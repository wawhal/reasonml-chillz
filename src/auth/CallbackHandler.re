[@react.component]
let make = (~urlHash: string) => {
  if (urlHash == "") {
    ReasonReactRouter.push("/login");
    <Login />;
  } else {
    let auth0Response = Js.String.split("&", urlHash);
    switch(Array.length(auth0Response)) {
      | 0 | 1 | 2 => <Login />
      | _ => {
        if (Js.String.length(auth0Response[1]) < 10) {
          ReasonReactRouter.push("/login");
          <Login />
        } else {
          let idToken = Js.String.substr(~from=9, auth0Response[1]);
          let expiresIn = Js.String.substr(~from=11, auth0Response[3]);
          Util.saveSessionToStorage(idToken, expiresIn);
          ReasonReactRouter.push("/");
          <App />
        }
      }
    };
  }
}