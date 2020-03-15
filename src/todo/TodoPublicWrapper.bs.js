// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var TodoInput$ReactHooksTemplate = require("./TodoInput.bs.js");
var TodoPublicList$ReactHooksTemplate = require("./TodoPublicList.bs.js");

function TodoPublicWrapper(Props) {
  return React.createElement("div", {
              className: "todoWrapper"
            }, React.createElement("div", {
                  className: "sectionHeader"
                }, "Public feed (realtime)"), React.createElement(TodoInput$ReactHooksTemplate.make, {
                  isPublic: true
                }), React.createElement(TodoPublicList$ReactHooksTemplate.make, { }));
}

var make = TodoPublicWrapper;

exports.make = make;
/* react Not a pure module */