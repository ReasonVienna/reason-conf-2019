const page_index = {
  id: "page_index",
  title: "Home",
  description: "The ReasonML conference for web-developers & OCaml enthusiasts"
};

const speakers = {
  id: "speakers",
  title: "Speakers"
};

const schedule = {
  id: "schedule",
  title: "Schedule"
};

const attendees = {
  id: "attendees",
  title: "For Attendees"
};

const sponsors = {
  id: "sponsors",
  title: "For Sponsors"
};

const about = {
  id: "about",
  title: "About"
};

const imprint = {
  id: "imprint",
  title: "Imprint"
};

const contact = {
  id: "contact",
  title: "Contact"
};

const jobs = {
  id: "jobs",
  title: "Jobs"
};

const privacy = {
  id: "privacy",
  title: "Privacy"
};

const coc = {
  id: "coc",
  title: "Code of Conduct"
};

const viennaGuide = [
  {
    id: "vienna-guide/food",
    title: "Vienna Guide"
  },
  {
    id: "vienna-guide/coffee",
    title: "Vienna Guide"
  },
  {
    id: "vienna-guide/culture",
    title: "Vienna Guide"
  },
  {
    id: "vienna-guide/drinks-and-bars",
    title: "Vienna Guide"
  },
  {
    id: "vienna-guide/fun-and-outside",
    title: "Vienna Guide"
  }
];

module.exports = [
  page_index,
  speakers,
  schedule,
  attendees,
  sponsors,
  about,
  jobs,
  privacy,
  coc,
  imprint,
  contact,
  ...viennaGuide
];
