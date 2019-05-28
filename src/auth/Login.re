[@react.component]
let make = () => {
  <div className="overlay">
    <div className="overlay-content">
      <div className="overlay-heading">
        {ReasonReact.string("Welcome to the GraphQL tutorial app")}
      </div>
      <div className="overlay-message"> 
        {ReasonReact.string("Please login to continue")}
      </div>
      <div className="overlay-action">
        <button
          id="qsLoginBtn"
          className="btn-primary btn-margin btn loginBtn"
        >
          {ReasonReact.string("Log in")}
        </button>
      </div>
    </div>
  </div>
}
