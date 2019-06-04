---
title: "Create Subscription and Render Result"
---

import GithubLink from "../../src/GithubLink.js";
import YoutubeEmbed from "../../src/YoutubeEmbed.js";

So let's define the graphql subscription to be used.

Open `src/GraphQLQueries.re` and add the following code, below everything else:

<GithubLink link="https://github.com/hasura/graphql-engine/blob/master/community/learn/graphql-tutorials/tutorials/react-apollo/app-final/src/GraphQLQueries.re" text="GraphQLQueries.js"/>

```javascript
// GraphQL subscription to get the list of online users
module GetOnlineUsers = [%graphql
  {|
    subscription getOnlineUsers {
      online_users(order_by: {user: {name: asc }}) {
        id
        user {
          name
        }
      }
    }
  |}
];
module GetOnlineUsersSubscription = ReasonApollo.CreateSubscription(GetOnlineUsers);
```

In the above code:

- `GetOnlineUsers` is a graphql query module built from plain string using `graphql_ppx`. This is similar to wrapping a subscription string with `gql` tag in javascript.
- `GetOnlineUsersSubscription` is a typed React component generated with the `GetOnlineUsers` subscription. It is similar to the subscription component in `react-apollo`.

Now, we will wrap the component with `GetOnlineUsersSubscription` to render the data from subscription instead of the dummy data. Go to `src/online-users/OnlineUsersWrapper.re`, remove the dummy data and wrap the JSX with the Subscription component that we described above:

```javascript
-open UserTypes;
-
-let sampleUsers = [
-  {
-    id: 1,
-    name: "User 1"
-  },
-  {
-    id: 2,
-    name: "User 2"
-  },
-  {
-    id: 3,
-    name: "User 3"
-  },
-  {
-    id: 4,
-    name: "User 4"
-  },
-];

[@react.component]
let make = () => {
+  <GraphQLQueries.GetOnlineUsersSubscription>
+    ...{
+      ({result}) => switch(result) {
+        | Loading => <div>{ReasonReact.string("Loading")}</div>
+        | Error(error) => {
+          Js.log(error);
+          <div>{ReasonReact.string("Error")}</div>
+        }
+        | Data(data) => {
-          let onlineUsers = List.map(u => <UserItem user={u}/>, sampleUsers);
+          let onlineUsers = Array.map(u => <UserItem user={u}/>, data##online_users);
-          let onlineUsersTitle = "Online users - " ++ string_of_int(List.length(sampleUsers));
+          let onlineUsersTitle = "Online users - " ++ string_of_int(Array.length(data##online_users));
          <div className="onlineUsersWrapper">
            <div className="sliderHeader">
              {ReasonReact.string(onlineUsersTitle)}
            </div>
-            {ReasonReact.array(Array.of_list(onlineUsers))}
+            {ReasonReact.array(onlineUsers)}
          </div>
+        }
+      }
+    }
+  </GraphQLQueries.GetOnlineUsersSubscription>
}
```

As you see, the dummy data was a list of records while the data we are using is an array of objects. So we are accessing the fields using the `##` notation. You will have to make similar changes in `src/online-users/UserItem.re` as well.

```js
- open UserTypes;
[@react.component]
-let make = (~user: user) => {
+let make = (~user) => {
+  let key = switch(user##id) {
+    | None => "none"
+    | Some(id) => id
+  };
+  let name = switch(user##user) {
+    | None => "null"
+    | Some(u) => u##name
+  };
+  <div className="userInfo" key=key>
+    <div className="userImg">
+      <i className="far fa-user" />
+    </div>
+    <div className="userName">
+      {ReasonReact.string(name)}
+    </div>
+  </div>
-  <div className="userInfo">
-    <div className="userImg">
-      <i className="far fa-user" />
-    </div>
-    <div className="userName">
-      {ReasonReact.string(user.name)}
-    </div>
-  </div>
};
```

How does this work?
-------------------

We are using a subscription component in the form of `<GetOnlineUsers>` which gives render props (similar to `<Query>` and `<Mutation>` components). The result prop when matched with `Data` type, gives the result of the realtime data for the query we have made.

Refresh your react app and see yourself online! Don't be surprised; There could be other users online as well.

Awesome! You have completed basic implementations of a GraphQL Query, Mutation and Subscriptions. Easy isn't it?
