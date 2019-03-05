[@bs.module] external chengLouImg: string = "../assets/img/speakers/cheng.jpg";

[@bs.module]
external amelieBenoitImg: string = "../assets/img/speakers/amelie.png";

[@bs.module]
external benjaminSanSouciImg: string = "../assets/img/speakers/ben.jpg";

[@bs.module]
external peterPiekarczykImg: string = "../assets/img/speakers/peter.jpg";

[@bs.module]
external jonathanSiebernImg: string = "../assets/img/speakers/jonathan.jpg";

[@bs.module]
external gagePetersonImg: string = "../assets/img/speakers/gage.jpg";
[@bs.module]
external christophKnittelImg: string = "../assets/img/speakers/christoph.png";

[@bs.module]
external davidCorticchiatoImg: string = "../assets/img/speakers/david.jpg";

[@bs.module]
external jeremieDiminoImg: string = "../assets/img/speakers/jeremie.jpg";

[@bs.module]
external douglasTeohImg: string = "../assets/img/speakers/douglas.jpg";

[@bs.module]
external speakerPlaceholder: string = "../assets/img/speaker-placeholder.svg";

[@bs.module]
external accentureLogo: string = "../assets/img/partners/accenture-logo.svg";

[@bs.module]
external janeStreetLogo: string = "../assets/img/partners/janestreet-logo.svg";

[@bs.module] external g2iLogo: string = "../assets/img/partners/g2i-logo.svg";

[@bs.module]
external imandraLogo: string = "../assets/img/partners/imandra-logo.svg";

/* List.find_opt is not supported by this BuckleScript version yet */
let find_opt = (fn, l) =>
  try (List.find(fn, l) |> (r => Some(r))) {
  | Not_found => None
  };

let cfpLink = "https://goo.gl/forms/1X7U4grPRs6MYcCh1";
let discordLink = "https://discord.gg/5Mtj7rx";

module Organizer = {
  [@bs.module] external style: Js.t({..}) = "./logoRow.module.scss";

  [@bs.module]
  external reasonViennaLogo: string =
    "../assets/img/partners/reasonvienna.svg";

  [@bs.module]
  external reasonAssocLogo: string =
    "../assets/img/partners/reason-association-logo.svg";

  [@bs.module]
  external reactViennaLogo: string =
    "../assets/img/partners/reactvienna-logo.svg";

  [@bs.module] external nikImg: string = "../assets/img/nik.jpg";

  [@bs.module] external patrickImg: string = "../assets/img/patrick.jpg";

  [@bs.module] external andreyImg: string = "../assets/img/andrey.jpg";

  type t = {
    name: string,
    imgUrl: string,
    href: string,
    twitter: string,
  };

  type logoT = {
    name: string,
    imgUrl: string,
    href: string,
  };

  /* First in this list should be rendered last */
  let organizers = [
    {
      name: "Patrick Stapfer",
      imgUrl: patrickImg,
      href: "https://twitter.com/ryyppy",
      twitter: "ryyppy",
    },
    {
      name: "Nik Graf",
      imgUrl: nikImg,
      href: "https://twitter.com/nikgraf",
      twitter: "nikgraf",
    },
    {
      name: "Andrey Okonetchnikov",
      imgUrl: andreyImg,
      href: "https://twitter.com/okonetchnikov",
      twitter: "okonetchnikov",
    },
  ];

  let logos = [
    {
      name: "ReactVienna",
      imgUrl: reactViennaLogo,
      href: "https://twitter.com/reactvienna",
    },
    {
      name: "ReasonVienna",
      imgUrl: reasonViennaLogo,
      href: "https://twitter.com/reasonvienna",
    },
    {
      name: "Reason Association",
      imgUrl: reasonAssocLogo,
      href: "https://www.reason-association.org",
    },
  ];
};

