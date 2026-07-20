import React, { useContext } from 'react';
import axios from 'axios';
import { useEffect, useState } from 'react'
import { useTodos } from './hooks/useTodos';
import { setTodosContext } from './context';

// provider : wrapping App component
function App() {
  const {todos, setTodos} = useTodos();   // custom hook 
  const [darkTheme, setDarkTheme] = useState(false);
  
  return  (

    <setTodosContext.Provider value={{setTodos, darkTheme}}>
      <>
      <button onClick={() => setDarkTheme(!darkTheme)} style={{padding: 5, borderRadius: 6, background: darkTheme ? "white" : "black", color:darkTheme ? "black" : "white", fontSize: 15, cursor:"pointer"}} >
        Change Theme
        </button>

      {todos.map(todo => (
        <Todo title={todo.title} id={todo.id}/>
      ))}  
      </>
    </setTodosContext.Provider>
  )
}
export default App



// Todo Component
type TodoType = {title: string, id: number};

const Todo = ({title, id} : TodoType) => {

  const {darkTheme} = useContext(setTodosContext);

  return <div style={{background: darkTheme ? "black" : "white", display:"flex", justifyContent:"space-between", padding: 15, color: darkTheme ? "white" : "black", margin:10, border: "2px solid black", borderRadius: 5}}>
          {title}
        <DeleteButton id={id}/>
      </div> 
}


// here setTodos is passed from , App => Todo => DeleteButton component : this is prop drilling
// solution :- i) Roll-up state to LCA(least common ancestor) - Code becomes to much big cause of multiple stat variables  
// ii) context-api (lets you grid of prop-drilling) - It provides transferring state from One component to direct needed component , no intermediate component

// DeleteButtoon Component
const DeleteButton = ({id} : {id: number}) => {

  const {setTodos, darkTheme} = useContext(setTodosContext);

  return <div>
    <button style={{padding:5, background: darkTheme ? "white" : "black" , color: darkTheme ? "black" : "white", fontSize:15, borderRadius: 6, cursor:"pointer"}}
                onClick={() => {
                  setTodos(todos => todos.filter(todo => todo.id != id));
                }}
    >
        Delete
    </button>
  </div>
}



/**
 * // Here, `setTodos` is passed from App -> Todo -> DeleteButton.
// This is called **prop drilling** because props are passed through
// intermediate components that don't actually use them.

// Solutions:
// 1. Lift state up to the LCA (Least Common Ancestor).
//    - Keep the state in the closest common parent of all components
//      that need access to it.
//    - Drawback: As the application grows, the parent component can
//      become large and difficult to manage because it holds many state variables.

// 2. Context API
//    - Eliminates the need for prop drilling.
//    - Allows data/state to be shared directly with any component
//      that needs it, without passing props through intermediate components.
//    - Best for global or shared state (e.g., theme, authentication, user data).
 * 
  ** Jargon :
      context - created using React.createContext(). It serves as a container for the data you want to share
      provider - This component wraps part of your application & provides the context value to all its descedants. 
               - Any component that is child of this provider can access the context.
      consumer - This component subscribes to context changes. It allows you to access the context value (using useContext hook)

 */

