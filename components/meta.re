module Helmet = ReactHelmetAsync.Helmet;

let component = ReasonReact.statelessComponent("Meta");

let make =
    (
      ~siteName: string,
      ~title: string,
      ~description: string,
      ~keywords: array(string),
      ~ogImage: string,
      _children,
    ) => {
  ...component,
  render: _self =>
    <Helmet>
      <link rel="canonical" href="https://reason-conf.com/" />
      <link rel="icon" type_="image/png" href="/favicon.png" />
      <title> {ReasonReact.string(siteName ++ " - " ++ title)} </title>
      <meta property="og:site_name" content=siteName />
      <meta charSet="UTF-8" />
      <meta
        name="viewport"
        content="width=device-width, initial-scale=1, maximum-scale=1, minimal-ui"
      />
      <meta name="description" content=description />
      <meta name="keywords" content={Util.join(~sep=", ", keywords)} />
      <meta property="og:title" content=title />
      <meta property="og:description" content=description />
      <meta property="og:image" content=ogImage />
      <meta name="twitter:title" content=title />
      <meta name="twitter:description" content=description />
      <meta name="twitter:site" content="@reasonconf" />
      <meta property="twitter:image" content=ogImage />
    </Helmet>,
};
