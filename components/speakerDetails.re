open Util;

[@bs.module] external style: Js.t({..}) = "./speakerDetails.module.scss";

module Link = ReactRouterDom.Link;

let talkSlug = Data.Speaker.talkSlug;

let component = ReasonReact.statelessComponent("SpeakerDetails");

let make = (~speaker: Data.Speaker.t, _children) => {
  ...component,
  render: _self =>
    <section className=style##root>
      <section className=style##speakerCard> <SpeakerCard speaker /> </section>
      <section className=style##description>
        <h2 className=style##name id={Data.Speaker.speakerAnchor(speaker)}>
          {speaker.name |> s}
        </h2>
        <p className=style##company>
          {speaker.company ++ " " |> s}
          <div className=style##social>
            <SocialLink target=Twitter link={speaker.social.twitterUser} />
            <SocialLink target=Github link={speaker.social.githubUser} />
            <SocialLink target=Website link={speaker.social.website} />
          </div>
        </p>
        {speaker.description |> md}
        <section className=style##meta>
          {
            switch (speaker.talk) {
            | Some(t) =>
              <Link to_={"/schedule/#" ++ talkSlug(t)}> {t.title |> s} </Link>
            | None => ReasonReact.null
            }
          }
        </section>
      </section>
    </section>,
};
