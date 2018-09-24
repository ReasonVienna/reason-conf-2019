module Link = ReactRouterDom.Link;

open Util;

[@bs.module] external style: Js.t({..}) = "./offeringSection.module.scss";

let component = ReasonReact.statelessComponent("OfferingSection");

let make = _children => {
  ...component,
  render: _self =>
    <section className=style##root>
      <section className=style##descriptions>
        <h2> {"On the Road to Production" |> s} </h2>
        <p>
          {
            {js|
                      Last year we have been eagerly onboarding newcomers to the language and we will continue to do so! This year, we designed a conference which is build around shipping products & tools, built in Reason & OCaml.
                    |js}
            |> s
          }
        </p>
      </section>
      <dl className=style##timeline>
        <dt className=style##day>
          <time dateTime="2018-04-11"> {"Day 1" |> s} </time>
        </dt>
        <dd className=style##dayDescription>
          <h3> {"Workshops & Knowledge Transfer" |> s} </h3>
          <p>
            {
              {js|
                        We will offer different workshops, for all kinds of levels.
                        There will be a beginner workshop for Reason newcomers and more practical workshops to get up to speed to build products more efficiently. Pick your favorite!

                      |js}
              |> s
            }
          </p>
        </dd>
        <dt className=style##day>
          <time dateTime="2018-04-12"> {"Day 2" |> s} </time>
        </dt>
        <dd className=style##dayDescription>
          <h3> {"Conference Day" |> s} </h3>
          <p>
            {
              {js|
                        The conference day will be a single-stage setup with a variety of talks about Reason & OCaml related R&D, case studies and the community.
                      |js}
              |> s
            }
          </p>
        </dd>
        <dt className=style##day>
          <time dateTime="2018-04-13"> {"Day 3" |> s} </time>
        </dt>
        <dd className=style##dayDescription>
          <h3> {"Open Mic & Reason Dojo Day" |> s} </h3>
          <p>
            {
              {js|
                        The last day will be split in a Open Microphone session in the noon and a reason-dojo in the afternoon. Take the chance to stand on stage and show the community what you are interested in and take part in a conference-wide reason dojo.
                      |js}
              |> s
            }
          </p>
        </dd>
      </dl>
    </section>,
};
