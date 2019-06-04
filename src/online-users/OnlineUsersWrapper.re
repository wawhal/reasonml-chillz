[@react.component]
let make = () => {
  <GraphQLQueries.GetOnlineUsersSubscription>
    ...{
      ({result}) => switch(result) {
        | Loading => <div>{ReasonReact.string("Loading")}</div>
        | Error(error) => {
          Js.log(error);
          <div>{ReasonReact.string("Error")}</div>
        }
        | Data(data) => {
          let onlineUsers = Array.map(u => <UserItem user={u}/>, data##online_users);
          let onlineUsersTitle = "Online users - " ++ string_of_int(Array.length(data##online_users));
          <div className="onlineUsersWrapper">
            <div className="sliderHeader">
              {ReasonReact.string(onlineUsersTitle)}
            </div>
            {ReasonReact.array(onlineUsers)}
          </div>
        }
      }
    }
  </GraphQLQueries.GetOnlineUsersSubscription >
}