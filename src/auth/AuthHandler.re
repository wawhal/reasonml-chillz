let authOptions = {
  "domain": "graphql-tutorials.auth0.com",
  "clientID": "P38qnFo1lFAQJrzkun--wEzqljVNGcWW",
  "redirectUri": "http://localhost:3000/callback",
  "responseType": "token id_token",
  "scope": "openid"
};

let authClient = Auth0.createClient(authOptions);

type state = {
  token: option(string)
};

type action =
  | SetToken(option(string));

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer((_state, action) =>
  switch(action) {
  | SetToken(token) => { token: token }
  }, { token: None});
  React.useEffect2(() => {
    let token = Util.getTokenFromStorage();
    if (state.token == None && token !== None) {
      dispatch(SetToken(token))
    };
    None
  }, (None, None));
  switch(state.token) {
    | Some(token) => <App token={token}/>
    | None => <Login />
  };
};