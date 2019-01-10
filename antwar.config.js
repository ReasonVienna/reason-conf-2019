const path = require("path");
const pages = require("./data/content/pages");

module.exports = {
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
    // speakers: page("speakers.bs"),
    schedule: page("schedule.bs"),
    workshops: page("workshops.mdx"),
    attendees: page("attendees.mdx"),
    "attendees/accomodation": page("attendees/accomodation.mdx"),
    "attendees/activities": page("attendees/activities.mdx"),
    "attendees/food": page("attendees/food.mdx"),
    "attendees/internet": page("attendees/internet.mdx"),
    "attendees/transport": page("attendees/transport.mdx"),
    sponsors: page("sponsors.mdx"),
    about: page("about.mdx"),
    privacy: page("privacy.mdx"),
    imprint: page("imprint.mdx"),
    contact: page("contact.mdx"),
    cfp: page("cfp.mdx"),
    "code-of-conduct": page("coc.mdx"),
    "terms-of-service": page("terms_of_service.mdx")
  }
};

const defaultKeywords = [
  "Reason",
  "ReasonML",
  "Conference",
  "ReasonML",
  "Conf",
  "Vienna",
  "Austria"
];

function page(filepath, meta = {}) {
  const name = filepath.split(".")[0];
  const ret = () => {
    const component = require(`./pages/${filepath}`).default;
    const data = pages.find(({ id }) => id === name) || {};

    component.description = data.description || meta.description || "";
    component.title = data.title || meta.title || "";
    component.keywords = data.keywords || meta.keywords || defaultKeywords;

    return component;
  };

  ret.name = name;

  return ret;
}
