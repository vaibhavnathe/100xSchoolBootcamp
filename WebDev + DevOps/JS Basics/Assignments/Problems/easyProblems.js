// 12. Count number of keys in object : i/p:- { a: 1, b: 2, c: 3 }
//                                      o/p:- 3
// /*
function findLength(list){
    //using in-built object function
    let len = Object.keys(list).length;

    // let len = 0;
    // for(let key in list){
    //     len++;
    // }
    return len;
}
const list = { 
    a: 1, 
    b: 2, 
    c: 3 ,
    d:4
};
console.log(findLength(list));
// */

// 11. Sort object entries by values (ascending). i/p:- { a: 3, b: 1, c: 2 }
//                                      o/p:- [["b",1], ["c",2], ["a",3]]
/*
function sortObjByValue(list){
    const entries = Object.entries(list);
    const res = entries.sort((a,b) => a[1]-b[1]);
    
    return res;
}

const list = { 
    a: 3, 
    b: 1, 
    c: 2 
};
console.log(sortObjByValue(list));
*/

// 10. Pick only given keys from object. i/p:- { name: "Rahul", age: 23, city: "Noida" }, ["name","city"]
//                                      o/p:- { name: "Rahul", city: "Noida" }
/*
function pickOnlyGivenKeys(user, keys){
    let res = {};
    for(let key in user){
        if(keys.includes(key)){
            res[key] = user[key];
        }
    }
    return res;
}
const user = {
    name:"Rahul",
    age : 23,
    city : "Noida"
};
const keys = ["name","city"];
console.log(pickOnlyGivenKeys(user, keys));
*/
 
 // 9. Unique values across all object arrays :- i/p: { x: [1,2,3], y: [2,3,4], z: [4,5] }
 //                                              o/p: [1,2,3,4,5]
 /*
function findUnique(obj){

    let res = [];
    for(let key in obj){
        for(let i=0; i<obj[key].length; i++){
            if(!res.includes(obj[key][i])){
                res.push(obj[key][i]);
            }
        }
    }
    return res;

    /* using set
    let set = new Set();
    
    for(let key in obj){
        for(let i=0; i<obj[key].length; i++){
            set.add(obj[key][i]);
        }
    }
    return set;
}
 const obj = { 
    x: [1,2,3], 
    y: [2,3,4], 
    z: [4,5] 
};
console.log(findUnique(obj));
*/

// 8. Find student with highest average mark :- i/p: { A: [80, 90], B: [70, 75, 85] }
//                                              o/p: A
/*
function highestAvg(students){
    let res;
    let highAvg = 0;
    for(let student in students){
        let sum = 0;
        for(let i=0; i<students[student].length; i++){
            sum += students[student][i];
        }
        let avg = sum/students[student].length;
        if(avg > highAvg){
            highAvg = avg;
            res = student;
        }
    }
    return res;
}
const students = { 
    A: [80, 90], 
    B: [70, 75, 85] 
};
console.log(highestAvg(students));
*/

// 7. Filter object by values > 50 :- i/p: { a: 20, b: 60, c: 40, d: 90 }
//                                    o/p: { b: 60, d: 90 }
/*
function filterValue(obj){
    let res = {};
    
    for(let key in obj){
        if(obj[key] > 50){
            res[key] = obj[key];
        }
    }
    return res;
}
const obj = { 
    a: 20,
    b: 60, 
    c: 40, 
    d: 90 
}
console.log(filterValue(obj));
*/

// 6. Group people by city. i/p:- [{ name: "A", city: "Delhi" },{ name: "B", city: "Mumbai" },{ name: "C", city: "Delhi" }]
//                          o/p:- { Delhi: ["A", "C"], Mumbai: ["B"] }
/*
function groupPeopleByCity(peoples){
    let res = {};
    for(let i=0; i<peoples.length; i++){
        if(res[peoples[i].city]){
            res[peoples[i].city].push(peoples[i].name);
        }
        else{
            res[peoples[i].city] = [peoples[i].name];
        }
    }
    return res;
}
const peoples = [
  { name: "A", city: "Delhi" },
  { name: "B", city: "Mumbai" },
  { name: "C", city: "Delhi" }
];
console.log(groupPeopleByCity(peoples));
*/

// 5. Flatten object of arrays into one array. i/p:- { fruits: ["apple", "banana"], veggies: ["carrot", "pea"] }
//                                             o/p:- ["apple", "banana", "carrot", "pea"]
/*
function makeArray(obj){
    let res = [];
    for(let key in obj){
        for(let i=0; i<obj[key].length; i++){
            res.push(obj[key][i]);
        }
    }

    return res;
}
const obj = { 
    fruits: ["apple", "banana"], 
    veggies: ["carrot", "pea"]
}
console.log(makeArray(obj));
*/

// 4. Find the largest value key :- i/p- { a: 10, b: 50, c: 20 }
//                                  o/p- b
/*
function findMaxValueKey(chars){
    let maxKey;
    let maxValue = 0;
    for(let key in chars){
        if(chars[key] > maxValue){
            maxValue = chars[key];
            maxKey = key;
        }
    }
    return maxKey;
}
const chars = { a: 10, b: 50, c: 20 };
console.log(findMaxValueKey(chars));
*/


// 3. Swap keys and values of object : - Input:    { a: "x", b: "y", c: "z" }
//                                       output: { x: "a", y: "b", z: "c" }
/*
function  swapKeyValues(letters){

    let res = {};
    for(let key in letters){
        res[letters[key]] = key;
    }

    return letters;
}

const letters = { a: "x", b: "y", c: "z" };
console.log(swapKeyValues(letters));
*/


// 2. Count word occurrences in array : i/p :- ["apple", "banana", "apple", "orange", "banana", "apple"]
//                                      o/p :- { apple: 3, banana: 2, orange: 1 }
/*
function countOccurences(fruits){
    let res = {};
    for(let i=0; i<fruits.length; i++){
        if(res[fruits[i]]){
            res[fruits[i]]++;
        }
        else{
            res[fruits[i]] = 1;
        }
    }
    return res;

}
const fruits = ["apple", "banana", "apple", "orange", "banana", "apple"];
console.log(countOccurences(fruits));
*/

// 1. Sum values in object arrays -> i/p :- { food: [10, 20, 30], travel: [5, 15], bills: [40, 60] }
                                   // o/p :-  {food: 60, travel: 20, bills: 100 }
/*
function totalExpense(expense){

    // using reduce function
    let res = {};
    for(let key in expense){
        res[key] = expense[key].reduce((acc, val) => acc + val, 0);
    }
    return res;

    // using loops
 
    for(let key in expense){
        let sum = 0;
        for(let i=0; i<expense[key].length; i++){
            sum += expense[key][i];
        }
        expense[key] = sum;
    }
    return expense;
    
}

let expense = { 
    food: [10, 20, 30], 
    travel: [5, 15], 
    bills: [40, 60] 
}
console.log(totalExpense(expense));
*/