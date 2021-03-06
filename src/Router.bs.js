// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReactRouter = require("reason-react/src/ReasonReactRouter.js");
var AuthHandler$ReactHooksTemplate = require("./auth/AuthHandler.bs.js");
var CallbackHandler$ReactHooksTemplate = require("./auth/CallbackHandler.bs.js");

function Router(Props) {
  var url = ReasonReactRouter.useUrl(undefined, /* () */0);
  var match = url[/* path */0];
  var exit = 0;
  if (match) {
    switch (match[0]) {
      case "callback" : 
          if (match[1]) {
            exit = 1;
          } else {
            return React.createElement(CallbackHandler$ReactHooksTemplate.make, {
                        urlHash: url[/* hash */1]
                      });
          }
          break;
      case "login" : 
          if (match[1]) {
            exit = 1;
          } else {
            return React.createElement(AuthHandler$ReactHooksTemplate.make, { });
          }
          break;
      default:
        exit = 1;
    }
  } else {
    return React.createElement(AuthHandler$ReactHooksTemplate.make, { });
  }
  if (exit === 1) {
    ReasonReactRouter.push("/");
    return React.createElement("div", undefined, "Please wait...");
  }
  
}

var make = Router;

exports.make = make;
/* react Not a pure module */
