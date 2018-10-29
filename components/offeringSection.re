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
              Last year we have been eagerly onboarding newcomers to the language and we will continue to do so. This year, we designed the conference around shipping products & tools, built in Reason & OCaml.|js}
          |> s
        }
      </p>
      <p>
        <a href=Data.cfpLink target="_blank"> {"Apply as a Speaker" |> s} </a>
      </p>
      <ol className=style##timeline>
        <li className=style##day>
          <time dateTime="2018-04-11"> {"Day 1" |> s} </time>
          <section>
            <h2> {"Workshops & Knowledge Transfer" |> s} </h2>
            <p>
              {
                {js|
                We will offer different workshops, for all kinds of levels. There will be a beginner workshop for Reason newcomers and more practical workshops to get up to speed to build products more efficiently. Pick your favorite!
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
            <h2> {"Open Mic & Reason Dojo Day" |> s} </h2>
            <p>
              {
                {js|
                The last day will be split in a Open Microphone session in the noon and a reason-dojo in the afternoon. Take the chance to stand on stage and show the community what you are interested in and take part in a conference-wide reason dojo.
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
