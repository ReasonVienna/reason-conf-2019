[@bs.module] external style: Js.t({..}) = "./button.module.scss";

let component = ReasonReact.statelessComponent("Button");

let s = ReasonReact.string;

let make =
    (~type_="button", ~onClick, ~className: option(string)=?, children) => {
  ...component,
  render: _self => {
    let classNames =
      (
        switch (className) {
        | Some(cn) => [|style##root, cn|]
        | None => [|style##root|]
        }
      )
      |> Util.join(~sep=" ");

    <button type_ className=classNames onClick> ...children </button>;
  },
};
