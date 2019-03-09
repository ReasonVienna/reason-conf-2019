open Util;

module Link = ReactRouterDom.Link;

[@bs.module] external style: Js.t({..}) = "./schedule.module.scss";

let talkSlug = Data.Speaker.talkSlug;

let component = ReasonReact.statelessComponent("Schedule");

let toTimeStr = (~fromTime, ~toTime) =>
  switch (toTime) {
  | Some(toTime) => toHHMM(fromTime) ++ {j|–|j} ++ toHHMM(toTime)
  | None => toHHMM(fromTime) ++ {j|–∞|j}
  };

let toDayStr = (~date) => {
  let format = "YYYY-MM-DDTHH:mm:ss.SSSZ";
  DateFns.format(format, date);
};

let toDurationStr = (~fromTime, ~toTime) => {
  let format = "YYYY-MM-DDTHH:mm:ss.SSSZ";
  switch (toTime) {
  | Some(toTime) =>
    DateFns.format(format, fromTime) ++ "/" ++ DateFns.format(format, toTime)
  | None => DateFns.format(format, fromTime)
  };
};

let miscRow = (~fromTime, ~toTime, description) =>
  ReasonReact.array([|
    <dt className=style##entryTime>
      <time dateTime={toDurationStr(~fromTime, ~toTime)}>
        {toTimeStr(~fromTime, ~toTime) |> s}
      </time>
    </dt>,
    <dd className=style##entryDescription> {description |> s} </dd>,
  |]);

let talkRow = (~fromTime, ~toTime, speakers: list(Data.Speaker.t)) => {
  let renderSpeaker = speaker =>
    <li className=style##speaker>
      <Link to_={"/speakers/#" ++ Data.Speaker.speakerAnchor(speaker)}>
        <SpeakerCard speaker compact=true />
      </Link>
    </li>;
  ReasonReact.array([|
    <dt className=style##talkTime>
      <time dateTime={toDurationStr(~fromTime, ~toTime)}>
        {toTimeStr(~fromTime, ~toTime) |> s}
      </time>
    </dt>,
    <dd className=style##talkDescription>
      {
        switch (List.hd(speakers).talk) {
        | Some(talk) =>
          let id = Data.Speaker.talkSlug(talk);
          <>
            <h3 className=style##talkTitle id>
              {talk.title |> s}
              {" " |> s}
              <a href={"#" ++ id} title={talk.title}> {"#" |> s} </a>
            </h3>
            <ul className=style##speakers>
              {
                speakers
                |> List.map(renderSpeaker)
                |> Array.of_list
                |> ReasonReact.array
              }
            </ul>
            {talk.abstract |> md}
          </>;
        | None => ReasonReact.null
        }
      }
    </dd>,
  |]);
};

let workshopRow = (~fromTime, ~toTime) =>
  ReasonReact.array([|
    <dt className=style##talkTime>
      <time dateTime={toDurationStr(~fromTime, ~toTime)}>
        {toTimeStr(~fromTime, ~toTime) |> s}
      </time>
    </dt>,
    <dd className=style##talkDescription>
      <Link to_="/workshops">
        <h3 className=style##talkTitleLink> {"Workshops" |> s} </h3>
      </Link>
    </dd>,
  |]);

let panelDiscussionRow = (~fromTime, ~toTime) =>
  ReasonReact.array([|
    <dt className=style##talkTime>
      <time dateTime={toDurationStr(~fromTime, ~toTime)}>
        {toTimeStr(~fromTime, ~toTime) |> s}
      </time>
    </dt>,
    <dd className=style##talkDescription>
      <section className=style##talkDetails>
        <h3 className=style##talkTitle> {"Panel Discussion" |> s} </h3>
      </section>
    </dd>,
  |]);

let openEndRow = (~fromTime, ~toTime, description) =>
  ReasonReact.array([|
    <dt className=style##entryTime>
      <time dateTime={toDurationStr(~fromTime, ~toTime=None)}>
        {toTimeStr(~fromTime, ~toTime) |> s}
      </time>
    </dt>,
    <dd className=style##entryDescription> {description |> s} </dd>,
  |]);

let createRow = ({task, fromTime, toTime}: Data.Timetable.entry) =>
  switch (task) {
  | Break(description) => miscRow(~fromTime, ~toTime, description)
  | Misc(description) => miscRow(~fromTime, ~toTime, description)
  | OpenEnd(description) => miscRow(~fromTime, ~toTime, description)
  | Talk(speakers) => talkRow(~fromTime, ~toTime, speakers)
  | Workshop(speakers) => workshopRow(~fromTime, ~toTime)
  | PanelDiscussion => panelDiscussionRow(~fromTime, ~toTime)
  };

let createDay = ({date, entries}: Data.Timetable.day) => {
  let id = DateFns.format("DD-MM-YY", date);
  <>
    <h2 id className="headingWithAnchor">
      <time dateTime={DateFns.format("YYYY-MM-DDTHH:mm:ss.SSSZ", date)}>
        {DateFns.format("Do MMMM, dddd", date) |> s}
      </time>
      <a href={"#" ++ id}> {"#" |> s} </a>
    </h2>
    <dl className=style##entries>
      {entries |> List.map(createRow) |> Array.of_list |> ReasonReact.array}
    </dl>
  </>;
};

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> {"Schedule" |> s} </h1>
      {
        Data.Timetable.days
        |> List.map(createDay)
        |> Array.of_list
        |> ReasonReact.array
      }
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
