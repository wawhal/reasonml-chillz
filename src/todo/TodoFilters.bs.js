// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function TodoFilters(Props) {
  var todoCount = Props.todoCount;
  var currentFilter = Props.currentFilter;
  var filterFunc = Props.filterFunc;
  var todoCountLabel = String(todoCount) + (" item" + (
      todoCount === 1 ? "s" : ""
    ));
  var match = currentFilter === "all";
  var match$1 = currentFilter === "active";
  var match$2 = currentFilter === "complete";
  return React.createElement("div", {
              className: "footerList"
            }, React.createElement("span", undefined, todoCountLabel), React.createElement("ul", undefined, React.createElement("li", {
                      onClick: (function (_event) {
                          return Curry._1(filterFunc, "all");
                        })
                    }, React.createElement("a", {
                          className: match ? "selected" : ""
                        }, "All")), React.createElement("li", {
                      onClick: (function (_event) {
                          return Curry._1(filterFunc, "active");
                        })
                    }, React.createElement("a", {
                          className: match$1 ? "selected" : ""
                        }, "Active")), React.createElement("li", {
                      onClick: (function (_event) {
                          return Curry._1(filterFunc, "complete");
                        })
                    }, React.createElement("a", {
                          className: match$2 ? "selected" : ""
                        }, "Completed"))));
}

var make = TodoFilters;

exports.make = make;
/* react Not a pure module */