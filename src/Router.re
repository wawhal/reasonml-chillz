[@react.component]
let make = () => {

  /* Check URL and map path */
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {

    /* Route for Todo App */
    | [] => <Wrapper />

    /* Route for Auth */
    | ["login"] => <Login />

    /* Redirect to root */
    | _ => {
      ReasonReactRouter.push("/");
      <div>{ReasonReact.string("Root")}</div>
    }
  }
}
