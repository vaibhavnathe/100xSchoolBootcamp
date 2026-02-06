/* Write 3 different functions that return promises that resolve after t1, t2, and t3 seconds respectively.
 * Write a function that uses the 3 functions to wait for all 3 promises to resolve using Promise.all,
 * Return a promise.all which return the time in milliseconds it takes to complete the entire operation.
*/

function wait1(t) {
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve();
        }, t)
    })
}

function wait2(t) {
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve();
        }, t)
    })
}

function wait3(t) {
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve();
        }, t)
    })
}

function calculateTime(t1, t2, t3) {
    const start = performance.now();
    return Promise.all([wait1(t1*1000), wait2(t2*1000), wait3(t3*1000)]).then(() => {
        const end = performance.now();
        return end-start;
    })
} 
const res = calculateTime(1,4,3);
res.then((ele) => {
    console.log(ele);
})
 

 /*8. Write a function that halts the JS thread (make it busy wait) for a given number of milliseconds.
 * During this time the thread should not be able to do anything else.
 * the function should return a promise just like before
 */
/** 
function sleep(milliseconds) {
    return new Promise((resolve) => {
        let start = performance.now();
        while(performance.now()-start <= milliseconds){
            // wait for milliseconds
        } 
        resolve("Resolved");
    })
}
sleep(3000).then((msg) => {
    console.log(msg);
});
*/ 


 /*7.  Write a function that returns a promise that resolves after n seconds have passed, where n is passed as an argument to the function.*/
 /** 
const wait = (n) => {
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve("Resolved");
        },n*1000);
    })
}
wait(3).then((ele) =>{
    console.log(ele);
});
*/

// 6.  Using `1-counter.md` or `2-counter.md` from the easy section, can you create a
// clock that shows you the current machine time?
// Can you make it so that it updates every second, and shows time in the following formats -  //  - HH:MM::SS (Eg. 13:45:23)
/**                                                                                                 //  - HH:MM::SS AM/PM (Eg 01:45:23 PM)
const time = () => {
    const date = new Date();
    let hour = date.getHours();
    let min = date.getMinutes();
    let sec = date.getSeconds();
    // console.log(hour);

    hour = hour > 12 ? hour%12 : hour;
    console.log("HH:MM::SS = " , hour, ":", min, ":", sec);
}
setInterval(time , 1000);
*/


// 5. // ## File cleaner
// Read a file, remove all the extra spaces and write it back to the same file.
// hello     world    my    name   is       raman => hello world my name is raman
/** 
const fs = require('fs');

fs.readFile('a.txt', 'utf-8', (err, content) => {
    content = content.split(' ').filter((word) => word.length >= 1).join(' ');
    
    fs.writeFile('a.txt', content, () => {
        fs.readFile('a.txt', 'utf-8', (err, data) => {
            console.log(data);
        })
    })
})
*/


//4. ## Write to a file
/** 
const fs = require('fs');

let content = "This is not just a normal text file. Its more...";
fs.writeFileSync('a.txt', content);
const file2 = fs.readFileSync('a.txt', 'utf-8');
console.log(file2);
*/

//3. ## Reading the contents of a file
// You can use the fs library to as a black box, the goal is to understand async tasks. 
/** 
const fs = require('fs');

fs.readFile('a.txt', 'utf-8', (err, content) => {
    console.log(content);
})

// Synchronously 
const file = fs.readFileSync('a.txt', 'utf-8');
// console.log(file);

let sum = 0;
for(let i=1; i<=1000000000; i++){
    sum += i;
}
console.log(sum);
*/


// 2. Counter without setInterval
/* 
let counter = 0;
const updateCounter = () => {
    console.log(counter++);
    setTimeout(updateCounter, 1000);
}
updateCounter();
*/


//1. ## Create a counter in JavaScript
// It should go up as time goes by in intervals of 1 second 
/**
let counter = 0;
const updateCounter = () => {
    console.log(counter++);
}

setInterval(updateCounter, 1000);
 */