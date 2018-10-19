%raw
"require('../styles/style.scss')";

open Util;

module Interactive = Antwar.Interactive;
module Helmet = ReactHelmetAsync.Helmet;
module HelmetProvider = ReactHelmetAsync.HelmetProvider;

let component = ReasonReact.statelessComponent("Layout");

let title = "ReasonConf 2018";

[@genType]
type file = {
  title: string,
  description: string,
  keywords: array(string),
};

[@genType]
type location = {pathname: string};

[@genType]
let make = (~location: location, ~file: file, children) => {
  ...component,
  render: _self => {
    let pageType =
      switch (location.pathname) {
      | "/" => Home
      | "/sponsors"
      | "/sponsors/" => Sponsors
      | "/speaker"
      | "/speaker/" => NoLayout
      | "/badges"
      | "/badges/" => Print
      | _ => Normal
      };

    let {title, description, keywords} = file;

    <>
      <Antwar.Interactive
        container={<CookieBox />}
        id="./components/CookieBox.re.js"
      />
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
        | _ =>
          <main>
            <Header pageType />
            <article>
              {
                if (pageType == Home || pageType == Sponsors) {
                  children;
                } else {
                  <div className="page-content"> children </div>;
                }
              }
              <SubscribeSection />
            </article>
            <Footer />
          </main>
        }
      }
    </>;
  },
};

/* As long as we can't pass the router via props, instead of context, we can't use
   layout directly via antwar.config */

/*
 [@bs.val] external module_: Js.t({.}) = "module";
 let default = (ReactHotLoader.hot(module_))(. wrapped); */
