const users = [
    {
        name : "Harkirat",
        age : 29,
        gender : "Male",
    },
    {
        name : "Rishabh",
        age : 25,
        gender : "Male",
    },
    {
        name : "Alan",
        age : 17,
        gender : "Male",
    },
    {
        name : "Kiran",
        age : 18,
        gender : "Female",
    }
]


// 3. Create a function that takes an array of objects as input,and returns the users whose age > 18 and are male
function adultMale(users){
    let res = [];

    for(let i=0; i<users.length; i++){
        if(users[i].age > 18 && users[i].gender == "Male"){
            res.push(users[i]);
        }
    }

    return res;
}

const res = adultMale(users);
console.log(res);


// 2. Write a function that takes an array of users as inputs and returns only the users who are more than 18 years old
/*
function adultUsers(users){
    let res = [];
    for(let i=0; i<users.length; i++){
        if(users[i].age > 18){
            res.push(users[i]);
        }
    }

    return res;
}
console.log(adultUsers(users));
*/

// 1. Write a function that takes an array of numbers as input, and returns a new array with only even values. Read about filter in JS
/*
function printEven(numbers){
    let res = [];

    for(let i=0; i<numbers.length; i++){
        if(numbers[i]%2 == 0){
            res.push(numbers[i]);
        }
    }
    return res;
}

function isEven(num){
    return num%2==0;
}

const numbers = [1,2,3,4,5,6,7,8,9];
// console.log(printEven(numbers));

const res = numbers.filter(isEven); // using filter method which takes function as an argument
console.log(res);
*/