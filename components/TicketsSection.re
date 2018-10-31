[@bs.module] external style: Js.t({..}) = "./TicketsSection.module.scss";

open Util;

let component = ReasonReact.statelessComponent("TicketsSection");

let make = _children => {
  ...component,
  render: _ =>
    <section className=style##root>
      <div className=style##inner>
        <div className="container">
          <div className="grid--4col push--1col">
            <h1 className=style##heading> {"Tickets" |> s} </h1>
          </div>
          <div className="grid--7col pull--1col">
            {
              "We offer free tickets for underrepresented groups. [Apply for a free ticket](https://diversitytickets.org/en/events/265/applications/new)."
              |> md
            }
          </div>
          <div className="grid--12col">
            <Tito event="reason-conf/2019" />
          </div>
        </div>
      </div>
    </section>,
};
