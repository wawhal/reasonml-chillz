// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var TodoItem$ReactHooksTemplate = require("./TodoItem.bs.js");
var TodoFilters$ReactHooksTemplate = require("./TodoFilters.bs.js");

var sampleTodos = /* :: */[
  /* record */[
    /* id */1,
    /* title */"This is private todo 1",
    /* is_completed */true,
    /* is_public */false
  ],
  /* :: */[
    /* record */[
      /* id */2,
      /* title */"This is private todo 2",
      /* is_completed */false,
      /* is_public */false
    ],
    /* [] */0
  ]
];

function TodoPrivateList(Props) {
  var match = React.useReducer((function (state, action) {
          return /* record */[/* filter */action[0]];
        }), /* record */[/* filter */"all"]);
  var dispatch = match[1];
  var state = match[0];
  var filteredTodos = List.filter((function (todo) {
            var match = todo[/* is_completed */2];
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
          }))(sampleTodos);
  var todoList = List.map((function (t) {
          return React.createElement(TodoItem$ReactHooksTemplate.make, {
                      todo: t
                    });
        }), filteredTodos);
  var filterTodos = function (f) {
    return Curry._1(dispatch, /* UpdateFilter */[f]);
  };
  return React.createElement(React.Fragment, {
              children: null
            }, React.createElement("div", {
                  className: "todoListWrapper"
                }, React.createElement("ul", undefined, $$Array.of_list(todoList))), React.createElement(TodoFilters$ReactHooksTemplate.make, {
                  todoCount: List.length(filteredTodos),
                  currentFilter: state[/* filter */0],
                  filterFunc: filterTodos
                }));
}

var make = TodoPrivateList;

exports.sampleTodos = sampleTodos;
exports.make = make;
/* react Not a pure module */
