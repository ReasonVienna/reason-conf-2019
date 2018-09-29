let component = ReasonReact.statelessComponent("SponsorTiers");

[@genType]
let make = _children => {
  ...component,
  render: _ =>
    <div className="full sponsor-tiers">
      Data.Tier.(
        sponsorTiers
        |> Array.map(tier => <SponsorTier tier key={tier.id} />)
        |> ReasonReact.array
      )
    </div>,
};
