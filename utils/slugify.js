const slugify = idBase =>
  idBase
    .toLowerCase()
    .replace(/`/g, "")
    .replace(/[^\w]+/g, "-");

export default slugify;
