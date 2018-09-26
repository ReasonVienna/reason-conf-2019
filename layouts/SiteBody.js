import React from "react";
import { hot } from "react-hot-loader";
import PropTypes from "prop-types";
import { connect } from "../components";

import Helmet, { HelmetProvider } from "react-helmet-async";

import Layout from "./layout.re.js";

import "../styles/style.scss";

function Meta({
  siteName = "test",
  title = "test",
  description = "test",
  keywords = []
}) {
  return (
    <Helmet>
      <link rel="canonical" href="https://react-finland.fi/" />
      <link rel="icon" type="image/png" href="/favicon.png" />

      <title>test</title>
      <meta property="og:site_name" content={siteName} />
      <meta charSet="UTF-8" />
      <meta
        name="viewport"
        content="width=device-width, initial-scale=1, maximum-scale=1, minimal-ui"
      />
      <meta name="description" content={description} />
      <meta name="keywords" content={keywords.join(", ")} />

      <meta property="og:title" content={title} />
      <meta property="og:description" content={description} />
      <meta property="og:image" content="/meta-image.png" />
      <meta name="twitter:title" content={title} />
      <meta name="twitter:description" content={description} />
      <meta name="twitter:site" content="@ReactFinland" />
      <meta name="twitter:image" content="./meta-image.png" />
    </Helmet>
  );
}

const SiteBody = ({ children, location, page: { file } }, ctx) => {
  /*
  ReasonReact doesn't support the stateless function 
  context parameter, like used here... therefore we will
  keep the SiteBody as a shim for the ReasonReact app
  
  This is probably the only impediment why we can't migrate to full ReasonReact
  */
  const { router } = ctx;

  return (
    <HelmetProvider
      context={
        router && router.staticContext && router.staticContext.helmetContext
      }
    >
      <Layout location={location} file={file} router={router}>
        {/* <Meta /> */}
        {children}
      </Layout>
    </HelmetProvider>
  );
};

export default hot(module)(SiteBody);
