[@bs.module] external style: Js.t({..}) = "./logoRow.module.scss";

[@bs.module]
external reasonViennaLogo: string = "../assets/img/partners/reasonvienna.svg";

[@bs.module]
external reasonAssocLogo: string =
  "../assets/img/partners/reason-association-logo.svg";

[@bs.module]
external reactViennaLogo: string =
  "../assets/img/partners/reactvienna-logo.svg";

let component = ReasonReact.statelessComponent("LogoRow");

let logoWithLink = ({imgUrl, name, href}: Data.Organizer.logoT) =>
  <a href key=name> <img src=imgUrl alt=name /> </a>;

[@genType]
let make = (~logos: list(Data.Organizer.logoT), _children) => {
  ...component,
  render: _ => {
    Js.log(logos);
    <aside className=style##root>
      {
        switch (logos) {
        | [] => ReasonReact.null
        | logos =>
          Array.of_list(logos)
          |> Array.map(logoWithLink)
          |> ReasonReact.array
        }
      }
    </aside>;
  },
};
