import React from "react";
import { request } from "graphql-request";
import config from "config";

function connect(query) {
  return component => {
    let queryCache = {};

    class Connect extends React.Component {
      constructor(props) {
        super(props);

        this.state = { data: queryCache || {} };
      }
      componentDidMount() {
        this.fetchData().then(data => this.setState(() => data));
      }
      render() {
        return React.createElement(component, {
          ...this.props,
          ...this.state.data
        });
      }
      fetchData() {
        return request(config.apiUrl, query).then(data => {
          queryCache = data;

          return { data };
        });
      }
    }

    return Connect;
  };
}

export default connect;
