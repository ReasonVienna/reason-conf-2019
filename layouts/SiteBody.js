import React from "react";
import { hot } from "react-hot-loader";
import PropTypes from "prop-types";
import { HelmetProvider } from "react-helmet-async";
import { AnchorProvider, Footer, Header, Meta, connect } from "../components";

import "normalize.css/normalize.css";
// import "../styles/fontello-codes.css";
// import "../styles/fontello-embedded.css";
import "../styles/style.scss";

const siteName = "ReasonConf";

const SiteBody = (
  {
    children,
    location: { pathname },
    page: {
      file: { title, description, keywords }
    },
    partners = [],
    goldSponsors = [],
    silverSponsors = [],
    bronzeSponsors = []
  },
  { router }
) => (
  <HelmetProvider
    context={
      router && router.staticContext && router.staticContext.helmetContext
    }
  >
    <AnchorProvider>
      <Meta
        siteName={siteName}
        title={title}
        description={description}
        keywords={keywords}
      />
      <main>
        <Header pathname={pathname} title={title} />
        <div className="main-container container">
          <section className="grid grid_6col">{children}</section>
        </div>
        <Footer />
      </main>
    </AnchorProvider>
  </HelmetProvider>
);
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
