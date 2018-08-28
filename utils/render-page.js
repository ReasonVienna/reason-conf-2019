const React = require("react");
const ReactDOMServer = require("react-dom/server");
const { getDataFromTree } = require("react-apollo");
const { Route, StaticRouter } = require("react-router");

module.exports = function renderDefault({ location, content: component }, cb) {
  const helmetContext = {};
  const page = React.createElement(
    StaticRouter,
    { location, context: { helmetContext } },
    React.createElement(Route, { component })
  );

  getDataFromTree(page)
    .then(() =>
      cb(null, {
        html: ReactDOMServer.renderToStaticMarkup(page),
        context: { helmet: helmetContext.helmet }
      })
    )
    .catch(cb);
};
