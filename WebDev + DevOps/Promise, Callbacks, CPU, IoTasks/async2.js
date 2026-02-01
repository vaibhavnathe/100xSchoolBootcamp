// JS Architecture flow:

//1. setTimeout callbacks are sent to Web APIs, while the synchronous for loop executes immediately and prints Sum : 55.
//2. After timers expire in web API's, callbacks move to the Callback Queue.
//3. Event Loop pushes callbacks to the Call Stack once call stack get's empty, executing them in order.


function callback(){
    console.log("This is callback function");
}

setTimeout(callback, 1000);
setTimeout(callback, 2000);
setTimeout(callback, 2000);

let sum = 0;
for(let i=0; i<=10; i++){
    sum += i;
}
console.log("Sum :", sum);