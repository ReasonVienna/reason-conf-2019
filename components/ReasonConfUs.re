[@bs.module] external style: Js.t({..}) = "./ReasonConfUs.module.scss";

let component = ReasonReact.statelessComponent("ReasonConfUs");

let make = _children => {
  ...component,
  render: _self =>
    <section className="container grid grid_12">
      <h1 className="push--1col pull--1col">
        {"Reason Conf US is happening!" |> ReasonReact.string}
      </h1>
      <p className="extraText push--1col pull--1col">
        {
          "We're proud to announce Reason Conf US taking place in Chicago, IL on October 8th. Keynote by Jordan Walke. "
          |> ReasonReact.string
        }
        <a href="https://www.reason-conf.us/">
          {"Buy tickets before they sell out!" |> ReasonReact.string}
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
