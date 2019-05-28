[@react.component]
let make = () => {
  <div>
    <Navbar />
    <div>
      {ReasonReact.string("Hello world")}
    </div>
  </div>
}
