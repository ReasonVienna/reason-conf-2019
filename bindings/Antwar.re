/*
  This is an actual rewrite of the Interactive component (v0.21.0).
  Check out `node_modules/antwar-interactive/src/Interactive.jsx` for reference
 */
module Interactive = {
  let component = ReasonReact.statelessComponent("Interactive");
  let stringify: Js.t({.}) => string = [%raw
    obj => "return JSON.stringify(obj);"
  ];

  /* We need this for stringifying the props */
  external shadyConversion: 'a => Js.t({.}) = "%identity";

  let make =
      (
        ~id: string,
        ~className: option(string)=?,
        ~container: ReasonReact.reactElement,
        ~props: option(Js.t({..}))=?,
        _children,
      ) => {
    ...component,
    render: _ => {
      let mergedClassName =
        switch (className) {
        | None
        | Some("") => "interactive"
        | Some(cn) => "interactive " ++ cn
        };

      /* If there are props, we need to clone and spread the props to the new element,
         otherwise we can just use the original reactElement */
      let (props, clonedContainer) =
        switch (props) {
        | Some(p) =>
          let cloned = ReasonReact.cloneElement(container, ~props=p, [||]);
          (p, cloned);
        | None => (Js.Obj.empty(), container)
        };

      let merged =
        Js.Obj.(
          empty()
          ->assign({
              "id": id,
              "className": mergedClassName,
              "data-props": props |> shadyConversion |> stringify,
            })
        );

      ReactDOMRe.createElementVariadic(
        "div",
        ~props=ReactDOMRe.objToDOMProps(merged),
        [|clonedContainer|],
      );
    },
  };
};
