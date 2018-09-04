import React from "react";
import { hot } from "react-hot-loader";
import PropTypes from "prop-types";
import { HelmetProvider } from "react-helmet-async";
import { Footer, Meta, connect } from "../components";

import Layout from "./Layout.bs";

// import "normalize.css/normalize.css";
// import "../styles/fontello-codes.css";
// import "../styles/fontello-embedded.css";
import "../styles/style.scss";

const siteName = "ReasonConf";

const SiteBody = (
  {
    children,
    location,
    page: { file },
    partners = [],
    goldSponsors = [],
    silverSponsors = [],
    bronzeSponsors = []
  },
  { router }
) => {
  /*
  ReasonReact doesn't support the stateless function 
  context parameter, like used here... therefore we will
  keep the SiteBody as a shim for the ReasonReact app
  */

  return (
    <Layout location={location} file={file} router={router}>
      {children}
    </Layout>
  );
  // return <HelmetProvider
  //   context={
  //     router && router.staticContext && router.staticContext.helmetContext
  //   }
  // >
  //   <Meta
  //     siteName={siteName}
  //     title={title}
  //     description={description}
  //     keywords={keywords}
  //   />
  //   <div className="page">
  //     <main>{children}</main>
  //     <Footer />
  //   </div>
  // </HelmetProvider>
};

SiteBody.propTypes = {
  children: PropTypes.node,
  location: PropTypes.object,
  page: PropTypes.object,
  partners: PropTypes.array,
  goldSponsors: PropTypes.array,
  silverSponsors: PropTypes.array,
  bronzeSponsors: PropTypes.array
};

const sponsorQuery = `{ name, social { homepage }, about, image }`;
export default hot(module)(
  connect(`
{
  partners ${sponsorQuery},
  goldSponsors ${sponsorQuery},
  silverSponsors ${sponsorQuery},
  bronzeSponsors ${sponsorQuery},
}
`)(SiteBody)
);
