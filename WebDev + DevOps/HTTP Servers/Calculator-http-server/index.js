// http server that supports 4 routes => (/sum, /sub, /divide, /multiply)
// frameworks to create https servers :- express(simplest not best), hono, elysiajs, trpc

// internal dependecies :- comes with nodejs, no need to install separately , ex. 'fs'
// external dependecies :- don't come with nodejs, need to install explicitely , ex. 'express'

const express = require("express");
const path  = require("path");

const app = express();      // creating my app or instance of express

app.use(express.json());    // if we want use json body as input then express.json needs

app.get("/", (req, res) => {
    // res.send("<html> <b> Hi Welcome to the Calculator App </b> </html>");    // hard to maintain

    res.sendFile(path.join(__dirname,"./index.html"));
});

// http://localhost:3000/sum?a=1&b=2 :- use query params(use for filtering) => res.query.a     ex. GET /books?author=John&genre=fiction
// http://localhost:3000/sum/1/2 :- use path params(dynamic params in route to uniquely idenfy) => req.params.a     ex. GET /books/123 
app.post("/sum", (req, res) => {
    // const a = parseInt(req.query.a);  // string :- need to convert to integer
    // const b = parseInt(req.query.b);  // string '1'+'1' => '11'

    //post req :- if data is coming in the body/payload
    const a = parseInt(req.body.a);
    const b = parseInt(req.body.b);

    const sum = a+b;

    // response -> eventually we send one response for one request , to send multiple response :- event-streams used

    /* sending response in 'json' */
    res.json({  
        ans: sum
    })

    /* sending response in 'plain-text' */
    // res.send("ans: " + sum.toString()); 
    
    /* Sending response in 'html' */
    // res.send("<h2><b><u>" + sum.toString() + "</u></b></h2>")
})

/** For path parameters */
// http://localhost:3000/sum/1/2 :- use path params(dynamic params in route to uniquely idenfy) => req.params.a     ex. GET /books/123 
app.get("/sum/:a/:b", (req, res) => {
    // const a = parseInt(req.query.a);  // string :- need to convert to integer
    // const b = parseInt(req.query.b);  // string '1'+'1' => '11'

    const a = parseInt(req.params.a);
    const b = parseInt(req.params.b);

    const sum = a+b;

    // response -> eventually we send one response for one request , to send multiple response :- event-streams used

    /* sending response in 'json' */
    res.json({  
        ans: sum
    })

    /* sending response in 'plain-text' */
    // res.send("ans: " + sum.toString()); 
    
    /* Sending response in 'html' */
    // res.send("<h2><b><u>" + sum.toString() + "</u></b></h2>")
})



// http://localhost:3000/sub?a=1&b=2
app.get("/sub", (req, res) => {
    const {a,b} = req.query;

    const sub = a-b;
    res.json({
        ans : sub
    })
})

// http://localhost:3000/mul?a=1&b=2
app.get("/mul", (req, res) => {
    const {a,b} = req.query;

    const mul = a*b;

    res.json({
        ans : mul
    })
})

// http://localhost:3000/div?a=1&b=2
app.get("/div", (req, res) => {
    const {a,b} = req.query;

    const div = a/b;

    res.json({
        ans: div
    })
})

// ip -> leads you to the machine but, port -> leads you to the actual process on that machine
// localhost :- 127.0.0.1  => our local own machine 
app.listen(3000, () => {
    console.log("Server started on 3000 port");
})