module Speaker = {
  type social = {
    twitterUser: option(string),
    githubUser: option(string),
    website: option(string),
  };
  type talk = {
    title: string,
    abstract: string,
  };
  type t = {
    name: string,
    company: string,
    imgUrl: string,
    description: string,
    talk: option(talk),
    video: option(string),
    slides: option(string),
    social,
  };
  let talkSlug = ({title}: talk) => GithubSlugger.slug(title);
  let speakerAnchor = ({social}) =>
    Js.Option.getWithDefault("tba", social.githubUser);
  let createPlaceholder = (~company="?", ~talk=?, ~name="TBA", ()) => {
    name,
    company,
    imgUrl: speakerPlaceholder,
    description: "Details will be announced reasonably soon!",
    talk,
    video: None,
    slides: None,
    social: {
      githubUser: None,
      twitterUser: None,
      website: None,
    },
  };
  let chengLou = {
    name: "Cheng Lou",
    company: "Facebook",
    imgUrl: chengLouImg,
    description: {j|I work on Reason and Facebook Messenger|j},
    talk: Some({title: "Keynote", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("chenglou"),
      twitterUser: Some("_chenglou"),
      website: None,
    },
  };
  let benjaminSanSouci = {
    name: "Benjamin San Souci",
    company: "Apple",
    imgUrl: benjaminSanSouciImg,
    description: {j||j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/bsansouci"),
      twitterUser: Some("https://twitter.com/bsansouci"),
      website: None,
    },
  };
  let peterPiekarczyk = {
    name: "Peter Piekarczyk",
    company: "Draftbit",
    imgUrl: peterPiekarczykImg,
    description: {j|Peter Piekarczyk is the co-founder of Draftbit: a tool that allows anyone to build native apps visually with almost no learning curve. Draftbit is built with ReasonML and has allowed his team to move quickly and effortlessly. Peter loves to cycle, drink coffee and make music. He's a huge fan of learning how to do new things. Peter was born in Chicago but speaks fluent Polish.|j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/peterpme"),
      twitterUser: Some("https://twitter.com/peterpme"),
      website: Some("https://peterp.me"),
    },
  };

  let jonathanSiebern = {
    name: "Jonathan Siebern",
    company: "Digital Solutions GmbH",
    imgUrl: jonathanSiebernImg,
    description: {j|Full-Stack-Developer from Münster, Germany with about 17 years of experience (mostly web technologies working for Digital Solutions GmbH in Münster, creating tools for online marketers.|j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/jsiebern"),
      twitterUser: Some("https://twitter.com/j_siebern"),
      website: None,
    },
  };
  let gagePeterson = {
    name: "Gage Peterson",
    company: "Podium",
    imgUrl: gagePetersonImg,
    description: {j|I graduated in Computer Science from Brigham Young University - Idaho, where my senior project was building a (poor) programming language in OCaml, later went on to work for Podium where I've built lots of stuff in Elixir, JavaScript (React), and Ruby, OCaml has remained my favorite language through it, recently had more serious discussions about introducing Reason. I'm Vegan, passionate about the environment.|j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/justgage"),
      twitterUser: Some("https://twitter.com/justgage"),
      website: None,
    },
  };
  let christophKnittel = {
    name: "Christoph Knittel",
    company: "Control Center Apps GmbH",
    imgUrl: christophKnittelImg,
    description: {j|Christoph Knittel is CTO at the Vienna-based Control Center Apps GmbH. Combining 20 years of experience in the design and development of software products with enthusiasm for mobile apps, React/React Native and ReasonML, he has set out with his team to bring modern technologies and user interfaces to enterprise applications in the Public Transport and Public Safety industries.|j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/cknitt"),
      twitterUser: Some("https://twitter.com/cknitt"),
      website: Some("https://www.knittel.cc/"),
    },
  };
  let amelieBenoit = {
    name: "Amelie Benoit",
    company: "Ubisoft",
    imgUrl: amelieBenoitImg,
    description: {j|As a web developer, I worked in France to create web applications first using Angular and then React; always in Javascript. A few month ago, I joined Ubisoft Montréal to work on a React-Native application in ReasonML. Sketchnoting addict, I also like to share knowledge and look for solutions to bring fun and dynamism in daily life.|j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/abenoit"),
      twitterUser: Some("https://twitter.com/AmelieBenoit33"),
      website: None,
    },
  };
  let davidCorticchiato = {
    name: "David Corticchiato",
    company: "Ubisoft",
    imgUrl: davidCorticchiatoImg,
    description: {j|I started as a C++ developer 14 years ago (So I'm old basically). About 7 years ago I chose to quit embedded software industry for web development. I've been a Pythonita for a long time, then a javascript developper. Now I work for Ubisoft as a mobile developer. We're rebuilding our app in ReasonML + React Native.|j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/dawee"),
      twitterUser: None,
      website: None,
    },
  };
  let jeremieDimino = {
    name: "Jeremie Dimino",
    company: "Jane Street",
    imgUrl: jeremieDiminoImg,
    description: {j||j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/diml"),
      twitterUser: Some("https://twitter.com/dimenix"),
      website: None,
    },
  };
  let douglasTeoh = {
    name: "Douglas Teoh",
    company: "",
    imgUrl: douglasTeohImg,
    description: {j|Douglas is a software engineer currently working at Allm Inc. in Japan. He develops backend services with Ruby, and webapp frontends with various compile-to-JavaScript languages. He has also published open source macOS apps.|j},
    talk: Some({title: "", abstract: ""}),
    video: None,
    slides: None,
    social: {
      githubUser: Some("https://github.com/dteoh/"),
      twitterUser: None,
      website: Some("https://dteoh.com/"),
    },
  };
  let headlineSpeakers = [|
    chengLou,
    amelieBenoit,
    benjaminSanSouci,
    peterPiekarczyk,
  |];
  let otherSpeakers = [|
    douglasTeoh,
    davidCorticchiato,
    christophKnittel,
    jeremieDimino,
    gagePeterson,
    jonathanSiebern,
  |];
  let speakers: array(t) = Array.concat([headlineSpeakers, otherSpeakers]);
};

module Timetable = {
  type task =
    | Talk(Speaker.t)
    | Misc(string)
    | Break(string)
    | Workshop(list(Speaker.t))
    | OpenEnd(string);
  type step = {
    task,
    duration: option(int),
  };
  type entry = {
    task,
    fromTime: Js.Date.t,
    toTime: option(Js.Date.t),
    duration: option(int),
  };
  type day = {
    date: Js.Date.t,
    entries: list(entry),
  };

  let addDuration = (time, duration) =>
    switch (duration) {
    | Some(d) => DateFns.addMinutes(float_of_int(d), time)
    | None => time
    };
  let day1Steps = [
    {
      task: Misc("Doors open, Registration & Editor Setup"),
      duration: Some(60),
    },
    {task: Workshop([]), duration: Some(180)},
    {task: Break("Lunch"), duration: Some(60)},
    {task: Workshop([]), duration: Some(240)},
    {task: OpenEnd("Open End until ImpactHub closes"), duration: Some(120)},
  ];
  let day2Steps = [
    {task: Misc("Doors open & Registration"), duration: Some(60)},
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: Break("Coffee break"), duration: Some(30)},
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: Break("Lunch"), duration: Some(90)},
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: Talk(Speaker.chengLou), duration: Some(15)},
    {task: Talk(Speaker.chengLou), duration: Some(15)},
    {task: Talk(Speaker.chengLou), duration: Some(15)},
    {task: Talk(Speaker.chengLou), duration: Some(15)},
    {task: Break("Coffee  break"), duration: Some(30)},
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: Break("Coffee  break"), duration: Some(30)},
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: OpenEnd("After Party at Cafe Leopold"), duration: None},
  ];
  let day3Steps = [
    {
      task: Misc("Doors open, Registration & Editor Setup"),
      duration: Some(60),
    },
    {task: OpenEnd("Enjoy yourself"), duration: None},
  ];
  let calcStep = (fromTime: Js.Date.t, step: step): entry => {
    let toTime =
      switch (step.duration) {
      | None => None
      | Some(_) => Some(addDuration(fromTime, step.duration))
      };
    {task: step.task, duration: step.duration, fromTime, toTime};
  };
  let rec calcTimetable =
          (fromTime: Js.Date.t, steps: list(step)): list(entry) =>
    switch (steps) {
    | [s, ...rest] =>
      let next = calcStep(fromTime, s);
      [
        next,
        ...calcTimetable(addDuration(next.fromTime, next.duration), rest),
      ];
    | [] => []
    };

  /* TODO: Why is it saying 11am +2 */
  let startDate = Js.Date.fromString("2019-04-11T11:00:00.000+02:00");
  let day2 = DateFns.addDays(float_of_int(1), startDate);
  let day3 = DateFns.addDays(float_of_int(2), startDate);
  let days = [
    {date: startDate, entries: calcTimetable(startDate, day1Steps)},
    {date: day2, entries: calcTimetable(day2, day2Steps)},
    {date: day3, entries: calcTimetable(day3, day3Steps)},
  ];
};

