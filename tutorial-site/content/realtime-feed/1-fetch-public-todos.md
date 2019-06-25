---
title: "Fetch public todos"
---

In this section, we are going to need to fire queries without using the JSX components. This means, we need access to the Apollo Client instance. Wrap the required component in an ApolloConsumer so that you can access the `client`. Go to `src/todo/TodoPublicWrapper.re` and wrap `TodoPublicList` component with `ApolloConsumer`.

```js
[@react.component]
let make = () => {
  <div className="todoWrapper">
    <div className="sectionHeader">
      {ReasonReact.string("Public feed (realtime)")}
    </div>
    <TodoInput isPublic=true/>
+    <ReasonApollo.Consumer>
+      ...{
+        client => {
+          <TodoPublicList client={client}/>
+        }
+      }
+    </ReasonApollo.Consumer>
-    <TodoPublicList/>
  </div>
}
```

Now we can access the client instance from the props of `TodoPublicList`.

Let us now load all the todos in before the first render using the `useEffect` hook.

We will start with fetching the newest 7 public tasks. Lets define the query first. Open `src/GraphQLQueries.re` and add the following code at the bottom:

```
query getOldPublicTodos ($oldestTodoId: Int!) {
  todos (where: { is_public: { _eq: true}, id: {_lt: $oldestTodoId}}, limit: 7, order_by: { created_at: desc }) {
    id
    title
    created_at
    user {
      name
    }
  }
}
```




