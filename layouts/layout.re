%raw
"require('../styles/style.scss')";

open Util;

module Helmet = ReactHelmetAsync.Helmet;
module HelmetProvider = ReactHelmetAsync.HelmetProvider;

let component = ReasonReact.statelessComponent("Layout");

let title = "ReasonConf 2018";

type helmetContext = Js.t({.});

type file = {
  title: string,
  description: string,
  keywords: array(string),
};

let subscribeFormIfNeeded = hasSubscribeForm =>
  componentOrNull(hasSubscribeForm, <SubscribeSection />);

let make = (~location: ReactRouter.location, ~file: file, children) => {
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

    let {title, description, keywords} = file;

    <>
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
          <main>
            <Header pageType />
            <article>
              children
              {subscribeFormIfNeeded(!isThanksPage)}
            </article>
            <Footer />
          </main>
        | Normal =>
          <main>
            <Header pageType />
            <article>
              <div className="container"> children </div>
              {subscribeFormIfNeeded(!isThanksPage)}
            </article>
            <Footer />
          </main>
        }
      }
    </>;
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
      make(~location, ~file, jsProps##children);
    },
  );

/* As long as we can't pass the router via props, instead of context, we can't use
   layout directly via antwar.config */

/*
 [@bs.val] external module_: Js.t({.}) = "module";
 let default = (ReactHotLoader.hot(module_))(. wrapped); */
