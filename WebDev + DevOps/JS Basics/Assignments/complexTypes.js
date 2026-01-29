const user1 = {
    name : "HarKirat",
    age : 28,
    gender : "Male"
};

const user2 = {
    name : "Vaibhav",
    age : 23,
    gender : "Male"
}

const user3 = {
    name : "Kiran",
    age : 15,
    gender : "Female"
}

// 4.

// 3. Write a function that takes a new object as input which has name , age  and gender and greets the user with their gender (Hi Mr/Mrs/Others harkirat, your age is 21)
// /*
function greeting(user){
    if(user.gender == "Male"){
        console.log("Hi Mr.", user.name , ",your age is", user.age);
        if(user.age >= 18){
            console.log("You can Vote");
        }
        else{
            console.log("You can't Vote");
        }
    }
    else{
        console.log("Hi Mrs.", user.name , ",your age is", user.age);
        if(user.age >= 18){
                console.log("You can Vote");
            }
            else{
                console.log("You can't Vote");
            }
        }

}
greeting(user1);
greeting(user2);
greeting(user3);
// */

// 2.Write a function that takes a user as an input and greets them with their name and age
/*
function greet(user){
    console.log("Hello", user.name);
    console.log("You age is", user.age);
}

greet(user1);
greet(user2);
*/

// 1. Create a function that takes an array of objects as input, and returns the users whose age > 18 and are male
/*
function canVoteMale(users){
    let legalUsers = [];
    for(let i = 0; i<users.length; i++){
        if(users[i].age >= 18 && users[i].gender == "Male"){
            legalUsers.push(users[i]);
        }
    }

    return legalUsers;
}

const users = [
    {
        name : "HarKirat",
        password : "hkirat123",
        age : 25,
        gender : "Male"
    },
    {
        name : "Raman",
        password : "raman123",
        age : 15,
        gender : "Male"
    },
    {
        name : "Kiran",
        password : "kiran123",
        age : 20,
        gender : "Female"
    },
]

// let legalUsers = canVoteMale(users);
// console.log(legalUsers);
*/