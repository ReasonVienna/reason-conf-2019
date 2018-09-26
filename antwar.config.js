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
    speakers: page("speakers.bs"),
    schedule: page("schedule.bs"),
    attendees: page("attendees.bs"),
    sponsors: page("sponsors.bs"),
    jobs: page("jobs.bs"),
    about: page("about.bs"),
    privacy: page("privacy.bs"),
    imprint: page("imprint.mdx"),
    contact: page("contact.mdx"),
    "code-of-conduct": page("coc.bs"),
    "vienna-guide/food": page("vienna-guide/food.bs"),
    "vienna-guide/coffee": page("vienna-guide/coffee.bs"),
    "vienna-guide/culture": page("vienna-guide/culture.bs"),
    "vienna-guide/drinks-and-bars": page("vienna-guide/drinksAndBars.bs"),
    "vienna-guide/fun-and-outside": page("vienna-guide/funAndOutside.bs")
  }
};

function page(filepath, meta = {}) {
  const name = filepath.split(".")[0];
  const ret = () => {
    const component = require(`./pages/${filepath}`).default;
    const data = pages.find(({ id }) => id === name) || {};

    component.description = data.description || meta.description || "";
    component.title = data.title || meta.title || "";
    component.keywords = data.keywords || meta.keywords || [];

    return component;
  };

  ret.name = name;

  return ret;
}
