
interface User {
    firstName: string,
    lastName: string,
    age: number
}

function isLegalUser(users: User[]){
    return users.filter(user => user.age >= 18);
}

let users: User[] = [
    {
        firstName: "HarKirat",
        lastName: "Singh",
        age: 26
    },
    {
        firstName: "Raman",
        lastName: "Deep",
        age: 16
    }
];

console.log(isLegalUser(users));
