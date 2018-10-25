/*
 By default, the component is hidden.
 During the mount process, we parse the cookie and if the cookie is not
 set, we will show the popup.

 The user has two choices: Accept / Decline

 On Accept, we store a new Cookie with gdpr_accept=true
 On Decline, we delete the Cookie, no matter if it was previously set or not

 This component is Client based. You can't use this for SSR and need to use
 it with Antwar's Interactive component.
 */

[@bs.module] external style: Js.t({..}) = "./CookieBox.module.scss";

open Util;

type state =
  | Shown
  | Hidden;

type action =
  | Agrees
  | Declines
  | Show;

let component = ReasonReact.reducerComponent("CookieBox");

let cookieName = "gdpr_accept";
let cookieValue = "1";

[@genType]
let make = _children => {
  ...component,
  initialState: () => Hidden,
  didMount: self => {
    let cookie = Cookie.readCookie(~name=cookieName);
    switch (cookie) {
    | Some(v) =>
      if (v != cookieValue) {
        self.send(Show);
      } else {
        self.send(Agrees);
      }
    | None => self.send(Show)
    };
  },
  reducer: (action, state) =>
    /* Only do a hide rerender if the component is currently shown */
    switch (action, state) {
    | (Show, _) => ReasonReact.Update(Shown)
    | (Agrees, Shown) =>
      ReasonReact.UpdateWithSideEffects(
        Hidden,
        (
          _ =>
            Cookie.createCookie(~name=cookieName, ~value=cookieValue, ~days=7)
        ),
      )
    | (Declines, Shown) =>
      ReasonReact.UpdateWithSideEffects(
        Hidden,
        (_ => Cookie.eraseCookie(~name=cookieName)),
      )
    | (_, Hidden) => ReasonReact.NoUpdate
    },
  render: self => {
    let className =
      switch (self.state) {
      | Shown => style##shown
      | Hidden => style##hidden
      };
    <div className>
      {
        "We use cookies and other tracking technologies to analyze site traffic, and understand where our audience is coming from. To find out more, please read our [Privacy Policy](/privacy)"
        |> md
      }
      <Button onClick={_evt => self.send(Agrees)}> {"Accept" |> s} </Button>
      <Button onClick={_evt => self.send(Declines)}>
        {"Decline" |> s}
      </Button>
    </div>;
  },
};
