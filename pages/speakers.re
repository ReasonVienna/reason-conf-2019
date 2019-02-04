open Util;

let component = ReasonReact.statelessComponent("Speakers");

let toSpeakerDetail = (speaker: Data.Speaker.t) =>
  <SpeakerDetails speaker key={speaker.name} />;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> {"Speakers" |> s} </h1>
      <section className="container grid grid--full">
        {
          Data.Speaker.speakers
          |> Array.map(toSpeakerDetail)
          |> ReasonReact.array
        }
      </section>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
