module Link = ReactRouterDom.Link;

open Util;

[@bs.module] external style: Js.t({..}) = "./offeringSection.module.scss";

let component = ReasonReact.statelessComponent("OfferingSection");

let make = _children => {
  ...component,
  render: _self =>
    <section className=style##root>
      <h1 className="push--1col pull--1col">
        {"On the Road to Production" |> s}
      </h1>
      <p className="leadText">
        {
          {js|
              Last year, we have been eagerly onboarding newcomers to the language and we will continue to do so. This year, the conference is all about shipping products and tools built with Reason & OCaml.
              |js}
          |> s
        }
      </p>
      <ol className=style##timeline>
        <li className=style##day>
          <time dateTime="2018-04-11"> {"Day 1" |> s} </time>
          <section>
            <h2> {"Workshops & Knowledge Transfer" |> s} </h2>
            <p>
              {
                {js|
                The first day is dedicated to different workshops for different skill levels and topics. There are beginner friendly workshops about Reason and ReasonReact and also more advanced workshops about GraphQL and OCaml. Our workshop leaders are more experienced Reason / OCaml users and Reason core team members. Check the ticket section for details.
              |js}
                |> s
              }
            </p>
          </section>
          <img
            src=Assets.offerDay1
            alt="Workshops & Knowledge Transfer Photo"
          />
        </li>
        <li className=style##day2>
          <time dateTime="2018-04-12"> {"Day 2" |> s} </time>
          <section>
            <h2> {"Conference Day" |> s} </h2>
            <p>
              {
                {js|
                The conference day will be a single-stage setup with a variety of talks about Reason & OCaml related R&D, case studies and the community.
              |js}
                |> s
              }
            </p>
          </section>
          <img src=Assets.offerDay2 alt="Conference Day Photo" />
        </li>
        <li className=style##day>
          <time dateTime="2018-04-13"> {"Day 3" |> s} </time>
          <section>
            <h2> {"Open Stage & Reason Dojo Day" |> s} </h2>
            <p>
              {
                {js|
                The last day will be split in an Open Stage session with recorded lightning talks in the morning and a Reason Dojo with experienced Dojo Leaders in the afternoon.
                |js}
                |> s
              }
            </p>
          </section>
          <img src=Assets.offerDay3 alt="Open Mic & Reason Dojo Day Photo" />
        </li>
      </ol>
    </section>,
};
