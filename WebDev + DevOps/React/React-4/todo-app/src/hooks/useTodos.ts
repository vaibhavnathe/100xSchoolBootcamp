import { useState, useEffect } from "react";
import axios from "axios";

// custom hook  :- A function is called hook if - i) It starts with use
//                                                ii) It uses other hooks
// note :- normal function can't have the other hooks like useEffect inside it
export function useTodos() {

    const [todos, setTodos] = useState([]);

  // just to fetch data from backend & refresh for each 10sec so the new todos get added -> for this code becomes to big
  // => that's where custome hooks used
//   /*
  useEffect(() => {
     axios.get("https://jsonplaceholder.typicode.com/todos/")
      .then((response) => {
        // console.log(response);
        setTodos(response.data);
      })

    // let interval = setInterval(() => {
    //   axios.get("https://jsonplaceholder.typicode.com/todos/")
    //   .then((response) => {
    //     // console.log(response);
    //     setTodos(response.data);
    //   })
    // }, 10*1000);

    // return () => {
    //   clearInterval(interval);
    // }
  }, []);
//   */

//   return todos;
  return {todos, setTodos};  // can also return setTodos

}