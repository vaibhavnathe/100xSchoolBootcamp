// #5. Write a function called sum that finds the sum from 1 to a number

function sum(num){
    let sum = 0;
    for(let i=1; i<=num; i++){
        sum += i;
    }
    console.log("Sum : ", sum);
}
sum(10);

// #4.Write an if/else statement that checks if a number is even or odd. If it's even, print "The number is even." Otherwise, print "The number is odd."
/*
function isEven(num){
    if(num&1){
        console.log("The number is odd");
    }
    else{
        console.log("The numbder is even");
    }
}
isEven(90);
*/

// #3. Write a function called canVote that returns true or false if the age of a user is > 18
/*
function canVote(user){
    if(user.age >= 18){
        console.log(user.name + " can vote");
    }
    else{
        console.log(user.name + " can't vote")
    }
}
const user = {
    name : "Hkirat",
    age : 23,
    gender : "Male"
};
canVote(user);
*/

//#2. Write a function sum that finds the sum of two numbers. 
// Side quest - Try passing in a string instead of a number and see what happens?
/*
function sum(num1, num2){
    return num1+num2;
}
// const res = sum(8,9);
const res = sum("eight",9);
console.log("Sum : " + res);
*/


// #1. Create a variable for each of the following: 
// your favorite color, your height in centimeters, and whether you like pizza. Use appropriate variable declarations (let, const, or var). Try logging it using console.log
/*
let favColor = "SkyBlue";
var height = "190cm";
const likePizza = true;
console.log("Favourite color : " + favColor);
console.log("Height : " + height);
console.log("Like pizza : " + likePizza);
*/


