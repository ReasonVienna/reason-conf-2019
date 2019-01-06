let component = ReasonReact.statelessComponent(__MODULE__);

let make = _children => {
  ...component,
  didMount: _self => GoogleAnalytics.initTracking(),
  render: _self => ReasonReact.null,
};
