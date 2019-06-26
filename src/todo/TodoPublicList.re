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
  "todos": list(todoType)
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

type action = SetTodos(list(todoType));

[@react.component]
let make = (~client) => {

  let (state, dispatch) = React.useReducer((_, action) => {
    let SetTodos(todos) = action;
    { "todos": todos }
  }, { "todos": [] });

  let fetchPublicTodos = () => {
    let fetchPublicTodosQuery = GraphQLQueries.GetPublicTodos.make(());
    let query = {
      "query": ApolloClient.gql(. fetchPublicTodosQuery##query),
      "variables": fetchPublicTodosQuery##variables
    };
    let apolloData = client##query(query);
    apolloData
    |> Js.Promise.then_(gqlResp => {
          Js.log(gqlResp);
          Js.Promise.resolve()
       });
  };

  React.useEffect0(
    () => {
      fetchPublicTodos();
      None;
    }
  );

  let todoList = List.map((t) => <FeedItem todo={t} key={t##title} />, sampleTodos) ;

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