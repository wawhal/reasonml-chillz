[@react.component]
let make = (~todo) => {
  Js.log(todo);
  <li>
    <div className="userInfoPublic" title={todo##user##name}>
      {ReasonReact.string(todo##user##name)}
    </div>
    <div>
      <div>
        {ReasonReact.string(todo##title)}
      </div>
    </div>
  </li>
}