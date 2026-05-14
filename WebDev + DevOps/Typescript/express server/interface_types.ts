// Types - similar to interfaces
// diff -> interfaces can be implemented by classes, types can't

interface Person2{      // can be implemented
    name: string,
    age: number
}

type Person = {     // can'nt be implememented, features -> unions , intersection
    name: string,
    age: number
}

let p1: Person = {
    name: "Kirat",
    age: 23
}

// type features:-
type Employee = {
    name: string,
    startDate: Date
}

type Manager = {
    name: string,
    department : string
}

//i) union -> aggregate type
type HiringManager = Manager | Employee;    // union (|) -> need properties either from Employee or Manager
let hr1: HiringManager = {
    name : "Kirat",
    // startDate: new Date(),   // either startDate from Employee or department from Manager type
    department: "CSE"
}

//ii) intersection
type SeniorManager = Manager & Employee;    // intersection (&) -> need properties from both types Employee & Manager
// same as below                            
// type SeniorManager = {
//     name: string,
//     startDate: Date,
//     department: string
// }
let sm1: SeniorManager = {
    name: "rmana",
    startDate: new Date(),
    department : "IT"
}




//************* */ Interfaces
/*
interface Person {
    name: String,
    age: number,
    greet(phrase: string) : void
}

class Manager implements Person{

    name: string;
    age: number;

    constructor(name: string, age: number)
    {
        this.name = name;
        this.age = age;
    }

    greet(phrase: string){
        console.log("Hi Sir", phrase);
    }
}

class Employee implements Person{

    name: string;
    age: number;

    constructor(name: string, age: number)
    {
        this.name = name;
        this.age = age;
    }

    greet(phrase: string){
        console.log("Chal na", phrase);
    }
}
    */