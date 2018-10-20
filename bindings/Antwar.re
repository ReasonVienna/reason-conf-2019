/*
  This is an actual rewrite of the Interactive component (v0.21.0).
  Check out `node_modules/antwar-interactive/src/Interactive.jsx` for reference
 */

/*
   This will probably be subject of change when upgrading to newest Antwar versions.
   It would be better to use process.env.NODE_ENV instead.
 */

let isDEV: unit => bool = [%raw
  () => "{
    if(__DEV__) {
        return true;
    }
    return false;
}"
];

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

      let originalProps = Js.Option.getWithDefault(Js.Obj.empty(), props);

      /* In development mode, we want to render the container as a child of the wrapping div, as in:
             <div className={mergedClassName} {...remainingContainerProps}>
                {React.createElement(component, props)}
             </div>
         */
      if (isDEV()) {
        let mergedProps =
          Js.Obj.(
            empty()
            ->assign(originalProps)
            ->assign({"className": mergedClassName})
          );
        let container =
          ReasonReact.cloneElement(container, ~props=mergedProps, [||]);
        let wrapper =
          ReactDOMRe.createElementVariadic(
            "div",
            ~props=ReactDOMRe.objToDOMProps(mergedProps),
            [|container|],
          );
        wrapper;
      } else {
        /* In production, we don't want to render the container as a child element, as in:
              <div
                className={mergedClassName}
                id={id}
                {...remainingContainerProps}
                data-props={JSON.stringify(props)}
              />
           */
        let dataProps = originalProps |> shadyConversion |> stringify;
        let mergedProps =
          Js.Obj.(
            empty()
            ->assign(originalProps)
            ->assign({
                "className": mergedClassName,
                "id": id,
                "data-props": dataProps,
              })
          );
        ReactDOMRe.createElementVariadic(
          "div",
          ~props=ReactDOMRe.objToDOMProps(mergedProps),
          [||],
        );
      };
    },
  };
};
