[@bs.module] external style: Js.t({..}) = "./impressionsSection.module.scss";

open Util;

let component = ReasonReact.statelessComponent("ImpressionsSection");

type navigationLocation =
  | Header
  | Footer;

let renderTweet = (tweet: Data.Tweet.t) => <Tweet tweet key={tweet.handle} />;

let make = _children => {
  ...component,
  render: _self =>
    <section className=style##root>
      <div className="container">
        <h1 className="push--1col pull--1col">
          {"Impressions from 2018" |> s}
        </h1>
        {
          Data.Tweet.startPageTweets
          |> Array.map(renderTweet)
          |> ReasonReact.array
        }
      </div>
    </section>,
};