module Tier = {
  type tier =
    | Gold
    | Catering
    | Supporter
    | Partner;
  type t = {
    id: string,
    name: string,
    cost: int,
    amount: int,
    description: string,
  };
  let sponsorTiers: array(t) = [|
    {
      id: "gold",
      name: "Gold Sponsor",
      cost: 7500,
      amount: 0,
      description: {js|
Same as Catering plus...

- Banner on stage (Day 2 & 3)
- Logo shown in every talk recording & voiceover with a message of your choice
- Logo on the conference badges / lanyards
- Job offer placement on job-board website section
- 3 conference tickets included (1050 EUR)
- Special cooperation to realize your own ideas at the conference (raffles, games code-challenges, etc.)
  |js},
    },
    {
      id: "catering",
      name: "Catering",
      cost: 2500,
      amount: 4,
      description: {js|
Same as Supporter plus...

- Banner in the catering / coffee area
- Logo shown in every talk recording
- Job offer placement on job-board website section
- 2 conference tickets included (700 EUR)
    |js},
    },
    {
      id: "supporter",
      name: "Supporter",
      cost: 1000,
      amount: 9,
      description: {js|
- Logo on the website in the sponsor's section
- Mention on twitter.com
- Job offer placement on job-board website section
- 1 conference ticket included (350 EUR)
    |js},
    },
  |];
};

