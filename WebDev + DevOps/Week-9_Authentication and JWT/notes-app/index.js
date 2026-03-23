
const express = require("express");
const jwt = require("jsonwebtoken");
const {authMiddleware} = require("./middleware");

const app = express();
const path = require("path");

app.use(express.json());    // middleware which extracts body from the req , if we dont use then it will give "can not read prop of undefined"

const notes = [];   // This is bad -- eventually we'll stores this in databases (sql, mongodb, postgress)
const users = [];   // to store user -- this is also bad but we will learn about databases

// signup
app.post("/signup", (req, res) => {
    const username = req.body.username;
    const password = req.body.password;

    const usersExists = users.find(user => user.username === username);

    if(usersExists){
        return res.status(403).json({
            message : "User with this username already exists"
        });
    }

    users.push({
        username : username,       // if key & value are same -> we can write like only username, password
        password : password
    });

    res.status(200).json({
        message : "You have signed up"
    })
    
})

// signing - login
app.post("/signin", (req, res) => {
    const username = req.body.username;
    const password = req.body.password;

    const userExists = users.find(user => user.username === username && user.password === password);

    if(!userExists){
        res.status(403).json({
            message : "Incorrect credentials"
        })
        return ;
    }

    // user exists :- send token to user so user can use this access the diff routes

    // optimal way :- JWT(json web token) 
    const token = jwt.sign({
        username : username
    }, "harkirat123");      // signing using private/secret key : 'harkirat123'
    res.json({
        token : token
    })

})

// POST - Create a note    : AUTHENTICATED ENDPOINT
app.post("/notes", authMiddleware, (req, res) => {
    
    const note = req.body.note;
    const username = req.username;

    notes.push({
        username: username, 
        note: note
    });

    res.json({
        message : "note added!"
    })
})


// GET - get all my notes      : AUTHENTICATED ENDPOINT
app.get("/notes", authMiddleware, (req, res) => {

    const username = req.username;

    const userNotes = notes.filter(note => note.username === username);
    res.json({
        notes : userNotes
    });
})


app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "frontend/index.html"))
})

app.get("/signup", (req, res) => {
    res.sendFile(path.join(__dirname , "frontend/signup.html"));
})

app.get("/signin", (req, res) => {
    res.sendFile(path.join(__dirname, "frontend/signin.html"));
})

app.listen(3000, () => {
    console.log("Server is started on port 3000");
})