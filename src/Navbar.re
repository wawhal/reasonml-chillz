[@react.component]
let make = () => {
  <nav className="m-bottom-0 navbar navbar-default">
    <div className="container-fluid">
      <div className="navHeader navbar-header">
        <span className="navBrand navbar-brand">
          {ReasonReact.string("GraphQL Tutorial App")}
        </span>
        <ul className="nav navbar-nav navbar-right">
          <li role="presentation">
            <a role="button" href="">
              <button id="qsLogoutBtn" className="btn-margin logoutBtn btn btn-primary">
                {ReasonReact.string("Log out")}      
              </button>
            </a>
          </li>
        </ul>
      </div>
    </div> 
  </nav>
}