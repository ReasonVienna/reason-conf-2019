open Util;

let component = ReasonReact.statelessComponent("Speakers");

let toSpeakerDetail = (speaker: Data.Speaker.t) =>
  <SpeakerDetails speaker key={speaker.name} />;

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> {"Speakers" |> s} </h1>
      <section>
        {
          Data.Speaker.speakers
          |> Array.map(toSpeakerDetail)
          |> ReasonReact.array
        }
      </section>
    </section>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
