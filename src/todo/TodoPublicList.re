open TodoTypes;

let sampleTodos = [
  {
    id: 1,
    title: "This is public todo 1",
    is_public: true,
    is_completed: false,
    user: Some({
      id: 33,
      name: "someUser1"
    })
  },
  {
    id: 2,
    title: "This is public todo 2",
    is_public: true,
    is_completed: false,
    user: Some({
      id: 45,
      name: "someUser2"
    })
  },
  {
    id: 3,
    title: "This is public todo 3",
    is_public: true,
    is_completed: false,
    user: Some({
      id: 55,
      name: "someUser3"
    })
  },
  {
    id: 4,
    title: "This is public todo 4",
    is_public: true,
    is_completed: false,
    user: Some({
      id:244,
      name: "someUser4"
    })
  }
];

[@react.component]
let make = () => {

  let todoList = List.map((t) => <FeedItem todo={t} />, sampleTodos) ;

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