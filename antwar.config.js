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
    "/": page("index")
    // "2018": page("2018", {
    //   description: "React Finland 2018",
    //   title: "React Finland 2018",
    // }),
    // "for-attendees": page("for-attendees"),
    // "for-sponsors": page("for-sponsors"),
    // about: page("about"),
    // imprint: page("imprint"),
    // "privacy-policy": page("privacy-policy"),
    // "2018/schedule": page("schedule"),
    // "2018/speakers": page("speakers"),
    // "2018/workshops": page("workshops"),
  }
};

function page(name, meta) {
  const ret = () => {
    const pageComponent = require(`./pages/${name}`).default;
    const pageData = pages.find(({ id }) => id === name) || {};

    pageComponent.description = pageData.description || meta.description;
    pageComponent.title = pageData.title || meta.title;

    return pageComponent;
  };

  ret.name = name;

  return ret;
}
