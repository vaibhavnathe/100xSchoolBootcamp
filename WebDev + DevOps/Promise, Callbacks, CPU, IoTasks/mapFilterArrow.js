// map, filter, arrow functions
// Assignment :- Create a map fn that takes an array and transform fn as input and returns the tranformed array as output

//**********filter ********* */
// problem statement :- given an input array, return an array with even values
const input = [1,2,3,4,5,6,7,8];

// normal way -> using loop
let res = [];
for(let i=0; i<input.length; i++){
    if(input[i]%2 == 0){
        res.push(input[i]);
    }
}
console.log(res);

//using filter
function filteringLogic(num){
    return num%2==0;
}
let even = input.filter(filteringLogic);

let even2 = input.filter((num)=>{
    return num%2==0;
})
console.log(even);
console.log(even2);

// more examples
const names = ["harkirat", "raman", "harman"];
const ans = names.filter((name) => {
    return name.startsWith('h');
})
//or write like
const ans2 = names.filter(function(name){
    if(name.endsWith('n')){
        return true;
    }
    else{
        return false;
    }
})
console.log(ans);
console.log(ans2);

// ********** map **************
/*
//problem statement: given an array, return a new array in which every value is multiplied by 2
const arr = [1,2,3,4,5];

// normal way
const newArray = [];
for(let i=0; i<arr.length; i++){
    newArray.push(arr[i]*2);
}
console.log(newArray);

//using map
const input = [2,4,6,8,10]; 

function tranform(ele){
    return ele*2;
}
let res = input.map(tranform);

let res2 = input.map((ele) => {
    return ele*2;
})
console.log(res);
console.log(res2);
*/


/*
// Arrow functions -> there is difference between the normal functions and arrow functions
function sum(a, b){
    return a+b;
}

const sum2 = (a, b) =>{
    return a+b;
}

// express server
const app = express();
app.get("/", (req,res) => {

})

app.get("/", function(req,res){
    
})


// const ans = sum (5,3);
console.log(sum2(5,6));
*/
// Arrow Function vs Normal Function:
// this binding: Normal functions have their own this, while arrow functions inherit this from the surrounding scope.
// Constructor & prototype: Normal functions can be used with new and have a prototype; arrow functions cannot.
// Arguments & syntax: Normal functions have an arguments object; arrow functions don’t and use shorter syntax.
