import express from "express";  // deafult export

// old import in JS
// const {userModel, todoModel} = require("./models");

// new Import in TS
import {userModel, todoModel} from "./models";
// import useModel from "./models";     // for default export model

const app = express();

app.use(express.json());

interface SignupInput{
    username: string,
    password: string
}

app.post("/signup", (req, res) => {

    const body: SignupInput  = req.body;    // compile-time checking , not runtime -> zod is used for runtime validation

    // push to db like
    // db.users.create({
    //     data : {
    //         username: body.username,
    //         password: body.password
    //     }
    // })

    res.json({
        message: "Signed up Successfully"
    })
})

app.post("/signin", (req, res) => {
    
})


app.listen(3000, () => {
    console.log(`Server is started on port 3000`);
})