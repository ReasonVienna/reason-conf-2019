[@bs.module] external style: Js.t({..}) = "./TicketsSection.module.scss";

open Util;

let component = ReasonReact.statelessComponent("TicketsSection");

let make = _children => {
  ...component,
  render: _ =>
    <section className=style##root>
      <h1> {"Tickets" |> s} </h1>
      <Tito event="reason-conf/2019" />
    </section>,
};
