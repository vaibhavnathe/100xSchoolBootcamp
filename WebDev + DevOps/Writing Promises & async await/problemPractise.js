const fs = require('fs');

// 1. Write a function that :- Reads the contenet of file, 
//                             Trim the extra spaces from left to right (we can use trim :- it only removes extra spaces from left and right side only, not from middle)
//                             Writes it back to the the file


// /** 
const fsReadWriteFilePromisified = (filepath, encoding) => {
    return new Promise((resolve, reject) => {
        fs.readFile(filepath, encoding, (err, content) => {
            if(err){
                reject(err);
            }
            else{
                content = content.split(' ').filter((word) => word.length>0).join(' ');
                fs.writeFile(filepath, content, (err) => {
                    if(err){
                        reject(err);
                    }
                    else{
                        resolve(content);
                    }
                });
            }
        })
    })
}

// Approach 4 :- using async await - modern way
const cleanFile = async(filepath) => {
    try{
        let p = await fsReadWriteFilePromisified(filepath, 'utf-8');
        if(p){
            console.log("File has been cleaned");
        }
    }
    catch(err){
        console.log("Error while reading and writing file");
    }
}
// cleanFile('b.txt');
// */


// Approach 3:- promisified version
/*
fsReadWriteFilePromisified('b.txt', 'utf-8')
.then((content) => console.log("File has ben cleaned, content: ", content))
.catch((err) => console.log("Error while reading file"));
*/


//Approach 2:-  async Callback way
/** 
const callback = (err, content) => {
    if(err){
        console.log("Error while reading a file");
    }
    else{
        console.log(content);
        content = content.split(' ').filter((word) => word.length > 0).join(' ');
        fs.writeFile('b.txt', content, () => {});
    }
}
// fs.readFile('b.txt', 'utf-8', callback);
*/


//Approach 1:-  sync way
/** 
let content = fs.readFileSync('b.txt', 'utf-8');
content = content.split(' ').filter((word) => word.length>0).join(' ');
fs.writeFileSync('b.txt', content);
console.log(content);
*/




// 2. Write a promisified function that takes a file prefix as an input (eg. a)
//     and cleans {prefix}1.txt, {prefix}.2.txt, {prefix}.txt -> eg. a1.txt, a2.txt, a3.txt

// even better way -> best way
const cleanManyFiles = async(prefix) => {
       try{ // cleaning all files parallely -> because cleanFile is async functions
            await cleanFile(`${prefix}1.txt`);
            await cleanFile(`${prefix}2.txt`);
            await cleanFile(`${prefix}3.txt`);
       }
       catch(err){
        console.log("Error while cleaning files");
       }
    
}
cleanManyFiles('a')     // here we haven't returned any promise still we are using .then(), .catch() -> because async await is built on top of promise , internally get converted into promise
.then(() => console.log("All files has been cleaned"))
.catch(() => console.log("Error while cleaning files."));


// better way
/** 
const cleanManyFiles = (prefix) => {
    return new Promise(async (resolve, reject) => {
       try{
            await cleanFile(`${prefix}1.txt`);
            await cleanFile(`${prefix}2.txt`);
            await cleanFile(`${prefix}3.txt`);
            resolve();
       }
       catch(err){
        reject(err);
        console.log("Error while cleaning files");
       }
    })
}
cleanManyFiles('a');
*/