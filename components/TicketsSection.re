[@bs.module] external style: Js.t({..}) = "./TicketsSection.module.scss";

open Util;

let component = ReasonReact.statelessComponent("TicketsSection");

let make = _children => {
  ...component,
  render: _ =>
    <section className=style##root>
      <div className=style##inner>
        /*
         <div className="container">
           <div className="grid--4col push--1col">
             <h1 className=style##heading> {"Tickets" |> s} </h1>
           </div>
           <div className="grid--8col pull--1col">
             {
               "We're going to start selling tickets very soon. Please subscribe to the newsletter to get notified about the sale start."
               |> md
             }
             <SubscribeForm />
           </div>
         </div>*/

          <div className="push--1col pull--1col">
            <Tito event="reason-conf/2019" />
            <div>
              {
                "We offer free diversity tickets. Please apply here at [diversitytickets.org](https://diversitytickets.org/en/events/265/applications/new)."
                |> md
              }
            </div>
          </div>
        </div>
    </section>,
};
