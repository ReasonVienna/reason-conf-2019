[@bs.module] external style: Js.t({..}) = "./Tweet.module.scss";

[@bs.module] external twitterLogo: string = "../assets/img/twitter.svg";

open Util;
let component = ReasonReact.statelessComponent("Tweet");

let make = (~tweet: Data.Tweet.t, _children) => {
  ...component,
  render: _ =>
    <div className=style##root>
      <div className=style##header>
        <img className=style##avatar src={tweet.imgSrc} />
        <div className=style##name>
          {tweet.name |> s}
          <span className=style##handle> {"@" ++ tweet.handle |> s} </span>
        </div>
        <a href={tweet.tweetHref} target="_blank">
          <img className=style##icon src=twitterLogo />
        </a>
      </div>
      <div> {tweet.content |> md} </div>
    </div>,
};
