// Assignment:- Write a function first_ele that takes an array as input, 
//               return the first ele if it exist, if it doesn't exists then returns null

function first_ele(arr: number[]): number | null{   //optional- return type for function, composite return type
    if(arr.length > 0){ 
        // return arr[0];  //number | undefined -> typescript compiler 'tsc' is not that smart who thinks arr[0] can be undefined, that's why return type include undefined also
        return arr[0] ?? null;     // for that undefined -> we can write like this
    }

    return null;    // null
}

let arr = [1,2,3,4,5];
let x = first_ele(arr);
console.log(x);
console.log(first_ele([]));

// composite return type
let z: number | string = 90;
z = "harkirat";
console.log(z);


// function to check whether user is valid to vote or not
function isValid(user: any): boolean {
    return user.age >= 18;
}

let user = {
    name : "Harkirat",
    age : 25,
    gender : "Male"
};

console.log(isValid(user));

// prnumimitive types :- number, boolean, string
/*
function sum(a:number, b:number) {
    return a+b;
}

function greet(firstName: String)
{
    console.log("Hello " + firstName);
}

greet("Harkirat");

let x = 4;  // type inference -> ts assumes its number
let y = 6;  // can write y:number, x:number
console.log(sum(x,y));
*/




// Q) If we can use zod in js for type checking/safety then why we need TS?
//  - zod doed runtime type check not compile time 
/*
const signupSchema = z.Object({
    username: z.toString(),
    password: z.toString()
})

app.post("/signup", (req, res) => {
    const body = signupSchema.safeParse(req.body);  // this line will check & execute at runtime 
})
*/