// auth0.re
type generatedAuth0Client = {.
  "authorize": [@bs.meth] (unit => unit),
  "isAuthenticated": [@bs.meth] (bool => unit)
};

type clientOptions = {
  .
  "domain": string,
  "clientID": string,
  "redirectUri": string,
  "responseType": string,
  "scope": string,
};

[@bs.module "auth0-js"] [@bs.new]  external createClient : (clientOptions => generatedAuth0Client) = "WebAuth";
