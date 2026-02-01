const fs = require("fs");

// callback function -> fileReadCallback(err, content) : baad mein call kar dena
function fileReadCallback(err, content){
    console.log(content);
}

fs.readFile("a.txt", "utf-8", fileReadCallback);

let sum = 0;
for(let i=1; i<=10000; i++){
    sum += i;
}
console.log(sum);

// Functional Arguments -> passing a function as an argument to another function
/*
function sum(a, b){
    return a+b;
}

function sub(a, b){
    return a-b;
}

function mul(a, b){
    return a*b;
}

function div(a, b){
    return a/b;
}

function doArithmatic(a,b, whatToDo){
    return whatToDo(a,b);
}

const ans1 = doArithmatic(5,4,sum);
const ans2 = doArithmatic(5,4,sub);
const ans3 = doArithmatic(6,4,mul);
const ans4 = doArithmatic(9,3,div);

console.log(ans1);
console.log(ans2);
console.log(ans3);
console.log(ans4);
*/



// I/O Operations -> operations which are not taking cpu and depends on OS for permissions.
/*
const contents = fs.readFileSync("a.txt", "utf-8");
console.log(contents);

const contents2 = fs.readFileSync("b.txt", "utf-8")
console.log(contents2);
*/
