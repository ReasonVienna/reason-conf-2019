const page_index = {
  id: "page_index",
  title: "Home",
  description: "Some description",
  intro: "Some intro",
  secondary: `foo`
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

const jobs = {
  id: "jobs",
  title: "Jobs"
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
  ...viennaGuide
];
