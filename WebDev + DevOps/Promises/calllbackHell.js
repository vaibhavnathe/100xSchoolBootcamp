// Callback Hell
// why promises are better than callback -> because of its better syntax and readability

// Q. Write code that : 1.logs 'hi' after 1 secoond
//                      2.logs 'hello' after 3 secoond after step1
//                      3.logs 'hello there' after 5 secoond after step2

// using promise chain
function setTimeoutPromisified(ms){
    return new Promise((resolve) => setTimeout(resolve, ms));
}

// same as below but looking better readable
setTimeoutPromisified(1000)
    .then(() => {
        console.log("hi");
        return setTimeoutPromisified(3000);
    }).then(() => {
        console.log("hello");
        return setTimeoutPromisified(5000);
    }).then(() => {
        console.log("hello there");
    })

// promise chain : can say promise hell
/** 
setTimeoutPromisified(1000).then(() => {
    console.log("hi");

    setTimeoutPromisified(3000).then(()=>{
        console.log("hello");

        setTimeoutPromisified(5000).then(() => {
            console.log("hello there")
        })

    })
})
    */


// solution 1: callback hell :- people say this is bad, thats why promise
/** 
setTimeout(() => {
    console.log("hi");

    setTimeout(() => {
        console.log("hello");

        setTimeout(() => {
            console.log("hello there");
        }, 5000);

    }, 3000);

}, 1000);
*/


// solution 2: alt solution -> doesn't really have callback hell :- people say this is bad , thats why promise
/** 
function step3Done(){
    console.log("hello there");
}

function step2Done(){
    console.log('hello');
    setTimeout(step3Done, 5000);
}

function step1Done(){
    console.log('hi');
    setTimeout(step2Done, 3000);
}
setTimeout(step1Done, 1000);
*/



/**
    
    class Promise{

        constructor(fn){
            this.fn = fn;
            this.fn(function(){
                this.successCallback();
            }, function(){
                this.errCallback();
            });
        }

        then(){

            this.successCallback();
            return this
        }

        catch(){

            this.errCallback();
            return this
        }
    }

    p.then().then();

    let x = p.then();
    let y = x.then();

 */