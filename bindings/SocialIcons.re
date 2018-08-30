[@bs.module "react-social-icons"]
external linkClass: ReasonReact.reactClass = "default";
let make =
    (
      ~urls: array(string),
      ~className: option(string)=?,
      ~color: option(string)=?,
      _children,
    ) => {
  let props = {
    "urls": urls,
    "className": Js.Nullable.fromOption(className),
    "color": Js.Nullable.fromOption(color),
  };
  ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, _children);
};