module Partners = {
  [@bs.module]
  external ahrefsLogo: string = "../assets/img/partners/ahrefs-logo.png";

  [@bs.module]
  external accentureLogo: string = "../assets/img/partners/accenture-logo.svg";

  [@bs.module]
  external janeStreetLogo: string =
    "../assets/img/partners/janestreet-logo.svg";

  [@bs.module]
  external g2iLogo: string = "../assets/img/partners/g2i-logo.svg";

  [@bs.module]
  external tuCCLogo: string = "../assets/img/partners/tucc-logo.svg";

  type sponsorT = {
    name: string,
    logoUrl: string,
    href: string,
    tier: Tier.tier,
  };

  let sponsors = [|
    {
      name: "ahrefs",
      logoUrl: ahrefsLogo,
      href: "https://ahrefs.com/",
      tier: Tier.Gold,
    },
    {
      name: "janestreet",
      logoUrl: janeStreetLogo,
      href: "https://janestreet.com",
      tier: Tier.Gold,
    },
    {
      name: "Imandra",
      logoUrl: imandraLogo,
      href: "https://www.imandra.ai/",
      tier: Tier.Catering,
    },
    {
      name: "g2i",
      logoUrl: g2iLogo,
      href: "https://g2i.co/",
      tier: Tier.Supporter,
    },
  |];

