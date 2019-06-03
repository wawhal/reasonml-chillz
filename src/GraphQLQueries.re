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

// GraphQL mutation for toggling a todo
module ToggleMyTodo = [%graphql
  {|
    mutation toggleTodo ($id: Int!, $isCompleted: Boolean!) {
      update_todos(where: {id: {_eq: $id}}, _set: {is_completed: $isCompleted}) {
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
module ToggleMyTodoMutation = ReasonApollo.CreateMutation(ToggleMyTodo);

// GraphQL mutation for removing a todo
module DeleteMyTodo = [%graphql
  {|
    mutation removeTodo ($id: Int!) {
      delete_todos(where: {id: {_eq: $id}}) {
        affected_rows
      }
    }
  |}
];
module DeleteMyTodoMutation = ReasonApollo.CreateMutation(DeleteMyTodo);
