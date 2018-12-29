module Link = ReactRouterDom.Link;

[@bs.module] external style: Js.t({..}) = "./navigation.module.scss";

open Util;

let component = ReasonReact.statelessComponent("Navigation");

type navigationLocation =
  | Header
  | Footer;

let make = (~pageType=Home, ~navigationLocation=Header, _children) => {
  ...component,
  render: _self => {
    let isHomePage = pageType == Home;
    let rootClassName =
      switch (navigationLocation) {
      | Header => style##root_header
      | Footer => style##root_footer
      };
    /* We don't need active class named in the footer */
    let activeClassName =
      navigationLocation == Header ? Some(style##link_active) : None;
    /* Use link style for tickets link in the footer */
    let ticketsClassName =
      navigationLocation == Header ? Some(style##ticketsButton) : None;
    <nav className=rootClassName>
      <ul className=style##list>
        <li className=style##listItem>
          <Link to_="/schedule/" className=style##link ?activeClassName>
            {s("Schedule")}
          </Link>
        </li>
        /* <li className=style##listItem>
             <Link to_="/speakers/" className=style##link ?activeClassName>
               {s("Speakers")}
             </Link>
           </li> */
        <li className=style##listItem>
          <Link to_="/attendees/" className=style##link ?activeClassName>
            {s("For Attendees")}
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/sponsors/" className=style##link ?activeClassName>
            {s("For Sponsors")}
          </Link>
        </li>
        /* <li className=style##listItem>
             <Link to_="/jobs/" className=style##link ?activeClassName>
               {s("Jobs")}
             </Link>
           </li> */
        <li className=style##listItem>
          <Link to_="/cfp/" className=style##link ?activeClassName>
            {s("Call for Papers")}
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/about/" className=style##link ?activeClassName>
            {s("About")}
          </Link>
        </li>
        <li className=style##listItemBuy>
          <a href="/#tickets" className=?ticketsClassName>
            {s("Buy a ticket")}
          </a>
        </li>
      </ul>
    </nav>;
  },
};
