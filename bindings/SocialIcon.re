[@bs.module "react-social-icons"]
external linkClass: ReasonReact.reactClass = "SocialIcon";
let make =
    (
      ~url: string,
      ~className: option(string)=?,
      ~color: option(string)=?,
      ~network: option(string)=?,
      _children,
    ) => {
  let props = {
    "url": url,
    "className": Js.Nullable.fromOption(className),
    "color": Js.Nullable.fromOption(color),
    "network": Js.Nullable.fromOption(network),
  };
  ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, _children);
};
