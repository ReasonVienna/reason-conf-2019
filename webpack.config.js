const path = require("path");
const webpack = require("webpack");
const ExtractTextPlugin = require("extract-text-webpack-plugin");
const RedirectWebpackPlugin = require("redirect-webpack-plugin");
const merge = require("webpack-merge");

module.exports = env => {
  switch (env) {
    case "build":
      return merge(commonConfig(), buildConfig());
    // case "interactive":
    //   return merge(commonConfig(), interactiveConfig());
    case "start":
    default:
      return merge(commonConfig(), developmentConfig());
  }
};

function commonConfig() {
  return {
    stats: "minimal",
    module: {
      rules: [
        {
          test: /(\.bs\.)?\.js$/,
          use: "babel-loader",
          include: [
            path.join(__dirname, "components"),
            path.join(__dirname, "layouts"),
            path.join(__dirname, "pages"),
            path.join(__dirname, "data")
          ]
        },
        {
          test: /\.woff(2)?|\.ttf$|\.eot$/,
          use: [
            {
              loader: "url-loader",
              options: {
                limit: 5000
              }
            }
          ]
        },
        {
          test: /\.gif$/,
          use: "file-loader"
        },
        {
          test: /\.jpg$/,
          use: "file-loader"
        },
        {
          test: /\.png$/,
          use: "file-loader"
        },
        {
          test: /\.svg$/,
          use: "file-loader"
        },
        {
          test: /\.txt$/,
          use: "raw-loader"
        },
        {
          test: /.mdx?$/,
          use: ["babel-loader", "@mdx-js/loader"]
        },
        {
          test: /\.md$/,
          use: "raw-loader"
        },
        {
          // Prevent webpack from interpreting Reason files
          test: /.re$/,
          loader: "./scripts/ignore-loader"
        }
      ]
    },
    resolve: {
      alias: {
        assets: path.resolve(__dirname, "assets"),
        config: path.resolve(__dirname, "antwar.config.js"), // XXX: styleguidist
        components: path.resolve(__dirname, "components"),
        utils: path.resolve(__dirname, "utils")
      }
    }
  };
}

// function interactiveConfig() {
//   return {
//     resolve: {
//       alias: {
//         react: "preact-compat/dist/preact-compat.min.js",
//         "react-dom": "preact-compat/dist/preact-compat.min.js",
//       },
//     },
//     plugins: [
//       new webpack.optimize.UglifyJsPlugin({
//         compress: {
//           warnings: false,
//         },
//       }),
//     ],
//   };
// }

function developmentConfig() {
  return {
    module: {
      rules: [
        {
          test: /\.s?css$/,
          // TODO: Refactor this extra scss loader config, after migrating to CSS-Modules only
          include: [path.resolve(__dirname, "styles")],
          use: ["style-loader", "css-loader", "postcss-loader", "sass-loader"]
        },
        {
          test: /\.s?css$/,
          exclude: [path.resolve(__dirname, "styles")],
          use: [
            "style-loader",
            {
              loader: "css-loader",
              options: {
                importLoaders: 2,
                modules: true,
                localIdentName: "[name]__[local]___[hash:base64:5]"
              }
            },
            "postcss-loader",
            "sass-loader"
          ]
        }
      ]
    }
  };
}

function buildConfig() {
  return {
    module: {
      rules: [
        {
          test: /\.s?css$/,
          // TODO: Refactor this extra scss loader config, after migrating to CSS-Modules only
          include: [path.resolve(__dirname, "styles")],
          use: ExtractTextPlugin.extract({
            use: ["css-loader", "postcss-loader", "sass-loader"],
            fallback: "style-loader"
          })
        },
        {
          test: /\.s?css$/,
          exclude: [path.resolve(__dirname, "styles")],
          use: ExtractTextPlugin.extract({
            use: [
              {
                loader: "css-loader",
                options: {
                  importLoaders: 2,
                  modules: true,
                  localIdentName: "[name]__[local]___[hash:base64:5]"
                }
              },
              "postcss-loader",
              "sass-loader"
            ],
            fallback: "style-loader"
          })
        }
      ]
    },
    plugins: [
      new ExtractTextPlugin({
        filename: "[name].[chunkhash].css",
        allChunks: true
      }),
      new webpack.DefinePlugin({
        window: `false`
      })
      // new RedirectWebpackPlugin({
      //   redirects: {
      //     organizers: "/about/",
      //     presentations: "/speakers/",
      //     talks: "/speakers/",
      //     schedule: "/2018/schedule/",
      //     speakers: "/2018/speakers/",
      //     workshops: "/2018/workshops/"
      //   }
      // })
    ]
  };
}
