module Link = ReactRouterDom.Link;

open Util;

[@bs.module] external style: Js.t({..}) = "./header.module.scss";

let component = ReasonReact.statelessComponent("Header");

let logoEl =
  <img src=Assets.logo alt="ReasonConf 2019 Logo" className=style##logo />;

let make = (~pageType, _children) => {
  ...component,
  render: _self => {
    let isHomePage = pageType == Home;
    let navClassName =
      if (isHomePage) {
        style##nav_home;
      } else {
        style##nav;
      };

    <header className=style##root>
      <div className="container">
        {
          if (isHomePage) {
            logoEl;
          } else {
            <Link to_="/" className=style##link_home> logoEl </Link>;
          }
        }
        {
          componentOrNull(
            isHomePage,
            <div className=style##meta>
              <p className=style##description>
                <strong>
                  {
                    {j|The ReasonML conference for web developers & OCaml enthusiasts|j}
                    |> s
                  }
                </strong>
              </p>
              <h2 className=style##dates>
                <time dateTime="2019-04-11/2019-04-13">
                  {{j|11–13 April 2019|j} |> s}
                </time>
              </h2>
              <a
                className=style##location
                href="https://goo.gl/maps/AGAAyPGReTm"
                target="_blank">
                {"WU Campus, Vienna, Austria" |> s}
              </a>
            </div>,
          )
        }
        <section className=navClassName> <Navigation pageType /> </section>
      </div>
    </header>;
  },
};
