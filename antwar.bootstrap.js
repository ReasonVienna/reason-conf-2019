/* eslint-disable no-console */

const antwar = require("antwar");
const antwarConfig = require("./antwar.config.js");
const environment = process.argv[2];

antwar[environment]({
  environment,
  antwar: antwarConfig,
  webpack: require("./webpack.config")
})
  .then(() => {
    if (environment !== "build") {
      console.log("Surf to http://localhost:3000");
    }
  })
  .catch(err => {
    console.error(err);
    process.exit(1);
  });
