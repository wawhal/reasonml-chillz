type user = {
  .
  "name": string
};

type todoType = {
  .
  "id": int,
  "created_at": string,
  "title": string,
  "user": user
};

type state = {
  .
  "todos": array(todoType),
  "loading": bool
};

type todosGqlResp = { 
  .
  "data": state
};

type response = {. "data": state};

external toApolloResult : 'a => response = "%identity";

type action = 
  | SetTodos(array(todoType))
  | SetLoading(bool);

[@react.component]
let make = (~client) => {

  let (state, dispatch) = React.useReducer((_, action) => {
    let SetTodos(todos) = action;
    { "todos": todos, "loading": false }
  }, { "todos": [||], "loading": true });

  let c = ApolloClient.instance;

  let fetchPublicTodos = () => {
    let fetchPublicTodosQuery = GraphQLQueries.GetPublicTodos.make(());
    let query = {
      "query": ApolloClient.gql(. fetchPublicTodosQuery##query),
      "variables": fetchPublicTodosQuery##variables
    };
    let apolloData = c##query(query);
    apolloData
    |> Js.Promise.then_(gqlResp => {
          let resp = toApolloResult(gqlResp);
          dispatch(SetTodos(resp##data##todos));
          Js.Promise.resolve()
       })
    |> ignore
  };

  React.useEffect0(
    () => {
      fetchPublicTodos();
      None;
    }
  );

  if (state##loading) {
    <div>
      {ReasonReact.string("Loading...")}
    </div>
  } else {
    let todoList = Array.map((t) => {
      <FeedItem todo={t} key={t##title} />
    }, state##todos);
    let newTodosBanner = {
      <div className={"loadMoreSection"}>
        {ReasonReact.string("New tasks have arrived!")}
      </div>
    };

    let oldTodosButton = {
      <div className={"loadMoreSection"}>
        {ReasonReact.string("Load older tasks")}
      </div>
    };

    <React.Fragment>
      <div className="todoListWrapper">
        {newTodosBanner}
        <ul>
          {ReasonReact.array(todoList)}
        </ul>
        {oldTodosButton}
      </div>
    </React.Fragment>
  }
}