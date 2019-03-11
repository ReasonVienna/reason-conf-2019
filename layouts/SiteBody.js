import React from "react";
import { hot } from "react-hot-loader";

import { HelmetProvider } from "react-helmet-async";

import Layout from "./layout.gen.js";

import "../styles/style.scss";

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
