/*8. Write a function `findLargestElement` that takes an array of numbers and returns the largest element.
  - Input: [3, 7, 2, 9, 1]
  - Output: 9
*/
function findLargest(numbers){
    let max = numbers[0];
    for(let i=1; i<numbers.length; i++){
        if(numbers[i] > max){
            max = numbers[i];
        }
    }
    return max;
}
const numbers = [3, 7, 2, 9, 1];
console.log(findLargest(numbers));

/*7.  Implement a function `calculateTotalSpentByCategory` which takes a list of transactions as parameter and return a list of objects where each object is unique category-wise and has total price spent as its value
Transaction - an object like { itemName, category, price, timestamp }.
  Output - [{ category1 - total_amount_spent_on_category1 }, { category2 - total_amount_spent_on_category2 }]*/
/*
function calculateTotalSpentByCategory(transactions){
    let res = {};
    for(let i=0; i<transactions.length; i++){
        let category = transactions[i].category;
        let price = transactions[i].price;  

        if(res[category]){
            res[category] += price;
        }else{
            res[category] = price;
        }
    }
    return res;
}
const transactions = [
  { itemName: "Burger", category: "Food", price: 200, timestamp: 1 },
  { itemName: "Pizza", category: "Food", price: 300, timestamp: 2 },
  { itemName: "Bus Ticket", category: "Travel", price: 50, timestamp: 3 },
  { itemName: "Movie", category: "Entertainment", price: 150, timestamp: 4 }
];
const res = calculateTotalSpentByCategory(transactions);
console.log(res);
*/


/*6. Write a function `isAnagram` which takes 2 parameters and returns true/false if those are anagrams or not.
  What's Anagram -> A word, phrase, or name formed by rearranging the letters of another, such as spar, formed from rasp.*/
/*
function isAnagram(str1, str2){

    return sortString(str1) == sortString(str2);
} 
function sortString(str){
    return str.toLowerCase().split('').sort().join('');
}
let str1 = "spar";
let str2 = "rasp";
console.log(isAnagram(str1, str2));
*/


/*5. Write a function `reve` which takes a string as input and returns the reversed version of the string.
  - Input: "Sumana"
  - Output: "anamuS"
function reverse(str){

    return str.split('').reverse().join('');

    // using logic
    const arr = str.split('');
    let i=0;
    let j=arr.length-1;
    while(i<=j){
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    str = arr.join('');
    return str;
    
}
const str = "Sumana";
console.log(reverse(str));
*/

/*4. Write two functions to generate the Fibonacci sequence: Input: 10
                                                            - Output (Iterative): [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
                                                            - Output (Recursive): 34

function fiboReccursive(n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fiboReccursive(n-1) + fiboReccursive(n-2);  
}

function fiboIterative(num){
    let res = [];
    res.push(0);
    res.push(1);
    for(let i=2; i<num; i++){
        res[i] = res[i-1] + res[i-2];
    }
    return res;
}
let num = 10;
console.log(fiboIterative(num));
console.log(fiboReccursive(num-1));
*/


/*3. Write a function `countVowels` which takes a string as input and returns the count of vowels (both uppercase and lowercase) in the string.
Input: "hello world" - Output: 3 
function countVowels(str){
    let count = 0;
    let str2 = str.toLowerCase();
    // console.log(str2);
    for(let i=0; i<str2.length; i++){
        if(str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u'){
            count++;
        }
    }
    return count;
}
const str = "hello world";
console.log(countVowels(str));
*/


/*2. Write a function `countOccurrences` which takes an array as input and returns an object representing the frequency of each element in the array.
// - Input: [10, 20, 10, 30, 20, 20]
  - Output: { 10: 2, 20: 3, 30: 1 }
function countOccurences(arr){
    let res = {};
    for(let i=0; i<arr.length; i++){
        if(res[arr[i]]){
            res[arr[i]]++;
        }else{
            res[arr[i]] = 1;
        }
    }
    return res;
}
const arr = [10, 20, 10, 30, 20, 20];
console.log(countOccurences(arr));
*/

/* 1. Write a function `countCharacters` which takes a string as input and returns an object representing the frequency of each character in the string.
Example:
  - Input: "hello"
  - Output: { h: 1, e: 1, l: 2, o: 1 } 
function countCharacters(str){
    let res = {};
    for(let i=0; i<str.length; i++){
        if(res[str[i]]){
            res[str[i]]++;
        }
        else{
            res[str[i]] = 1;
        }
    }
    return res;
}
let str = "hello";
console.log(countCharacters(str));
*/