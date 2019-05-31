open TodoTypes;

[@react.component]
let make = (~todo: todo) => {
  let userString = switch(todo.user) {
    | Some(u) => "@" ++ u.name
    | None => ""
  };
  let todoTextStyle = "labelContent" ++ switch(todo.is_completed) {
    | true => " completed"
    | _ => ""
  };
  <li>
    <div className="userInfoPublic" title={userString}>
      {ReasonReact.string(userString)}
    </div>
    <div className={todoTextStyle}>
      <div>
        {ReasonReact.string(todo.title)}
      </div>
    </div>
  </li>
}