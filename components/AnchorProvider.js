import React from "react";
import PropTypes from "prop-types";
import { slugify } from "../utils";

class AnchorProvider extends React.Component {
  constructor() {
    super();

    this.ids = {}; // { id: index }. Example: { foo: 1 }
  }
  getChildContext() {
    const parent = this;

    return {
      getId: (anchor, children) => {
        let id = slugify(
          anchor || (Array.isArray(children) ? children : [children]).join()
        );

        // Check for duplicate id
        if (parent.ids[id]) {
          parent.ids[id]++;

          id += `-${parent.ids[id]}`;
        } else {
          parent.ids[id] = 1;
        }

        return id;
      }
    };
  }
  render() {
    return this.props.children;
  }
}
AnchorProvider.childContextTypes = {
  getId: PropTypes.func
};
AnchorProvider.propTypes = {
  children: PropTypes.node
};

export default AnchorProvider;
