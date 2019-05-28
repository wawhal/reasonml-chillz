[@react.component]
let make = () => {

  /* Check URL and map path */
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {

    /* Route for Todo App */
    | [] => <div>{ReasonReact.string("Root")}</div>

    /* Route for Auth */
    | ["login"] => <div>{ReasonReact.string("Login")}</div>

    /* Redirect to root */
    | _ => {
      ReasonReactRouter.push("/");
      <div>{ReasonReact.string("Root")}</div>
    }
  }
}
