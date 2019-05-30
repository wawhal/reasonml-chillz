let makeApolloClient = (token) => {

  // Create an InMemoryCache
  let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

  // headers
  let headers = Json.Encode.object_([("authorization", Json.Encode.string("Bearer " ++ token))]);

  // Create an HTTP Link 
  let httpLink = ApolloLinks.createHttpLink(
    ~uri="https://learn.hasura.io/graphql",
    ~headers=headers,
    ()
  );

  // return apollo client instance
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());
}
