module Tickets = Tito.Tickets;
module Link = ReactRouterDom.Link;

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <Header />
      <div className="container_centered">
        <OfferingSection />
        <SpeakersSection />
        <PartnersSection />
      </div>
    </>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
