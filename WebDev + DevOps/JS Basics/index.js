
// ************* JS Features ************* 

// i) Interprted -> execute line by line
// console.log("Hi there")
// console.log(jhsdjd);

// ii) Dynamic typed -> can change types of varible dynamically
/*
var num = 15;
num = "hello";
console.log(num);
num = true;
console.log(num);
*/


// iii) Single threaded -> running program on only one core(cpu)
                        // -> possess one task at a time

// iv) Garbage Collector -> JavaScript automatically manages memory allocation and deallocation through garbage collection.
                    // -> did manually in cpp(programmer allocate & deallocate) , rust(it has its own ownership model for memory management, makes it extremely safe to memory errors)




// *********** Syntax of Javascript
/*
let name = "John";  // Variables that can be reassigned
const age =  30;    // Const variables that cannot be changed/reassigned
var isStudent = true;   // Older way to declare variables, function-scoped

let color = "skyblue";
const height = 185;
var likePizza = true;

console.log(color);
console.log(height);
console.log(likePizza);
*/


// ************* Data types
// let num = 43;
// let string = "Hello jee";
// let isActive = false;
// let numbers = [15,47,23,96,42];


// ************ Operators
// let sum = 10 + 14;
// let isEqual = (10 === 20);
// let isTrue = (true && false)


//************ Functions
/*
let firstName = "HKirat";
console.log("Hello " + firstName);
console.log("namaste " + firstName);
console.log("kiwean aa singh " + firstName);

let firstName1 = "raman";
console.log("Hello " + firstName);
console.log("namaste " + firstName);
console.log("kiwean aa singh " + firstName);

let firstName2 = "Kirat";
console.log("Hello " + firstName);
console.log("namaste " + firstName);
console.log("kiwean aa singh " + firstName);
*/

// CS rule -> DRY : Do not Repeat Yourself
/*
function greet(name){
    console.log("Hello " + name);
    console.log("namaste " + name);
    console.log("kiwean aa singh " + name);

}

let firstName = "HarKirat";
let firstName1 = "Raman";
let firstName2 = "Kirat";

greet(firstName);
greet(firstName1);
greet(firstName2);

*/


// *********** If-else
// /*
function isLegal(age){
    if(age >= 18){
        console.log("You are allowed to vote");
    }
    else{
        console.log("You are not allowed to vote");
    }
}

// isLegal(65);
// isLegal(15);
// */


// *********** Loops
// for(let i=0; i<20; i++){
//     isLegal(i);
// }

// let i=0;
// while(i < 5){
//     console.log(i++);
// }


// ********** Complex Types -> Array , Objects
// Objects -> collection of key-value pairs, key-> string
                                        //   value -> any other data type
/*
function canVote(userName , age){
    if(age >= 18){
        console.log(userName + " can Vote");
    }
    else{
        console.log(userName + " can not Vote");
    }
}
    

function canVote2(user){
    if(user.age >= 18){
        console.log(user.name + " can Vote");
    }
    else{
        console.log(user.name + " can not Vote");
    }
}

// var userName1 = "Harkirat";
// var password1 = "123random";
// var age1 = 22;

// var userName2 = "Ramanjeet";
// var password2 = "raman123";
// var age2 = 15;

const user1 = {
    name : "HarKirat",
    password : "hkirat123",
    age : 22,
    address : {
        city : "Delhi",
        country : "India"
    }
}

const user2 = {
    name : "Raman",
    password : "raman",
    age : 15
}

// canVote(user1["name"], user1["age"]);
// canVote(user2["name"], user2["age"]);

canVote(user1.name, user1.age);
canVote(user2.name, user2.age);

canVote2(user1);
canVote2(user2);

console.log(user1.address.city)

*/


// Array -> group data together
const numbers = [15,47,85,96,32];
// console.log(numbers[0]);
// console.log(numbers[5]);
for(let i=0; i<numbers.length; i++){
    console.log(numbers[i]);
}

// const users = ["Harkirat", "raman", "kirat"];
// console.log(users[0]);
// console.log(users[1]);

function canVote(user){
    if(user.age >= 18){
        console.log(user.name + " can Vote");
    }
    else{
        console.log(user.name + " can not Vote");
    }
}
// array of objects
const users = [
    {
        name : "HarKirat",
        password : "hkirat123",
        age : 25,
        addresses : [
           {
            city : "delhi",
            building : 60,
            pincode : 12345
           } ,
           {
            city : "chandigad",
            building : 50,
            pincode : 657432
           }
        ]
    },
    {
        name : "Raman",
        password : "raman123",
        age : 15,
        addresses : []
    },
    {
        name : "Kirat",
        password : "kirat123",
        age : 20,
        addresses: []
    },
]
// console.log(users[0].name);
// console.log(users[0].age);
// console.log(users[1].name);
// console.log(users[1].age);
// for(let i=0; i<users.length; i++){
//     console.log("Name : " + users[i].name);
//     console.log("Age : " + users[i].age);
// }

for(let i=0; i<users.length; i++){

    canVote(users[i]);

    // if(users[i].age >= 18){
    //     console.log(users[i].name + " Can Vote");
    // }
    // else{
    //     console.log(users[i].name + " Can not Vote");
    // }
}

console.log(users[0].addresses[0].city);
console.log(users[0].addresses[1].city);

