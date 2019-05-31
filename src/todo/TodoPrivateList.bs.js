// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var TodoItem$ReactHooksTemplate = require("./TodoItem.bs.js");
var TodoFilters$ReactHooksTemplate = require("./TodoFilters.bs.js");
var GraphQLQueries$ReactHooksTemplate = require("../GraphQLQueries.bs.js");

function TodoPrivateList(Props) {
  var match = React.useReducer((function (param, action) {
          return /* record */[/* filter */action[0]];
        }), /* record */[/* filter */"all"]);
  var dispatch = match[1];
  var state = match[0];
  return React.createElement(GraphQLQueries$ReactHooksTemplate.GetMyTodosQuery[/* make */4], {
              children: (function (param) {
                  var result = param[/* result */0];
                  if (typeof result === "number") {
                    return React.createElement("div", undefined, "Loading");
                  } else if (result.tag) {
                    var filteredTodos = List.map((function (t) {
                            return React.createElement(TodoItem$ReactHooksTemplate.make, {
                                        todo: t
                                      });
                          }), List.filter((function (todo) {
                                  var match = todo.is_completed;
                                  if (match) {
                                    if (state[/* filter */0] === "all") {
                                      return true;
                                    } else {
                                      return state[/* filter */0] === "complete";
                                    }
                                  } else if (state[/* filter */0] === "all") {
                                    return true;
                                  } else {
                                    return state[/* filter */0] === "active";
                                  }
                                }))($$Array.to_list(result[0].todos)));
                    var filterTodos = function (f) {
                      return Curry._1(dispatch, /* UpdateFilter */[f]);
                    };
                    return React.createElement(React.Fragment, {
                                children: null
                              }, React.createElement("div", {
                                    className: "todoListWrapper"
                                  }, React.createElement("ul", undefined, $$Array.of_list(filteredTodos))), React.createElement(TodoFilters$ReactHooksTemplate.make, {
                                    todoCount: List.length(filteredTodos),
                                    currentFilter: state[/* filter */0],
                                    filterFunc: filterTodos
                                  }));
                  } else {
                    console.error(result[0]);
                    return React.createElement("div", undefined, "Loading");
                  }
                })
            });
}

var make = TodoPrivateList;

exports.make = make;
/* react Not a pure module */
