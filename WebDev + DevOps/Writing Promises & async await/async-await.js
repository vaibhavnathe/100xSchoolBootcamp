
const fs = require('fs');

const fsReadFilePromisified = (filepath, encoding) => {
    return new Promise((resolve, reject) => {
        fs.readFile(filepath, encoding, (err, data) => {
            if(err){
                reject(err);
            }
            else{
                resolve(data);
            }
        })
    })
}

// 2nd way -: using async await : better syntax on top of .then() , internally doing same thing as .then()
async function main(){
    // read first file then read second file then read third file -> using .then() becomes hard to read
    /** 
    fsReadFilePromisified("promiseNotes.txt", "utf-8")
    .then((data) => {
        console.log(data)
        
        fsReadFilePromisified("a1.txt", "utf-8").then((data) => {
            console.log(data);

            fsReadFilePromisified("a2.txt", "utf-8").then((data) => {
                console.log(data);
            })
        })
    })
    .catch((Err) => console.log("Error while reading file"))
    */

    // better way : using async await
    // looks like sync code but they are async code
    let file1 = await fsReadFilePromisified("promiseNotes.txt", "utf-8");
    let file2 = await fsReadFilePromisified("a1.txt", "utf-8");
    let file3 = await fsReadFilePromisified("a2.txt", "utf-8");

    console.log(file1);
    console.log(file2);
    console.log(file3);
}

main();
console.log("Hi");
console.log("Hello there");


// 1st way to call promisified version
/** 
fsReadFilePromisified('promiseNotes.txt', 'utf-8')
.then((data) => console.log(data))
.catch((err) => console.log("Error while reading file"))
*/