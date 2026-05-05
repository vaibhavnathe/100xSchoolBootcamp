const fs = require("fs");

// Erro handling in JS

try{
    const fileContent = fs.readFileSync("./main.rs", "utf-8");
    console.log(fileContent);
}
catch(err){
    console.log("Error occured while reading file ", err);
}

// generic in js

// function firstElement<T>(v: T[]): T{
//     return T[0];
// }