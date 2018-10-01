module Link = ReactRouterDom.Link;

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <OfferingSection />
      /*<SpeakersSection />*/
      <TicketsSection />
      <PartnersSection />
      <ImpressionsSection />
    </>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
