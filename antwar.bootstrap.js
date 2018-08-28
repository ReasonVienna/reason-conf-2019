/* eslint-disable no-console */
// Needed for JSX compilation to work
require("@babel/register");

const antwar = require("antwar");
const request = require("request");
const antwarConfig = require("./antwar.config.js");
const environment = process.argv[2];

// Check that the API is up before starting
request
  .get(antwarConfig.apiUrl)
  .on("response", () => {
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
  })
  .on("error", function(err) {
    console.error(err);
  });
