module HelmetProvider = {
  /* We use a closed empty JS object type here, because we don't really care about the shape */
  type context = Js.t({.});

  [@bs.module "react-helmet-async"]
  external reactClass: ReasonReact.reactClass = "HelmetProvider";

  let make = (~context: context, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"context": context},
      children,
    );
};

module Helmet = {
  [@bs.module "react-helmet-async"]
  external helmetClass: ReasonReact.reactClass = "default";
  type metaT =
    option(
      array({
        .
        "name": string,
        "content": string,
      }),
    );

  let make =
      (~title: option(string)=?, ~bodyAttributes=?, ~meta: metaT=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=helmetClass,
      ~props={
        "title": Js.Nullable.fromOption(title),
        "bodyAttributes": Js.Nullable.fromOption(bodyAttributes),
        "meta": Js.Nullable.fromOption(meta),
      },
      children,
    );
};
