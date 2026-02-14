const fs = require('fs');
// Creating a Promise

// Why we write promisified versions if we have the libraries which uses promisified version
// ans -> coz there might be requreiment to write our own promise which is not exist in libraries
// ex. consider fsReadFilePromisified, fsWriteFilePromisified exits nut if we want to fsReadWriteFilePromisified


// 2. Creating a promisified version of setTimeout 
const setTimeoutPromisified = (delay) => {
    return new Promise((resolve, reject) => {
        // logic -> setTimeout
        setTimeout(() =>{
            resolve();
        } ,delay)
    })
}
setTimeoutPromisified(3000) // we never pass a callback in promisified version, always one argument less as compared to callback version
    .then(() => console.log("1 Sec has passed"))
    .catch(() => console.log("Rejected"))
    .finally(() => console.log("Finally always get executed")); // finally block always get executes even if promise get resolved or rejected

// setTimeout calllback version
// const callback = () => {
//     console.log("Callback function");
// }
// setTimeout(callback,2000);



/** 
// 1. Creating a promisified version of fs.readFile on top of fs.readFile
const fsReadFilePromisified = (filePath, encoding) => {
    return new Promise((resolve, reject) => {
        fs.readFile(filePath, encoding, (err, content) => {
            if(err){
                reject(err);
            }
            else{
                resolve(content);
            }
        })
    })
}
fsReadFilePromisified('promiseNotes.txt', 'utf-8')
.then((data) => console.log(data))
.catch((err) => console.log("Error while reading a file", err));

//fs.readFile's callback version
const callback = (err, content) => {
    if(err){
        console.log("Error while reading a file");
    }
    else{
        console.log(content);
    }
} 
// fs.readFile('promiseNotes.txt', 'utf-8', callback);
*/



// Promise states
/* 
const p = new Promise((resolve, reject) => resolve());
console.log(p);
p.then(() => {
    console.log("Resolved");
})
.catch(() =>{
    console.log("Rejected")
})
*/



/**
    class Promise{
        constructor(fn){
            this.fn = fn;
            this.fn(function(){
                this.successCallback();
            }, function(){
                this.errorcallBack();
            })
        }

        then(successCallback){
            this.successCallback();
            return this;
        }

        catch(errCallback){
            this.errCallback();
            return this;
        }
    }

    let p = promisifiedVersion();
    let x = p.then()
    x.then().then()
    .catch();
 */