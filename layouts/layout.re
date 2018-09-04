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
      ~_location: ReactRouter.location,
      ~file: file,
      ~router: ReactRouter.StaticRouter.t,
      children,
    ) => {
  ...component,
  render: _self => {
    let helmetContext = ReactRouter.StaticRouter.getHelmetContext(router);
    let {title, description, keywords} = file;
    <HelmetProvider context=helmetContext>
      <Meta siteName="ReasonConf" title description keywords />
      <div className="page"> <main> children </main> <Footer /> </div>
    </HelmetProvider>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    jsProps => {
      let file = {
        title: jsProps##title,
        description: jsProps##description,
        keywords:
          switch (jsProps##keywords) {
          | Some(v) => v
          | None => [||]
          },
      };

      make(
        ~_location=jsProps##location,
        ~file,
        ~router=jsProps##router,
        jsProps##children,
      );
    },
  );
