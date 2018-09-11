type location = {pathname: string};

module StaticRouter = {
  type t = Js.t({.});

  let getHelmetContext: t => option(Js.t({.})) = [%raw
    router => "router && router.staticContext && router.staticContext.helmetContext"
  ];
};
