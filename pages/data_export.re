open Util;
let component = ReasonReact.statelessComponent(__MODULE__);

[@genType]
let make = _children => {
  ...component,
  render: _self =>
    <div style={ReactDOMRe.Style.make(~width="4rem", ~color="white", ())}>
      <h2> "Speakers"->s </h2>
      <pre> Exporter.speakersAsJSON()->s </pre>
      <h2> "Schedule"->s </h2>
      <pre> <pre> Exporter.scheduleAsJSON()->s </pre> </pre>
    </div>,
};
