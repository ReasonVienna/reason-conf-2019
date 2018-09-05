type state = {
  instance: ref(option(BasicScroll.t)),
  scrollAreaRef: ref(option(Dom.element)),
};

let component = ReasonReact.reducerComponent("ParallaxScroll");

let setScrollAreaRef = (theRef, {ReasonReact.state}) =>
  state.scrollAreaRef := Js.Nullable.toOption(theRef);

let initScroll = (~from: string, ~to_: string, ~props: Js.t({..}), state) =>
  switch (state.instance^, state.scrollAreaRef^) {
  | (None, Some(scrollArea)) =>
    open BasicScroll;
    let newInstance =
      maybeCreate({
        "elem": scrollArea,
        "from": from,
        "to": to_,
        "props": props,
      });
    switch (newInstance) {
    | Some(instance) =>
      start(instance);
      state.instance := Some(instance);
    | None => ()
    };
  | (_, _) => ()
  };

let make = (~from: string, ~to_: string, ~props: Js.t({..}), children) => {
  ...component,
  initialState: () => {instance: ref(None), scrollAreaRef: ref(None)},
  didMount: self => initScroll(~from, ~to_, ~props, self.state),
  willReceiveProps: self => {
    initScroll(~from, ~to_, ~props, self.state);
    self.state;
  },
  willUnmount: self =>
    BasicScroll.(
      switch (self.state.instance^) {
      | Some(instance) =>
        update(instance);
        stop(instance);
        self.state.instance := None;
      | None => ()
      }
    ),
  reducer: ((), _state) => ReasonReact.NoUpdate,
  render: self => <div ref={self.handle(setScrollAreaRef)}> children </div>,
};
