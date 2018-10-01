let component = ReasonReact.statelessComponent("SponsorTiers");

[@genType]
let make = _children => {
  ...component,
  render: _ =>
    <section className="grid--full grid grid_12">
      Data.Tier.(
        sponsorTiers
        |> Array.map(tier => <SponsorTier tier key={tier.id} />)
        |> ReasonReact.array
      )
    </section>,
};