  let partners = [||];
};

module Tweet = {
  type t = {
    name: string,
    handle: string,
    imgSrc: string,
    content: string,
    tweetHref: string,
  };
  let startPageTweets = [|
    {
      name: {j|Jérémie Dimino|j},
      handle: "dimenix",
      imgSrc: {j|https://pbs.twimg.com/profile_images/941456700854472710/__ldUQiF_bigger.jpg|j},
      content: {j|
It was really nice to meet people from the @reasonml community at the
#ReasonConf and see how this new language is making the things we love about
OCaml accessible to new communities. Thanks to the organizers and
congratulations to the authors and maintainers of Reason!
|j},
      tweetHref: {j|https://twitter.com/dimenix/status/995648995992178688?ref_src=twsrc%5Etfw%7Ctwcamp%5Etweetembed&ref_url=https%3A%2F%2Freason-conf.at%2F|j},
    },
    {
      name: {j|Keira|j},
      handle: "keirasaid",
      imgSrc: {j|https://pbs.twimg.com/profile_images/1081301106653683712/cQcUaUpA_bigger.jpg|j},
      content: {j|
To the core contributors who came and tirelessly listened, helped, informed,
debated, taught, demonstrated, and were generally awesome - thank you.
#ReasonConf
      |j},
      tweetHref: {j|https://twitter.com/keirasaid/status/995930697977204736|j},
    },
    {
      name: {j|Ben|j},
      handle: "bsansouci",
      imgSrc: {j|https://pbs.twimg.com/profile_images/465532103212273664/-yUUaMag_bigger.jpeg|j},
      content: {j|
Truly amazing day in Vienna at #ReasonConf

I’ve never seen such a nice community :) @reasonml
      |j},
      tweetHref: {j|https://twitter.com/bsansouci/status/995449310627139585?ref_src=twsrc%5Etfw%7Ctwcamp%5Etweetembed&ref_url=https%3A%2F%2Freason-conf.at%2F|j},
    },
    {
      name: {j|Johann Sonntagbauer|j},
      handle: "johann_sonntag",
      imgSrc: {j|https://pbs.twimg.com/profile_images/1076131606979641344/KZkFBvWQ_bigger.jpg|j},
      content: {j|
#ReasonConf was an inspiring experience and not a conference in traditional
sense. No advertising, simply telling the truth, sharing stories and trying to
work for the best outcome possible. I am so thankfull to have wittnessed this
amazing experience thx!
      |j},
      tweetHref: {j|https://twitter.com/johann_sonntag/status/995711821574230016|j},
    },
    {
      name: {j|Sophie G|j},
      handle: "rarity2017",
      imgSrc: {j|https://pbs.twimg.com/profile_images/929714218332499968/4MpQzqQ0_bigger.jpg|j},
      content: {j|
Thank you #ReasonConf organisers for the sightseeing tour! Was a great
conference from start to finish. Thank you, Vienna!
      |j},
      tweetHref: {j|https://twitter.com/rarity2017/status/995682730007580673|j},
    },
    {
      name: {j|Andrey Popp|j},
      handle: "andreypopp",
      imgSrc: {j|https://pbs.twimg.com/profile_images/987242695503511553/Q7-BSPEK_bigger.jpg|j},
      content: {j|
Got back from @reasonconf, this was the best conf I've ever attended: both from
the fun and usefulness PoV. Thank you @ryyppy @nikgraf and @okonetchnikov for
organising it. The @reasonml community is so nice, been very happy to meet in
person with a lot of people from there 😀
      |j},
      tweetHref: {j|https://twitter.com/andreypopp/status/996671658097291264|j},
    },
    /* {
         name: {j||j},
         handle: "",
         imgSrc: {j||j},
         content: {j||j},
         tweetHref: {j||j},
       }, */
  |];
};

/* For JS interop */
let organizers = Organizer.organizers;
let organizerLogos = Organizer.logos;
