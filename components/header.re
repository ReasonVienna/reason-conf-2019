module Link = ReactRouterDom.Link;

open Util;

[@bs.module] external style: Js.t({..}) = "./header.module.scss";

let component = ReasonReact.statelessComponent("Header");

let make = _children => {
  ...component,
  render: _self =>
    <header className=style##root>
      <h1 className=style##logo>
        <img src=Assets.logo alt="ReasonConf 2019" className="teaser--image" />
      </h1>
      <div className=style##meta>
        <p className=style##description>
          <strong>
            {
              {j|The official ReasonML conference for web developers & OCaml enthusiasts|j}
              |> s
            }
          </strong>
        </p>
        <h2 className=style##dates>
          <time dateTime="2019-04-11/2019-04-13">
            {{j|11–13 April 2019|j} |> s}
          </time>
        </h2>
        <p className=style##location> {"Vienna, Austria" |> s} </p>
      </div>
      <section className=style##nav> <Navigation pathname="/" /> </section>
    </header>,
};
