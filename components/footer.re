[@bs.module] external style: Js.t({..}) = "./footer.module.scss";

open Util;

module Link = ReactRouterDom.Link;

let component = ReasonReact.statelessComponent("Footer");

let socialUrls = [|
  "https://twitter.com/reasonconf",
  "https://www.facebook.com/ReasonConf-1334078980027448/",
  "https://www.github.com/reasonvienna",
  "https://www.youtube.com/c/ReasonConf",
|];

let socialIcon = (~key: string, ~url: string) =>
  <SocialIcon url key color="#8eaeb6" className=style##socialIcon />;
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
        <Navigation navigationLocation=Footer />
        <nav className=style##additional>
          <ul>
            <li>
              <a href=Data.discordLink target="_blank">
                {"Discord Chatroom" |> s}
              </a>
            </li>
            <li>
              <Link to_="/code-of-conduct/"> {"Code of Conduct" |> s} </Link>
            </li>
            <li>
              <Link to_="/terms-of-service/"> {"Terms of Service" |> s} </Link>
            </li>
            <li> <Link to_="/privacy/"> {"Privacy Policy" |> s} </Link> </li>
            <li> <Link to_="/contact/"> {"Contact Us" |> s} </Link> </li>
            <li> <Link to_="/imprint/"> {"Imprint" |> s} </Link> </li>
            <li>
              <a
                href="https://2018.reason-conf.com"
                title="ReasonConf 2018 Website">
                {s("ReasonConf 2018")}
              </a>
            </li>
          </ul>
        </nav>
        <nav className=style##social>
          {
            socialUrls
            |> Array.mapi((i, url) =>
                 socialIcon(~key=string_of_int(i), ~url)
               )
            |> ReasonReact.array
          }
        </nav>
        <section className=style##copyright>
          {
            {j|
ReasonConf is a [not-for-profit conference](/about/) event by the [Reason Association](https://www.reason-association.org/) and the [ReactVienna](https://www.meetup.com/reactvienna/) community.

Design by [Andrey Okonetchnikov](http://okonet.ru)

© [ReasonConf](mailto:hi@reason-conf.com), 2019|j}
            |> md
          }
        </section>
      </section>
    </footer>,
};
