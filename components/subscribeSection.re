[@bs.module] external style: Js.t({..}) = "./subscribeSection.module.scss";

open Util;

let component = ReasonReact.statelessComponent("SubscribeSection");

type navigationLocation =
  | Header
  | Footer;

let make = _children => {
  ...component,
  render: _self =>
    <section className=style##root>
      <div className=style##inner>
        <div className="container">
          <h1 className=style##heading> {"Subscribe to Newsletter" |> s} </h1>
          <SubscribeForm />
        </div>
      </div>
    </section>,
};
