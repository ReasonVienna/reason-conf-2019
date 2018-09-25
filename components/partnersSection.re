module Link = ReactRouterDom.Link;

open Util;

[@bs.module] external style: Js.t({..}) = "./partnersSection.module.scss";

let component = ReasonReact.statelessComponent("PartnersSection");

let sponsorLogo = (sponsor: Partners.sponsorT) => {
  let className =
    switch (sponsor.tier) {
    | Gold => style##gold
    | Catering => style##catering
    | LocalSupport => style##local
    | Partner => style##partner
    };
  let title =
    switch (sponsor.tier) {
    | Gold => "Gold Sponsor"
    | Catering => "Food & Drinks"
    | LocalSupport => "Supporter"
    | Partner => "Partner"
    };
  <li className key={sponsor.name}>
    <figure className=style##figure>
      <a href={sponsor.href} title={sponsor.name} target="_blank">
        <img src={sponsor.logoUrl} alt={sponsor.name} className=style##logo />
      </a>
      <figcaption className=style##caption> {title |> s} </figcaption>
    </figure>
  </li>;
};

let make = _children => {
  ...component,
  render: _self =>
    <section className=style##root>
      <div className=style##intro>
        <h1> {"Sponsors & Partners" |> s} </h1>
        <p className="extraText">
          {"Do you want to help us make a better conference? " |> s}
          <Link to_="/sponsors"> {"Become a sponsor!" |> s} </Link>
        </p>
      </div>
      <ul className=style##partners>
        {Partners.sponsors |> Array.map(sponsorLogo) |> ReasonReact.array}
      </ul>
      <ul className=style##partners>
        {Partners.partners |> Array.map(sponsorLogo) |> ReasonReact.array}
      </ul>
    </section>,
};
