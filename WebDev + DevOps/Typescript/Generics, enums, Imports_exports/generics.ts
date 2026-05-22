// Generics are a lang independent concept (exist in cpp, rust as well)

// problem statement :- We have function that needs to return the first ele of an array. Array can be type of either string or number

type Arr = string | number;

function firstEle(arr: Arr[]) {
    return arr[0];
}

const arr: Arr[] = ["Harkirat", "Kirat"];
const arr2: Arr[] = [4,6,7,9,3];

// console.log(firstEle([1,2,3,"rmana"])); // problem :- it shoud firstEle of string array only or number array, tsc doesn't infers this
// console.log(firstEle(arr).toUpperCase());   // problem :- tsc is not smart to apply upperCase on arr of Type Arr & also not smart to assume its an string array
console.log(firstEle(arr2));

// solution :- Generics - Generics enable you to create components that work with any data type while still providig compile-time safety.

// same function executing for diff types
console.log(get_first([5,4,6]));
function get_first<T>(arr:T[]) : T {    // T-> refres to any type
    return arr[0];
}

const value = get_first(["kirat", "raman"]);     
console.log(value.toUpperCase());           // now value infers -> string
const value2 = get_first([1,2,3,4]);
console.log(value2);                        // value2 -> number