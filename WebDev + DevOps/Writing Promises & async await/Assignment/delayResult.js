
// // Problem Description – Delayed Success (Sleep Wrapper)
// //
// // You are given a value and a delay time in milliseconds.
// // Your task is to implement delayResult(value, ms).
// //
// // The function must return a Promise that resolves with the given value
// // only after ms milliseconds.


function delayResult(value, ms) {
    return new Promise(r => setTimeout(() => r(value), ms));
}

delayResult(10, 3000).then((val) => console.log(val));

module.exports = delayResult;