// in memory cache for caching GraphQL data 
let cache = ApolloInMemoryCache.createInMemoryCache();

// apollo link instance as a network interface for apollo client
// apollo link also has to be configured with headers
// we get token from local storage and configure apollo link headers with it
let headers = switch(Util.getTokenFromStorage()) {
  | None => Json.Encode.object_([])
  | Some(token) => {
    Js.log(token);
    Json.Encode.object_([("Authorization", Json.Encode.string("Bearer " ++ token))])
  }
};

let link = ApolloLinks.createHttpLink(
  ~uri="https://learn.hasura.io/graphql",
  ~headers=headers,
  ()
);

// apollo client instance
let instance = ReasonApollo.createApolloClient(~link, ~cache, ());

[@bs.module] external gql: ReasonApolloTypes.gql = "graphql-tag";