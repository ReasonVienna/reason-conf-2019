type document;

/*
 This is used for establishing a well-typed interface for
 the content of a cookie, which needs to be in a specific
 format. We express any cookie content as type Content.t
 instead of a string type.

 Advantage of this approach is that we don't need to worry
 about wrongly passing strings. Everytime we want to write
 a cookie, we need to use the Content module first.
 */
module type ContentSig = {
  type t;
  let make: (~name: string, ~value: string, ~days: int) => t;
  let fromString: string => t;
  let read: (t, string) => option(string);
  let toString: t => string;
};

/* must be calculated in float since the int space only covers a couple days in ms */
let daysInMilliseconds = days => days *. 24. *. 60. *. 60. *. 1000.;

module Content: ContentSig = {
  exception StopRead(string);

  type t = string;

  /* See https://www.quirksmode.org/js/cookies.html */
  let make = (~name: string, ~value: string, ~days: int) => {
    let expires =
      if (days > 0) {
        open Js.Date;
        let futureTime =
          make()->getTime
          +. daysInMilliseconds(float_of_int(days))
          |> fromFloat;

        "; expires=" ++ futureTime->toUTCString;
      } else {
        "";
      };
    {j|$name=$value$expires; path=/|j};
  };

  let read = (content, name) => {
    /* Note: This is a hacky approach of doing imperative programming.
       I was literally translating a very imperative example from JS
       to Reason. There are ways to rewrite it in a functional way which
       may be much cleaner */

    open Js.String;
    let nameEQ = name ++ "=";
    let ca = split(";", content);

    let loop = () =>
      for (i in 0 to Array.length(ca) - 1) {
        let c = trim(ca[i]);

        if (indexOf(nameEQ, c) == 0) {
          let ret = substring(~from=length(nameEQ), ~to_=length(c), c);
          raise(StopRead(ret));
        } else {
          ();
        };
      };

    switch (loop()) {
    | exception (StopRead(ret)) => Some(ret)
    | () => None
    };
  };

  let fromString = str => str;
  let toString = content => content;
};

[@bs.val] external document: document = "";
[@bs.set] external setCookie: (document, Content.t) => unit = "cookie";
[@bs.get] external getCookie: document => Content.t = "cookie";

let createCookie = (~name: string, ~value: string, ~days: int) =>
  Content.make(~name, ~value, ~days) |> document->setCookie;

/* Reads the value of cookie with given name */
let readCookie = (~name: string) => document->getCookie->Content.read(name);

let eraseCookie = (~name: string) =>
  Content.make(~name, ~value="", ~days=-1) |> document->setCookie;
