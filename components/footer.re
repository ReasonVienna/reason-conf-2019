[@bs.module] external style: Js.t({..}) = "./footer.module.scss";

open Util;

module Link = ReactRouterDom.Link;

let component = ReasonReact.statelessComponent("Footer");

let socialUrls = [|
  "https://twitter.com/reasonconf",
  "https://www.facebook.com/ReasonConf-1334078980027448/",
  "https://www.github.com/reasonvienna",
|];

let organizerWithPic = ({imgUrl, name, href}: Data.Organizer.t) =>
  <a href className=style##creator key=name>
    <img src=imgUrl alt={j|Photo of $(name)|j} className=style##userpic />
    {name |> s}
  </a>;

let make = _children => {
  ...component,
  render: _self =>
    <footer className=style##root>
      <section className=style##wrapper>
        <div className=style##content>
          <Navigation navigationLocation=Footer />
          <nav className=style##additional>
            <ul>
              <li>
                <Link to_="/code-of-conduct/"> {"Code of Conduct" |> s} </Link>
              </li>
              <li> <Link to_="/privacy/"> {"Privacy Policy" |> s} </Link> </li>
              <li> <a href="/contact/"> {"Contact Us" |> s} </a> </li>
              <li> <Link to_="/imprint/"> {"Imprint" |> s} </Link> </li>
            </ul>
          </nav>
          <nav className=style##social>
            <SocialIcons
              urls=socialUrls
              color="#8eaeb6"
              className=style##socialIcon
            />
            <section className=style##copyright>
              {
                {j|
ReasonConf is a [not-for-profit conference](/about/) event by ReasonVienna and ReactVienna communities.

Design by [Andrey Okonetchnikov](http://okonet.ru)

© [ReasonConf](mailto:hi@reason-conf.com), 2018|j}
                |> md
              }
            </section>
          </nav>
        </div>
      </section>
    </footer>,
};
