import { useState, useEffect } from "react";   // use... -> hook
import axios from "axios";

// useState function returns an array of 2 ele -> [state_var, fun_tochange_state_var]
// function useState(){
//   return ["data", function(){}];
// }

// useEffect(fun, dep arr[]) -> job is to let you run a side effect
//                     - fun executes based on change in value in arr

// flow -> Only first time this component is rendered , data will be initiated to []
//      - In all future re-renders , it will not get re-initiated

function App() {
  // state :- ReactJS State is a built-in object used to store and manage data that changes over time in a component. It allows React components to respond dynamically to user actions and application events.
  // IMP - React only re-renders components if a state-variable changes

  // let data = [];  // normal variable(will get intiated [] at each re-render), not state variable & React only re-renders component when state variable changes but state variable's data or state remains same at each re-render
  
  // state-varible -> react only re-renders component for change in state-variable , re-renders mean(App function recall) , State varibles only initiated at only first render, not for all future re-renders
  let [data, setData] = useState([]);   // res = useState([]);  => can write also data=res[0] , setDate = res[1]

  // to avoid recursive request/fun call caused by changin state var data & re-renders -> useEffect
  // useEffect(function() {    
  //     axios.get("https://jsonplaceholder.typicode.com/todos/")
  //     .then(response => {
  //       setData(response.data);   // now react re-renders the component - at re-render data(state var) does not change, remaining get re-rendered but due re-call again & again infinite request goes internally which is problem
  //     });

  // }, []);   // [] - empty -> function runs only on the first-render(mount), on further renders fun will get skipped
  

  // ex. for understanding the state flow & recursive request/fun call caused by re-rendering data after changin state ->   
  // setTimeout(() => {
  //   setData([...data, {title:"Hi there" +  Math.random()}]);    //using setTimeout not setInterval-> executes fun after give timespan(2 sec), but on page new-entry gets add at each 2 sec, why?
  //                                                                                 // because of Change in state var cause re-render & its getting re-rendered at each 2 sec
  // }, 2000);


  const [currentTodo, setCurrentTodo]  = useState(1);
  // const getTodo = (value:number) => {
  //     axios.get(`https://jsonplaceholder.typicode.com/todos/${value}`)
  //     .then(response => {
  //       console.log(data);
  //       setData([...data, response.data]);
  //     })
  // }

  return (
    <div>
      <b>Hi there too!</b>
      {/* {
        posts.map(post => <Post name={post.name} content={post.content}/>)
      } */}

        {/* // rendering todos from data state variable*/}
        {/* {data.map(todo => 
          <Todo title={todo.title} completed={todo.completed}/>
        )} */}


        {/* Now click on button & get the specifc no todo & render it on page */}
        {/* <button onClick={() => getTodo(1)}>1</button>
        <button onClick={() => getTodo(2)}>2</button>
        <button onClick={() => getTodo(3)}>3</button>
        <button onClick={() => getTodo(4)}>4</button>
        <button onClick={() => getTodo(5)}>5</button> */}
       
        {/* {
          data.map(todo => (
            <div>{todo.title}</div>
          )) 
        } */}


        {/* Using each todo id & fetching data of it through Todo component */}
        <button onClick={() => setCurrentTodo(1)}>1</button>
        <button onClick={() =>  setCurrentTodo(2)}>2</button>
        <button onClick={() =>  setCurrentTodo(3)}>3</button>
        <button onClick={() =>  setCurrentTodo(4)}>4</button>
        <button onClick={() =>  setCurrentTodo(5)}>5</button> 

        <Todo id = {currentTodo}/>
      
    </div>
  )
}

// Components
// functions -> takes arguments
// components -> takes props which is object

// give todId , will render that todo
function Todo(props) { 
  const [currentTodoTitle, setCurrentTodoTitle] = useState("");
  
  const id = props.id;
 
  useEffect(() => {
    console.log("Inside useEffect for id", id);
     axios.get(`https://jsonplaceholder.typicode.com/todos/${id}`)
    .then(response => {
      setCurrentTodoTitle(response.data.title);
    });

    // useEffect can return a function -> also called cleanup function
    return function(){    // first control reaches here for id then executes above logic
      console.log("Hi there for id", id);
    }
  
  }, [id]);   //[id] dependency array ->  re-render based on change in id value

  return (
    <div style={{margin: "5px", backgroundColor: props.backgroundColor, padding: "5px",borderRadius: "5px", border: "2px solid black"}}>
      {/* <h3>{props.title}</h3>
      <p>{props.completed}</p> */}

      <h3>{currentTodoTitle}</h3>

    </div>
  )
}

export default App;