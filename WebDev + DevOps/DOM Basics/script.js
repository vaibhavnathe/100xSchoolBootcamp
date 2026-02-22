// JS for frontend

let todoIndex = 1;
// write a code that read the content of input box and create todo , add todo on page
const addTodo = () => {
    // get the todo from ele 
    // create a new ele and set its text to todo's text
     // add newEle to the page/dom
     // making input box empty

    const inputTodo = document.getElementById("todoInput");
    const todoText = inputTodo.value;
    inputTodo.value = "";
    
    const todoDiv = document.createElement("div");       // <div> </div>                         // <div> todo's text </div>
    todoDiv.setAttribute("id", `todo${todoIndex}`)
    
    const todoSpan = document.createElement("span");
    todoSpan.innerHTML = todoText;

    const dltBtn = document.createElement("button");
    dltBtn.innerHTML = "Delete todo";
    dltBtn.setAttribute("onclick", `deleteTodo(${todoIndex})`);

    todoDiv.appendChild(todoSpan);
    todoDiv.appendChild(dltBtn);
    todoText && document.getElementById("todos").appendChild(todoDiv);

    todoIndex++;
}

const deleteTodo = (todoIndex) => {
    // alert("Delete todo called with " + todoIndex)\
    const divEle = document.getElementById(`todo${todoIndex}`);
    divEle.parentElement.removeChild(divEle);
    
    // alternatively
    // document.getElementById("todos").removeChild(divEle);
    
}


// assingment :- Implement the editTodo functionality



// this is executing only in backend : JS for backend
/**
const fs = require('fs');
fs.readFile("a.txt", "utf-8", (err, content) => {
    if(err){
        console.log("Error while reading file.")
    }
    else{
        console.log(content);
    }
})
     */