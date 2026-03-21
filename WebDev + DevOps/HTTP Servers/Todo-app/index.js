const fs = require("fs");
const express = require("express");

const app = express();

// Assignment :- Create a todo application
// post - > extract the todo title from body, create a random id for todo
// delete -> extract the todo id 
const todos = [];       // after this try to store data in a file

// route handlers
app.get("/", (req, res) => {
    // res.send("Welcome to TODO App");
    res.send("Welcome to TODO App");
})

// Create todo
app.post("/todo", (req, res) => {
    console.log("req: ", req);
    console.log("res: ", res);
    // const todo = req.body;
    // todos.push(todo);
    // console.log(todo);
    // res.send(`Todo get added : ${todo}`);
    res.send("request successful");
})

app.get("/all-todos", (req, res) => {
    res.send(todos);
})

// which port
app.listen(3000, () => console.log("Server started at port 3000"));
