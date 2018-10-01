[@bs.module] external style: Js.t({..}) = "./Tweet.module.scss";

[@bs.module] external twitterLogo: string = "../assets/img/twitter.svg";

open Util;
let component = ReasonReact.statelessComponent("Tweet");

let make = (~tweet: Data.Tweet.t, _children) => {
  ...component,
  render: _ =>
    <section className=style##root>
      <header className=style##header>
        <img
          className=style##avatar
          src={tweet.imgSrc}
          alt={tweet.name ++ " avatar image"}
        />
        <div className=style##name>
          {tweet.name |> s}
          <span className=style##handle> {"@" ++ tweet.handle |> s} </span>
        </div>
        <a href={tweet.tweetHref}>
          <img className=style##icon src=twitterLogo />
        </a>
      </header>
      {tweet.content |> md}
    </section>,
};
