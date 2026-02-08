// Promise class :- Its an object that represents the eventual completion(or failure) of an async operation & its resulting value.
//         - Promises used to handle the async operation
//         - Calling a promise is easy, defining your own is where things get hard


// Promisified version for reading files
const fs = require('fs');

function fsReadFilePromisified(filePath, encoding){
    return new Promise((resolve, reject) => {
        fs.readFile(filePath, encoding, (err, data) => {
            if(err){
                reject(err);
            }
            else{
                 resolve(data);
            }
        })
    })
}

function callbackErr(err){
    console.log("Error while reading file ::", err);
}

function callback(content){
        console.log(content);
}

fsReadFilePromisified('a.txt', 'utf-8')  // promisified way/version
.then(callback)         // on resolve -> if evrything goes well
.catch(callbackErr);    // on reject -> if something went wrong
// fs.readFile('a.txt', 'utf-8', callback);      // callback way/version



/*
function setTimeoutPromisified(ms){
    return new Promise((resolve) => setTimeout(resolve, ms));
}

function callback(){
    console.log("3 Seconds have passed");
}
// calling then method on object of promise class
setTimeoutPromisified(3000).then(callback);     // promisified version - better way & syntax for async tasks like API calls, timers etc
*/
/**
    class Promise{

        constructor(fn){
            fn(resolve, reject);
        }

        then(){     // then is a function of Promise class
        }

        catch(){
        }
    }
 */

// setTimeout(callback, 3000);     // callback version
// let sum = 0;
// for(let i=1; i<=1000; i++){
//     sum += i;
// }
// console.log(sum);


// let p1 = new Promise();

/** 
const fs = require('fs');

const afterReadFile = (err, content) => {
    console.log(content);
}
fs.readFile('a.txt', 'utf-8', afterReadFile);

let sum = 0;
for(let i=1; i<=1000; i++){
    sum += i;
}
console.log(sum);
*/
