// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var GraphQLQueries$ReactHooksTemplate = require("../GraphQLQueries.bs.js");

function TodoInput(Props) {
  var isPublic = Props.isPublic;
  var match = React.useReducer((function (param, action) {
          return /* record */[/* text */action[0]];
        }), /* record */[/* text */""]);
  var dispatch = match[1];
  var state = match[0];
  var insertTodoMutation = GraphQLQueries$ReactHooksTemplate.InsertMyTodo[/* make */3](state[/* text */0], isPublic, /* () */0);
  return React.createElement(GraphQLQueries$ReactHooksTemplate.InsertMyTodoMutation[/* make */6], {
              children: (function (mutate, param) {
                  return React.createElement("form", {
                              className: "formInput",
                              onSubmit: (function ($$event) {
                                  $$event.preventDefault();
                                  Curry._4(mutate, Caml_option.some(insertTodoMutation.variables), /* array */["getMyTodos"], undefined, /* () */0).then((function (data) {
                                          Curry._1(dispatch, /* HandleTextChange */[""]);
                                          return Promise.resolve(/* () */0);
                                        }));
                                  return /* () */0;
                                })
                            }, React.createElement("input", {
                                  className: "input",
                                  placeholder: "What needs to be done?",
                                  value: state[/* text */0],
                                  onChange: (function ($$event) {
                                      return Curry._1(dispatch, /* HandleTextChange */[$$event.target.value]);
                                    })
                                }), React.createElement("i", {
                                  className: "inputMarker fa fa-angle-right"
                                }));
                })
            });
}

var make = TodoInput;

exports.make = make;
/* react Not a pure module */
