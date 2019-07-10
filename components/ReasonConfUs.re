[@bs.module] external style: Js.t({..}) = "./ReasonConfUs.module.scss";

let component = ReasonReact.statelessComponent("ReasonConfUs");

let make = _children => {
  ...component,
  render: _self =>
    <section className="container grid grid_12">
      <h1 className="push--1col pull--1col">
        {"Reason Conf US is happening!" |> s}
      </h1>
      <p className="extraText">
        {
          "We're proud to announce Reason Conf US taking place in Chicago, IL on October 8th. Keynote by Jordan Walke. "
          |> s
        }
        <a href="https://www.reason-conf.us/">
          {"Buy tickets before they sell out!" |> s}
        </a>
      </p>
      <a href="https://www.reason-conf.us/" className="push--1col pull--1col">
        <img
          src="https://www.reason-conf.us/img/og-image.jpg"
          alt="ReasonConf US Announcement"
        />
      </a>
    </section>,
};
