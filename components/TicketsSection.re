[@bs.module] external style: Js.t({..}) = "./TicketsSection.module.scss";

open Util;

let component = ReasonReact.statelessComponent("TicketsSection");

let make = _children => {
  ...component,
  render: _ =>
    <section className="container">
      <div className="push--1col pull--1col">
        <h1> {"Tickets" |> s} </h1>
      </div>
      <Tito event="reason-conf/2019" />
    </section>,
};
