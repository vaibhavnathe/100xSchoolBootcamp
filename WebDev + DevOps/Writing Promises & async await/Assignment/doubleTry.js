// // Problem Description – Double Try (Basic Retry)
// //
// // You are given an async function fn that may fail.
// // Your task is to implement doubleTry(fn).
// //
// // Call fn once. If it succeeds, return the result.
// // If it fails, call fn one more time immediately.
// // If the second attempt fails, reject with the error.
const fs = require('fs');

const fsReadFilePromisified = (filePath, encoding) => {
    return new Promise((resolve, reject) => {
        fs.readFile(filePath, encoding, (err, content) => {
            if(err){
                reject(err);
            }
            else{
                resolve(content);
            }
        } )
    })
}

async function fn() {
    return fsReadFilePromisified('a.txt', 'utf-8');
}

const doubleTry = async(fn) => {
    try{
        return await fn();
    }
    catch(err){
         console.log("Retrying...");
        const res = fn();
        return res;
    }


}

doubleTry(fn)
    .then(res => console.log("Success:", res))
    .catch(err => console.log("Final error:", err.message));
