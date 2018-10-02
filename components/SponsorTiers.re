open Util;

[@bs.module] external style: Js.t({..}) = "./sponsorTiers.module.scss";

let component = ReasonReact.statelessComponent("SponsorTiers");

[@genType]
let make = _children => {
  ...component,
  render: _ =>
    <section className=style##root>
      <div className="container">
        <h1 className="push--1col pull--1col"> {"Sponsor Tiers" |> s} </h1>
        Data.Tier.(
          sponsorTiers
          |> Belt.Array.reverse
          |> Array.map(tier => <SponsorTier tier key={tier.id} />)
          |> ReasonReact.array
        )
      </div>
    </section>,
};
