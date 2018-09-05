const index = {
  id: "index",
  title: "Reason Conf",
  description: "Some description",
  intro: "Some intro",
  secondary: `foo`
};

const page_index = {
  ...index,
  id: "page_index"
};

const speakers = {
  id: "speakers",
  title: "Speakers"
};

module.exports = [index, page_index, speakers];
