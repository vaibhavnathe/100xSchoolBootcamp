// Create a https server

const express = require("express");
const path = require("path");

let requestCount = 0;

const app = express();

app.use(express.json());    // internally :- calling express.json() function which return's another function that check in request whether appliaction/json header is present or not

function countMiddleware(req, res, next) {
    requestCount++;
    next();
}

// countMiddleware will not be applicable to /requestCount route/handler because it is above of app.use(countMiddleware)
app.get("/requestCount", (req, res) => {
    res.send({
        requestCount : requestCount
    })
})

// app.use(countMiddleware);   // app.use apply middleware to all next route handlers

// app.use(function(req, res, next){
//     console.log("1st Middleware called");
//     next();                     // forwarding control to next handler , if i don't call it then it won't reach the next route handlers
// });

// app.use((req, res, next) => {
//     console.log("2nd Middleware called");
//     next();
// })


// experimenting 
app.get("/status",countMiddleware,  (req, res) => {
    res.send("Up");
})



app.get("/", countMiddleware, (req, res) => {
    res.sendFile(path.join(__dirname, "index.html"));
})

app.post("/sum", (req, res) => {
    const a = parseInt(req.body.a);
    const b = parseInt(req.body.b);

    const sum = a+b;

    res.json({
        ans : sum
    })
})

app.post("/sub", (req, res) => {
    const a = parseInt(req.body.a);
    const b = parseInt(req.body.b);

    const sub = a-b;

    res.json({
        ans : sub
    })
})

app.post("/mul", (req, res) => {
    const a = parseInt(req.body.a);
    const b = parseInt(req.body.b);

    const mul = a*b;

    res.json({
        ans : mul
    })
})

app.post("/div", (req, res) => {
    const a = parseInt(req.body.a);
    const b = parseInt(req.body.b);

    if(b == 0){
        res.json({
            ans : "Denominator Can't be 0"
        });
    }
    else{
        const div = a/b;

        res.json({
            ans : div
        })
    }
})

app.listen(3000, () => {
    console.log("Server is started on port 3000");
});