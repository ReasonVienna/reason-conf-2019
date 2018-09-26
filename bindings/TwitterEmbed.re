[@bs.module "react-twitter-embed"]
external linkClass: ReasonReact.reactClass = "TwitterTweetEmbed";
let make = (~tweetId: string, ~options: option(Js.t({..}))=?, _children) => {
  let props = {"tweetId": tweetId, "options": options};
  ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, _children);
};
