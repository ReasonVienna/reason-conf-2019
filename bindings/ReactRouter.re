type location = {pathname: string};

module StaticRouter = {
  type t;

  let getHelmetContext: t => ReactHelmetAsync.HelmetProvider.context = [%raw
    router => "router && router.staticContext && router.staticContext.helmetContext"
  ];
};
