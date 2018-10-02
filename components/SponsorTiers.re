[@bs.module] external style: Js.t({..}) = "./sponsorTiers.module.scss";

open Util;

let component = ReasonReact.statelessComponent("SponsorTiers");

let renderTier = (~tier: Data.Tier.t, ~key: string) => {
  let className =
    switch (tier.id) {
    | "gold" => style##gold
    | "catering" => style##catering
    | "supporter" => style##supporter
    | _ => style##root
    };
  let href = "mailto:hi@reason-conf.com?subject=Sponsoring: " ++ tier.name;
  <a href className key>
    <header className=style##header>
      <h3 className=style##name> {tier.name |> s} </h3>
      <div className=style##amount>
        <h4 className=style##cost> {tier.cost |> string_of_int |> s} </h4>
        {{js|€|js} |> s}
      </div>
    </header>
    <ul className=style##description>
      {
        tier.offer
        |> Array.mapi((i, text) =>
             <li key={string_of_int(i)}> {text |> s} </li>
           )
        |> ReasonReact.array
      }
    </ul>
  </a>;
};

[@genType]
let make = _children => {
  ...component,
  render: _ =>
    <section className=style##root>
      Data.Tier.(
        sponsorTiers
        |> Array.map(tier => renderTier(~tier, ~key=tier.id))
        |> ReasonReact.array
      )
    </section>,
};
