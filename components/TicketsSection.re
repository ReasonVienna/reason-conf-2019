[@bs.module] external style: Js.t({..}) = "./TicketsSection.module.scss";

open Util;

let component = ReasonReact.statelessComponent("TicketsSection");

let make = _children => {
  ...component,
  render: _ =>
    <section className=style##root>
      <div className=style##inner>
        <div className="container">
          <div className="push--1col pull--1col">
            <h1 className=style##heading> {"Tickets" |> s} </h1>
            <Tito event="reason-conf/2019" />
          </div>
        </div>
      </div>
    </section>,
};
