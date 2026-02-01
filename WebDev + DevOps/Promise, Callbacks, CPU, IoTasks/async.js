// Stop watch
let counter = 0;
function callback(){
    console.log(counter++);
}

// At every 1000ms = 1sec calling callback function
setInterval(callback, 1000);

console.log("Other code execution");
let sum = 0;
for(let i=0; i<=10; i++){
    sum += i;
}
console.log("Sum : ", sum);

/*
const a = 1;
const b = 2;

console.log(a);
console.log(b);

//setTimeout : async function which will wait for 1 sec for callback function
setTimeout(callback,1000);

function callback(){
    console.log(a+b);
}
console.log(__dirname);     // log current directory
console.log(__filename);    // log current file path

// synchronous code -> doing nothing for 1 second
let beforeTime = Date.now();
let sum = 0;
for(let i=0; i<10000000; i++){
    // let currentTime = Date.now();
    // if(currentTime - beforeTime >= 1000){
    //     break;
    // }
    sum += i;
}

console.log(sum);
*/