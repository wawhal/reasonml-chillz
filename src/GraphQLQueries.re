// GraphQL query for getting my todos
module GetMyTodos = [%graphql
  {|
    query getMyTodos {
      todos(where: { is_public: { _eq: false} }, order_by: { id: desc }) {
        id
        title
        is_completed
        is_public
      }
    }
  |}
];
module GetMyTodosQuery = ReasonApollo.CreateQuery(GetMyTodos);

// GraphQL mutation for inserting a todo
module InsertMyTodo = [%graphql
  {|
    mutation ($todo: String!, $isPublic: Boolean!) {
      insert_todos(objects: {title: $todo, is_public: $isPublic}) {
        affected_rows
        returning {
          id
          title
          created_at
          is_completed
        }
      }
    }
  |}
];
module InsertMyTodoMutation = ReasonApollo.CreateMutation(InsertMyTodo);
