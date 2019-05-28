// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReactRouter = require("reason-react/src/ReasonReactRouter.js");
var App$ReactHooksTemplate = require("./App.bs.js");
var Login$ReactHooksTemplate = require("./auth/Login.bs.js");

function Router(Props) {
  var url = ReasonReactRouter.useUrl(undefined, /* () */0);
  var match = url[/* path */0];
  var exit = 0;
  if (match) {
    if (match[0] === "login" && !match[1]) {
      return React.createElement(Login$ReactHooksTemplate.make, { });
    } else {
      exit = 1;
    }
  } else {
    return React.createElement(App$ReactHooksTemplate.make, { });
  }
  if (exit === 1) {
    ReasonReactRouter.push("/");
    return React.createElement("div", undefined, "Please wait...");
  }
  
}

var make = Router;

exports.make = make;
/* react Not a pure module */
