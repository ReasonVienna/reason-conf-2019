%debugger.chrome
%raw
"require('../styles/style.scss')";

open Util;

module Helmet = ReactHelmetAsync.Helmet;
module HelmetProvider = ReactHelmetAsync.HelmetProvider;

let component = ReasonReact.statelessComponent("Layout");

let title = "ReasonConf 2018";

type layoutType =
  | Home
  | Normal
  | NoLayout
  | Print;

type helmetContext = Js.t({.});

type file = {
  title: string,
  description: string,
  keywords: array(string),
};

let subscribeFormIfNeeded = hasSubscribeForm =>
  componentOrNull(
    hasSubscribeForm,
    <footer className="subscribe">
      <div className="container_centered grid grid_6cols">
        <h2> {"Subscribe to Newsletter" |> s} </h2>
        <SubscribeForm />
      </div>
    </footer>,
  );

let make =
    (
      ~location: ReactRouter.location,
      ~file: file,
      ~router: ReactRouter.StaticRouter.t,
      children,
    ) => {
  ...component,
  render: _self => {
    let pageType =
      switch (location.pathname) {
      | "/" => Home
      | "/speaker"
      | "/speaker/" => NoLayout
      | "/badges"
      | "/badges/" => Print
      | _ => Normal
      };
    let isThanksPage = location.pathname == "/thanks/";
    let helmetContext = ReactRouter.StaticRouter.getHelmetContext(router);
    let {title, description, keywords} = file;
    <HelmetProvider context=helmetContext>
      <Meta siteName="ReasonConf" title description keywords />
      {
        switch (pageType) {
        | NoLayout => <div> <Helmet title /> children </div>
        | Print =>
          <div className="page-print">
            <Helmet title bodyAttributes={"class": "A4"}>
              <link
                rel="stylesheet"
                type_="text/css"
                href="https://cdnjs.cloudflare.com/ajax/libs/paper-css/0.3.0/paper.css"
              />
            </Helmet>
            children
          </div>
        | Home =>
          <div className="page">
            <main> children </main>
            {subscribeFormIfNeeded(!isThanksPage)}
            <Footer />
          </div>
        | Normal =>
          <div className="page">
            <div className="container container_centered">
              <header> <Navigation pathname={location.pathname} /> </header>
              <article> children </article>
            </div>
            {subscribeFormIfNeeded(!isThanksPage)}
            <Footer />
          </div>
        }
      }
    </HelmetProvider>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    jsProps => {
      let file = {
        title: jsProps##file##title,
        description: jsProps##file##description,
        keywords:
          switch (jsProps##file##keywords) {
          | Some(v) => v
          | None => [||]
          },
      };

      let location = ReactRouter.{pathname: jsProps##location##pathname};
      make(~location, ~file, ~router=jsProps##router, jsProps##children);
    },
  );
