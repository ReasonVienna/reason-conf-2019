import React from "react";
import classnames from "classnames";
import PropTypes from "prop-types";
import Link from "./Link";

const NavigationRow = ({ links, pathname, className, ...props }) => (
  <ul {...props} className={classnames("nav--row", className)}>
    {links.map((link, i) => {
      const linkClassNames = classnames("nav--link", {
        "nav--link_selected": link.url && link.url === pathname
      });
      return (
        <li key={`link-${i}`} className={linkClassNames}>
          {link.url ? <Link to={link.url}>{link.title}</Link> : link.title}
        </li>
      );
    })}
  </ul>
);
NavigationRow.propTypes = {
  links: PropTypes.array,
  pathname: PropTypes.string,
  className: PropTypes.string,
  props: PropTypes.object
};

const Navigation = ({ pages, pathname }) => (
  <nav className="nav">
    {pages.map(({ links, props }, i) => (
      <NavigationRow key={i} links={links} pathname={pathname} {...props} />
    ))}
  </nav>
);
Navigation.propTypes = {
  pages: PropTypes.array,
  pathname: PropTypes.string
};

export default Navigation;
