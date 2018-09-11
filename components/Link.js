import React from "react";
import { Link as RRLink } from "react-router-dom";
import PropTypes from "prop-types";

const Link = ({ to, children, ...props }) =>
  /^https?:\/\//.test(to) ? (
    <a href={to} {...props}>
      {children}
    </a>
  ) : (
    <RRLink to={to} {...props}>
      {children}
    </RRLink>
  );
Link.propTypes = {
  to: PropTypes.string,
  children: PropTypes.node,
  props: PropTypes.object
};

export default Link;
