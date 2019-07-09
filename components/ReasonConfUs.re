[@bs.module] external style: Js.t({..}) = "./ReasonConfUs.module.scss";

let component = ReasonReact.statelessComponent("ReasonConfUs");

let make = _children => {
  ...component,
  render: _self =>
    <section className="container grid grid_12">
      <a href="https://www.reason-conf.us/" className="push--1col pull--1col">
        <img
          src="https://www.reason-conf.us/img/og-image.jpg"
          alt="ReasonConf US Announcement"
        />
      </a>
    </section>,
};
