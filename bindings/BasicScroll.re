type t;
[@bs.module "../vendor/basicscroll"]
external js_create:
  {
    .
    "elem": Dom.element,
    "from": string,
    "to": string,
    "props": Js.t({..}),
  } =>
  t =
  "create";
let maybeCreate = opts: option(t) =>
  switch ([%external window]) {
  | None => None
  | Some(_) => Some(js_create(opts))
  };
[@bs.send] external update: t => unit = "";
[@bs.send] external start: t => unit = "";
[@bs.send] external stop: t => unit = "";
