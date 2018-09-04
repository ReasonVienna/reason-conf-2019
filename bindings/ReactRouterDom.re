module Link = {
  [@bs.module "react-router-dom"]
  external linkClass: ReasonReact.reactClass = "Link";

  let make =
      (
        ~to_: string,
        ~className: option(string)=?,
        ~activeClassName: option(string)=?,
        children,
      ) => {
    /* So far we keep this for Link prop compatibility reasons */
    let _dontuse = activeClassName;
    let props = {"to": to_, "className": Js.Nullable.fromOption(className)};
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, children);
  };
};
