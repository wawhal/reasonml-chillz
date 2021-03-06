// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Auth0Js = require("auth0-js");

var authOptions = {
  domain: "graphql-tutorials.auth0.com",
  clientID: "P38qnFo1lFAQJrzkun--wEzqljVNGcWW",
  redirectUri: "http://localhost:3000/callback",
  responseType: "token id_token",
  scope: "openid"
};

var authClient = new Auth0Js.WebAuth(authOptions);

function Login(Props) {
  return React.createElement("div", {
              className: "overlay"
            }, React.createElement("div", {
                  className: "overlay-content"
                }, React.createElement("div", {
                      className: "overlay-heading"
                    }, "Welcome to the GraphQL tutorial app"), React.createElement("div", {
                      className: "overlay-message"
                    }, "Please login to continue"), React.createElement("div", {
                      className: "overlay-action"
                    }, React.createElement("button", {
                          className: "btn-primary btn-margin btn loginBtn",
                          id: "qsLoginBtn",
                          onClick: (function (param) {
                              return authClient.authorize();
                            })
                        }, "Log in"))));
}

var make = Login;

exports.authOptions = authOptions;
exports.authClient = authClient;
exports.make = make;
/* authClient Not a pure module */
