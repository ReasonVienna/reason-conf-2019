import React from "react";

export default [
  {
    props: {
      className: "nav--main"
    },
    links: [
      {
        title: "GraphQL Finland",
        url: "https://graphql-finland.fi/"
      },
      {
        title: "About",
        url: "/about/"
      }
      /*{
        title: "Buy tickets",
        url: "/#tickets",
      },*/
    ]
  },
  {
    props: {
      className: "nav--social"
    },
    links: [
      {
        title: (
          <a href="https://www.youtube.com/c/ReactFinland">
            <i className="icon-youtube-play" />
          </a>
        )
      },
      {
        title: (
          <a href="https://medium.com/react-finland">
            <i className="icon-medium" />
          </a>
        )
      },
      {
        title: (
          <a href="https://twitter.com/ReactFinland">
            <i className="icon-twitter" />
          </a>
        )
      },
      {
        title: (
          <a href="https://github.com/ReactFinland">
            <i className="icon-github-circled" />
          </a>
        )
      }
    ]
  },
  {
    props: {
      className: "nav--secondary"
    },
    links: [
      {
        title: "For Attendees",
        url: "/for-attendees/"
      },
      {
        title: "For Sponsors",
        url: "/for-sponsors/"
      },
      {
        title: "2018",
        url: "/2018/"
      }
    ]
  }
];
