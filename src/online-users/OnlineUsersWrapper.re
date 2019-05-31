open UserTypes;

let sampleUsers = [
  {
    id: 1,
    name: "User 1"
  },
  {
    id: 2,
    name: "User 2"
  },
  {
    id: 3,
    name: "User 3"
  },
  {
    id: 4,
    name: "User 4"
  },
];

[@react.component]
let make = () => {
  let onlineUsers = List.map(u => <UserItem user={u}/>, sampleUsers);
  let onlineUsersTitle = "Online users - " ++ string_of_int(List.length(sampleUsers));
  <div className="onlineUsersWrapper">
    <div className="sliderHeader">
      {ReasonReact.string(onlineUsersTitle)}
    </div>
    {ReasonReact.array(Array.of_list(onlineUsers))}
  </div>
}