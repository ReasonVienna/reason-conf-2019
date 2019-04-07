/* Used for exporting our Reason encoded data to JSON */

open Util;

[@bs.deriving abstract]
type img = {url: string};

/* Talk */
[@bs.deriving abstract]
type session = {
  [@bs.as "type"]
  type_: string,
  title: string,
  description: string,
  [@bs.optional]
  people: array(string),
};

/* Speaker */
[@bs.deriving abstract]
type contact = {
  name: string,
  about: string,
  company: string,
  image: img,
  talks: array(session),
};

[@bs.deriving abstract]
type interval = {
  [@bs.as "begin"]
  begin_: string,
  [@bs.as "end"]
  end_: string,
  title: string,
  sessions: array(session),
};

[@bs.deriving abstract]
type schedule = {
  day: string,
  description: string,
  intervals: array(interval),
};

[@bs.val] [@bs.return undefined_to_opt] [@bs.scope "JSON"]
external stringifyAnyPretty:
  ('a, [@bs.as {json|null|json}] _, [@bs.as {json|4|json}] _) =>
  option(string) =
  "stringify";

let convertSpeaker = (sp: Data.Speaker.t): contact => {
  let {Data.Speaker.name, talk, company, description, imgUrl} = sp;

  let people = [|name|];

  let talks =
    Belt.Option.(
      map(talk, t =>
        [|
          session(
            ~type_="TALK",
            ~title=t.title,
            ~description=t.abstract,
            ~people,
            (),
          ),
        |]
      )
      ->getWithDefault([||])
    );

  contact(
    ~name,
    ~company,
    ~talks,
    ~about=description,
    ~image=img(~url="https://www.reason-conf.com" ++ imgUrl),
  );
};

let convertTask = (task: Data.Timetable.task): array(session) =>
  switch (task) {
  | Talk(speakers) =>
    switch (List.hd(speakers).talk) {
    | Some(talk) =>
      let {Data.Speaker.title, abstract: description} = talk;
      let people = speakers->Belt.List.map(s => s.name)->Array.of_list;
      [|session(~type_="TALK", ~title, ~description, ~people, ())|];
    | None => [|session(~type_="TALK", ~title="TBA", ~description="", ())|]
    }

  | Break(title) => [|
      session(~type_="COFFEE_BREAK", ~title, ~description="", ()),
    |]
  | Workshop(workshops) =>
    workshops
    |> List.map((ws: Data.Workshop.t) =>
         session(~type_="WORKSHOP", ~title=ws.title, ~description="", ())
       )
    |> Array.of_list
  | OpenEnd(title) => [|
      session(~type_="OPEN_END", ~title, ~description="", ()),
    |]
  | PanelDiscussion => [|
      session(
        ~type_="PANEL_DISCUSSION",
        ~title="Panel Discussion",
        ~description="",
        (),
      ),
    |]
  | Misc(title) => [|session(~type_="MISC", ~title, ~description="", ())|]
  | _ => [|session(~type_="UNKNOWN", ~title="", ~description="", ())|]
  };

let convertEntryToInterval = (entry: Data.Timetable.entry): interval => {
  let sessions = convertTask(entry.task);

  let end_ =
    entry.toTime
    ->Belt.Option.map(dt => toHHMM(dt))
    ->Belt.Option.getWithDefault({j|∞|j});

  interval(~begin_=toHHMM(entry.fromTime), ~end_, ~title="", ~sessions);
};

let pickEntries = (day: Data.Timetable.day): list(Data.Timetable.entry) =>
  day.entries;

/* Converted values */
let speakers = Array.map(convertSpeaker, Data.Speaker.speakers);

let createSchedule =
    (~day: Js.Date.t, ~description: string, intervals: array(interval)) =>
  schedule(~day=toYYYYMMDD(day), ~description, ~intervals);

let day1Schedule =
  Belt.List.getExn(Data.Timetable.days, 0)
  ->pickEntries
  ->Belt.List.map(convertEntryToInterval)
  ->Array.of_list
  |> createSchedule(
       ~day=Data.Timetable.startDate,
       ~description="Workshop Day",
     );

let day2Schedule =
  Belt.List.getExn(Data.Timetable.days, 1)
  ->pickEntries
  ->Belt.List.map(convertEntryToInterval)
  ->Array.of_list
  ->createSchedule(~day=Data.Timetable.day2, ~description="Conference Day");

let day3Schedule =
  Belt.List.getExn(Data.Timetable.days, 2)
  ->pickEntries
  ->Belt.List.map(convertEntryToInterval)
  ->Array.of_list
  ->createSchedule(
      ~day=Data.Timetable.day3,
      ~description="Community & Dojo Day",
    );

let schedules = [|day1Schedule, day2Schedule, day3Schedule|];

let speakersAsJSON = (): string =>
  stringifyAnyPretty(speakers)->Belt.Option.getWithDefault("");

let scheduleAsJSON = (): string =>
  stringifyAnyPretty(schedules)->Belt.Option.getWithDefault("");
