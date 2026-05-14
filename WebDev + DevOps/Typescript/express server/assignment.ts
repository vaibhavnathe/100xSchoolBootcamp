
// for the object type: use interface
interface User {
    firstName: String,
    lastName : String,
    email : String,
    age : number
}

function isLegal(user: User): boolean {
    if(user.age > 18){
        return true;
    }
    else{
        return false;
    }
}

let user1: User = {
    firstName: "Harkirat",
    lastName: "Singh",
    email: "harkirat@gmail.com",
    age: 23
}
 
let user2: User = {
    firstName: "Raman",
    lastName: "Deep",
    email: "raman@gmail.com",
    age: 15
}
console.log(isLegal(user1));
console.log(isLegal(user2));