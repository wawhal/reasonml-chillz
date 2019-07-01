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
  "todos": list(todoType),
  "loading": bool
};

type todosGqlResp = { 
  .
  "data": state
};

let sampleTodos = [
  {
    "id": 1,
    "title": "task1",
    "created_at": "something",
    "user": {
      "name": "User 1"
    }
  },
  {
    "id": 2,
    "title": "task2",
    "created_at": "something2",
    "user": {
      "name": "User 2"
    }
  }
];

type response = {. "data": state};

external toApolloResult : 'a => response = "%identity";

type action = 
  | SetTodos(list(todoType))
  | SetLoading(bool);

[@react.component]
let make = (~client) => {

  let (state, dispatch) = React.useReducer((_, action) => {
    let SetTodos(todos) = action;
    { "todos": todos, "loading": false }
  }, { "todos": [], "loading": true });

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
    Js.log("Loading..............");
    <div>
      {ReasonReact.string("Loading...")}
    </div>
  } else {
    let todoList = List.mapi((i, t) => {
      Js.log("======================");
      Js.log(state##todos);
      Js.log(i);
      Js.log(t);
      Js.log(List.nth(state##todos, i*2));
      Js.log("======================");
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
          {ReasonReact.array(Array.of_list(todoList))}
        </ul>
        {oldTodosButton}
      </div>
    </React.Fragment>
  }


}