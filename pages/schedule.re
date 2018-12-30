open Util;

module Link = ReactRouterDom.Link;

[@bs.module] external style: Js.t({..}) = "./schedule.module.scss";

let component = ReasonReact.statelessComponent("Schedule");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> "Schedule"->s </h1>
      <p>
        "All workshops will be held on the first day from 9:30am to about 5pm."
        ->s
      </p>
      <ul />
      <li>
        <a href="#beginner-reason-and-reasonreact-workshop">
          "Beginner Reason & ReasonReact Workshop"->s
        </a>
      </li>
      <li>
        <a href="#advanced-reasonreact-workshop">
          "Advanced ReasonReact Workshop"->s
        </a>
      </li>
      <li> <a href="#ocaml-workshop"> "OCaml Workshop"->s </a> </li>
      <li>
        <a href="#reason-and-graphql-workshop">
          "Reason & GraphQL Workshop"->s
        </a>
      </li>
      <h3 id="beginner-reason-and-reasonreact-workshop">
        "Beginner Reason & ReasonReact Workshop"->s
      </h3>
      <p>
        {js|
ReasonML is a new cool JavaScript-like language with a strong type-system and first level React bindings. As with every new language, there comes a new ecosystem and unfamiliar concepts with it.

In this workshop, attendees will first of all learn how to setup and use ReasonML with React and find explanations on how to find relevant information for their coding problems (navigating the docs, leverage the community).

Later own they will discover the capabilities of the underlying JS-compiler platform called BuckleScript and see how Reason translates to JavaScript. They slowly will get introduced to the interoperability layer to be able to interact with existing JavaScript code and learn how the React component model works in practise.

In more detail, the workshop will cover following topics:

- Why ReasonML?
- Introduction to the platform / tech stack (OCaml, BuckleScript, Tooling, ReasonML)
- Dev-Setup / Editor integration
- Basic language features (data types, pattern-matching, Collection APIs)
- BuckleScript related topics (JS-compilation,
- React related topics (stateless / reducer components, JSX, CSS etc.)
- Interoperability with existing JavaScript

In the end, ambitious attendees will be able to integrate Reason React components in their existing React codebase without interrupting the existing development workflows.
      |js}
        ->md
      </p>
      <h3 id="advanced-reasonreact-workshop">
        "Advanced ReasonReact Workshop"->s
      </h3>
      <p>
        {js|
ReasonReact is the default set of bindings to ReactJS in Reason. The bindings have popularized the concept of reducers for controlling local state as well as pushing functional approches to ReactJS design patterns.

In this workshop, attendees will learn about the design tradeoffs made in the building of ReasonReact and what capabilities these tradeoffs give you. Attendees will be working with different approaches for creating higher order components and managing complex state.

Later, we will use React Hooks to solve many of the same problems in a way that is closer to ReactJS and provides some distinct advantages.

* ReasonReact vs ReactJS
* Reducers, retainedProps, weird APIs
* Functional components, partial application of components
* Functor components, polymorphic state/props
* React Hooks in Reason

Before this workshop, attendees are expected to have good working familiarity with ReactJS and Reason. Experience with ReasonReact is not required, but definitely recommended.
|js}
        ->md
      </p>
      <h3 id="ocaml-workshop"> "OCaml Workshop"->s </h3>
      <p> {js|Coming soon …|js}->md </p>
      <h3 id="reason-and-graphql-workshop">
        "Reason & GraphQL Workshop"->s
      </h3>
      <p>
        {js|
#### Why two proposals?

We don’t know what the conference audience wants. There are two styles of workshop we can do:

- “Clojure” style: A much more limited scope but much deeper approach. The audience starts with `mkdir my_new_project`  and types in everything from the ground up. They naturally leave with a tiny, limited app but know everything about how it’s built and put together. They may be unclear on how to do the next steps (authentication, db interaction, etc.). Nearly no “magic at a distance,” and members may feel much more confident in their ability to overcome challenges on their own afterwards.
- “Rails” style: A much higher-view - steps of the workshop are in a git-checkoutable form, and the workshop alternates between checkout-next-step, explain what’s going on and the motivations, and then hacking on a specific task for the step. In this case the audience should be clear on how things fit together and how to build on it, but not necessarily how it all works under the hood, and may have more problems debugging when things go wrong (definitely going to be “magic at a distance” here, but could be exciting enough to get member to continue exploring deeper at home afterwards), and there’ll be a lot of emphasis on using the Discord channel.

2 months before the workshop we send out a survey to everyone who bought a ticket and based on that one or the other will take place.

#### Expected experience level in both cases:

- Basic familiarity with Reason type system and syntax
- Basic familiarity with http calls between browser/server

#### 1. Clojure Style: Deep-drive, nitty-gritty approach

Let’s explore the benefits and tradeoffs when pairing GraphQL and Reason, both from a server’s and a client’s point-of-view. We’ll build a small app with both a server and client component.

We’ll start with a quick overview of GraphQL’s properties, how the system works, and what the overall ecosystem looks like. We’ll see how its built-in introspect-ability returns fully-descriptive JSON, and how to take that JSON description and generate Reason code and types.

From there, we’ll use GraphQL + ReasonReact on the frontend to build a client for a small app against OneGraph, so we have a sense of what consuming GraphQL is like in a day-to-day context.

Next up, it’s time to start building our own GraphQL server in Reason. We’ll start from scratch, using `esy` to manage our dependencies, and `dune` to manage the build process. We’ll look at how configuration works in both cases. We’ll add in JaneStreet’s Core and Async libraries as dependencies and experiment with what their API surface area looks like. Then we’ll bring in `httpaf` as a basic but highly-performant web server, and see how to build a very basic (non-GraphQL) server with it. We’ll also take a brief look at how to interact with the database via `oneSql`.

Once we’re comfortable with the underlying dependencies and their APIs, we’ll finally build a basic GraphQL server using `ocaml-graphql-server`, and see how we can expose objects, fields, unions, and interfaces.

Finally, we’ll finish up with some thoughts on challenges that you’re likely to faces while implementing GraphQL servers: What constitutes a “good” GraphQL API design, how to optimize your resolvers and overall query execution, dealing with security and permissions, and more.

1. Introduction to GraphQL
  1. Typed schema
  2. Introspection query and results
  3. How to turn that into Reason code and types
  4. graphql_ppx
2. GraphQL on the client
  1. ReasonReact
  2. reason-apollo
3. Building your own GraphQL server in Reason
  1. Setting up a new esy project
  2. Setting up and configuring dune
  3. A basic web-server
    1. Introducing JST Core
    2. Introducing JST Async
    3. Introducing httpaf
    4. Interacting with the database via oneSql
  4. Building a Reason GraphQL server
    1. Introducing ocaml-graphql-server
      1. objects
      2. fields
      3. async and io_fields
      4. unions
      5. interfaces
  5. Closing thoughts on overall GraphQL server design, avoiding N+1 problems, security and permissions

#### 2. Rails Style: High-level, big-scope, example-driven approach

Let’s explore the benefits and tradeoffs when pairing GraphQL and Reason, both from a server’s and a client’s point-of-view. We’ll build a small but realistic full-stack app together that you can take away and tweak for real-work projects afterwards.

We’ll start with a quick overview of GraphQL’s properties, how the system works, and what the overall ecosystem looks like.

From there, we’ll use GraphQL + ReasonReact on the frontend to build a client for a small app against OneGraph, so we have a sense of what consuming GraphQL is like in a day-to-day context.

Next, we’ll move on to building a fully-native Reason GraphQL server. We’ll take an existing project that uses a high-performance http server (`httpaf`), Reason’s GraphQL server (`ocaml-graphql-server`), and a PostgreSQL-compatible model library (`oneSql`) to quickly iterate and build a custom GraphQL application for our client.

Once we have our application running locally, we’ll set up continuous deployment via CircleCI and push our app to production, where anyone can hit it! The CD process will include automated tests that will fail if we attempt to push breaking changes to our GraphQL schema, unless we manually override it. This is a great way to combine the speed of CD with the comfort of knowing you’re (likely!) not breaking any clients.

Towards the end of the day, we’ll see what it’s like to consume another GraphQL service from the server, while still retaining the type safety and convenience that we enjoyed earlier in the day on the client.

Finally, we’ll explore what schema stitching might look like, so that we can enjoy all the existing work that’s gone into the GraphQL SaaS ecosystem, while still providing our own custom data.


- Introduction to GraphQL
- Using GraphQL on the client
  - ReasonReact
  - reason-apollo
  - graphql_ppx
- Building your own GraphQL server in Reason
  - esy - bullet-proof dependency management
  - dune - project management
  - ocaml-graphql-server
  - oneSql - database interactions
  - Canonicalizing and documenting your universe of errors
  - User authentication
  - Schema permissions
- Deploy to “production”
- ReasonML server as a client of a GraphQL service
- Dataloader pattern: Avoiding the N+1 problem
- Schema stitching
- Thoughts on overall GraphQL server design, security and permissions, etc.

|js}
        ->md
      </p>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
