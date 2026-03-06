import chalk from "chalk";      // modern import syntax, like promises
// const fs = require("fs"); // not work in ES 
import fs from "fs";

console.log(chalk.blue("Hello world"))
console.log(chalk.red.bold("This is an error message"));
console.log(chalk.green.underline("This is an success message"));

fs.readFile("package.json", "utf-8", (err, content) => {
    if(err){
        throw new Error(err);
    } 
    else{
        console.log(content);
    }
})

console.log(__dirname);
console.log(__filename);