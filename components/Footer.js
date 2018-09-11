import React from "react";
import PropTypes from "prop-types";
import Navigation from "./Navigation";
import navigationPages from "./navigation-pages";

const Footer = ({ pathname }) => {
  return (
    <footer className="footer">
      <div className="footer--wrapper">
        <Navigation pathname={pathname} pages={navigationPages} />
        <section className="footer--bottomLinks">
          <a href="https://toolbox.finland.fi/">Finland Toolbox</a>
          <a href="/imprint/">Imprint</a>
          <a href="/privacy-policy/">Privacy Policy</a>
          <a href="http://berlincodeofconduct.org/">Code of Conduct</a>
        </section>
        <p className="footer--copyright">
          © React Finland, {new Date().getFullYear()}
        </p>
      </div>
    </footer>
  );
};
Footer.propTypes = {
  pathname: PropTypes.string
};

export default Footer;
