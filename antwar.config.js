const path = require("path");
const pages = require("./data/content/pages");

module.exports = {
  apiUrl: "https://api.react-finland.fi/graphql-2018",
  template: {
    file: path.resolve(__dirname, "templates/page.ejs"),
    context: {
      helmet: {}
    }
  },
  renderPage: require("./utils/render-page"),
  output: "build",
  layout: () => require("./layouts/SiteBody").default,
  paths: {
    // "404.html": page("404", {
    //   description: "Page was not found",
    //   title: "Page not found",
    // }),
    "/": page("page_index.bs"),
    speakers: page("speakers.bs")
  }
};

function page(filename, meta = {}) {
  const name = path.basename(filename, ".bs");
  const ret = () => {
    const component = require(`./pages/${filename}`).default;
    const data = pages.find(({ id }) => id === name) || {};

    component.description = data.description || meta.description;
    component.title = data.title || meta.title;

    return component;
  };

  ret.name = name;

  return ret;
}
