
// Q] Create a function that takes another function as input, and runs runs it after 1 second

// function fn(){
//     console.log("Fn function");
// }
// function delay(fn: Function){
//     setTimeout(fn, 1000);
// }
// delay(fn);

function delayCall(fn: () => void) {
    setTimeout(fn, 1000);
}

function fn(){
    console.log("Hi theere");
}

delayCall(fn);