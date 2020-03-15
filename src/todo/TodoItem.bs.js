// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");

function TodoItem(Props) {
  var todo = Props.todo;
  var todoStyle = todo[/* is_completed */2] ? " complete" : "";
  return React.createElement("li", undefined, React.createElement("div", {
                  className: "view"
                }, React.createElement("div", {
                      className: "round"
                    }, React.createElement("input", {
                          id: String(todo[/* id */0]),
                          checked: todo[/* is_completed */2],
                          type: "checkbox"
                        }), React.createElement("label", {
                          htmlFor: String(todo[/* id */0])
                        }))), React.createElement("div", {
                  className: "labelContent" + todoStyle
                }, React.createElement("div", undefined, todo[/* title */1])), React.createElement("button", {
                  className: "closeBtn"
                }, "x"));
}

var make = TodoItem;

exports.make = make;
/* react Not a pure module */