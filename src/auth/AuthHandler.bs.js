// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Auth0Js = require("auth0-js");
var App$ReactHooksTemplate = require("../App.bs.js");
var Util$ReactHooksTemplate = require("./Util.bs.js");
var Login$ReactHooksTemplate = require("./Login.bs.js");

var authOptions = {
  domain: "graphql-tutorials.auth0.com",
  clientID: "P38qnFo1lFAQJrzkun--wEzqljVNGcWW",
  redirectUri: "http://localhost:3000/callback",
  responseType: "token id_token",
  scope: "openid"
};

var authClient = new Auth0Js.WebAuth(authOptions);

function AuthHandler(Props) {
  var match = React.useReducer((function (_state, action) {
          return /* record */[/* token */action[0]];
        }), /* record */[/* token */undefined]);
  var dispatch = match[1];
  var state = match[0];
  React.useEffect((function () {
          var token = Util$ReactHooksTemplate.getTokenFromStorage(/* () */0);
          if (state[/* token */0] === undefined && token !== undefined) {
            Curry._1(dispatch, /* SetToken */[token]);
          }
          return undefined;
        }), /* tuple */[
        undefined,
        undefined
      ]);
  var match$1 = state[/* token */0];
  if (match$1 !== undefined) {
    return React.createElement(App$ReactHooksTemplate.make, {
                token: match$1
              });
  } else {
    return React.createElement(Login$ReactHooksTemplate.make, { });
  }
}

var make = AuthHandler;

exports.authOptions = authOptions;
exports.authClient = authClient;
exports.make = make;
/* authClient Not a pure module */
