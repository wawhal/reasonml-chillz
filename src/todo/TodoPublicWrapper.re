[@react.component]
let make = () => {
  <div className="todoWrapper">
    <div className="sectionHeader">
      {ReasonReact.string("Public feed (realtime)")}
    </div>
    <TodoInput isPublic=true/>
    <ReasonApollo.Consumer>
      ...{
        client => {
          <TodoPublicList client={client}/>
        }
      }
    </ReasonApollo.Consumer>
  </div>
}

