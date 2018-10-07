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
          <div className="grid--4col">
            <h1 className=style##heading>
              {"Subscribe to Newsletter" |> s}
            </h1>
          </div>
          <div className="grid--8col">
            {"Get ReasonConf news straight to your inbox" |> md}
            <SubscribeForm />
          </div>
        </div>
      </div>
    </section>,
};
