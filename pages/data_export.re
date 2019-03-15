open Util;
let component = ReasonReact.statelessComponent(__MODULE__);

[@genType]
let make = _children => {
  ...component,
  render: _self => {
    let speakerJSON = Exporter.speakersAsJSON();
    let scheduleJSON = Exporter.scheduleAsJSON();
    <div style={ReactDOMRe.Style.make(~width="4rem", ~color="white", ())}>
      <h2> "Speakers"->s </h2>
      <pre> speakerJSON->s </pre>
      <h2> "Schedule"->s </h2>
      <pre> <pre> scheduleJSON->s </pre> </pre>
    </div>;
  },
};
