open Util;

open Data;

[@bs.module] external style : Js.t({..}) = "./speakerDetails.module.scss";

let component = ReasonReact.statelessComponent("SpeakerDetails");

let make = (~speaker: Data.speakerData, _children) => {
  ...component,
  render: _self =>
    <div className=style##root key=speaker.name>
      <img src=speaker.imgUrl />
      <div>
        <h3> (speaker.name |> s) </h3>
        <p> (speaker.description |> s) </p>
        (
          switch speaker.talk {
          | Some(t) => <p> ("Talk: " |> s) <a href=""> (t.title |> s) </a> </p>
          | None => ReasonReact.nullElement
          }
        )
      </div>
    </div>
};
