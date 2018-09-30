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
      <div className=style##inner>
        <div className=style##layout>
          <h1 className=style##heading> {"Impressions from 2018" |> s} </h1>
          <div className=style##tweets>
            /* <TwitterEmbed
                 tweetId="995648995992178688"
                 options={TwitterEmbed.embedOptions(~theme="light")}
               />
               <TwitterEmbed tweetId="995449310627139585" />
               <TwitterEmbed tweetId="995625518979604480" /> */

              {
                Data.Tweet.startPageTweets
                |> Array.map(renderTweet)
                |> ReasonReact.array
              }
            </div>
        </div>
      </div>
    </section>,
};
