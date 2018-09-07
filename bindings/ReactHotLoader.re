[@bs.module "react-hot-loader"]
external hot:
  Js.t({..}) => (. ReasonReact.reactClass) => ReasonReact.reactClass =
  "hot";
