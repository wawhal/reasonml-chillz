// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var ReasonReactRouter = require("reason-react/src/ReasonReactRouter.js");
var App$ReactHooksTemplate = require("../App.bs.js");
var Util$ReactHooksTemplate = require("./Util.bs.js");
var Login$ReactHooksTemplate = require("./Login.bs.js");

function CallbackHandler(Props) {
  var urlHash = Props.urlHash;
  if (urlHash === "") {
    ReasonReactRouter.push("/login");
    return React.createElement(Login$ReactHooksTemplate.make, { });
  } else {
    var auth0Response = urlHash.split("&");
    var match = auth0Response.length;
    if (match === 0 || match === 1) {
      return React.createElement(Login$ReactHooksTemplate.make, { });
    } else if (Caml_array.caml_array_get(auth0Response, 1).length < 10) {
      ReasonReactRouter.push("/login");
      return React.createElement(Login$ReactHooksTemplate.make, { });
    } else {
      var idToken = Caml_array.caml_array_get(auth0Response, 1).substr(9);
      Util$ReactHooksTemplate.saveTokenToStorage(idToken);
      ReasonReactRouter.push("/");
      return React.createElement(App$ReactHooksTemplate.make, {
                  token: idToken
                });
    }
  }
}

var make = CallbackHandler;

exports.make = make;
/* react Not a pure module */
