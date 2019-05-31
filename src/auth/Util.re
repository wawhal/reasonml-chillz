let saveTokenToStorage = (value) => {
  Dom.Storage.(localStorage |> setItem("@learn.hasura.io:reason-apollo", value))
};

let getTokenFromStorage = () => {
  Dom.Storage.(localStorage |> getItem("@learn.hasura.io:reason-apollo"))
};

let removeTokenFromStorage = () => {
  Dom.Storage.(localStorage |> removeItem("@learn.hasura.io:reason-apollo"))
};
