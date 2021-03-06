// sample data
open TodoTypes;
let sampleTodos : list(todo) = [
  {
    id: 1,
    title: "This is private todo 1",
    is_completed: true,
    is_public: false,
    user: None,
  },
  {
    id: 2,
    title: "This is private todo 2",
    is_completed: false,
    is_public: false,
    user: None
  }
];

// state type
type state = {
  filter: string
};

// action type
type action =
  | UpdateFilter(string);

[@react.component]
let make = () => {

  // state and reducer
  let (state, dispatch) = React.useReducer((_state, action) =>
    switch(action) {
      | UpdateFilter(filter) => { filter: filter }
    },
    {filter: "all"}
  );

  // filtering todos
  let filteredTodos = List.filter((todo) => {
    switch(todo.is_completed) {
      | true => state.filter === "all" || state.filter === "complete"
      | false => state.filter === "all" || state.filter === "active"
    };
  }, sampleTodos);
  let todoList = List.map((t) => <TodoItem todo={t} />, filteredTodos);

  // filter callback
  let filterTodos = (f) => {
    dispatch(UpdateFilter(f))
  };

  // return JSX
  <React.Fragment>
    <div className="todoListWrapper">
      <ul>
        {ReasonReact.array(Array.of_list(todoList))}
      </ul>
    </div>
    <TodoFilters
      todoCount={List.length(filteredTodos)}
      currentFilter={state.filter}
      filterFunc={filterTodos}
    />
  </React.Fragment>
}
