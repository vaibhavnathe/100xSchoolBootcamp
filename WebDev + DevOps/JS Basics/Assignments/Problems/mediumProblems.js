/*7. Write a function `reverseInteger` which takes an integer as input and returns the integer with its digits reversed. If the input is negative, the reversed integer should also be negative.
 Input: 123 - Output: 321 
 - Input: -456 - Output: -654 */
 /*
function reverseInteger(num){
    let rev = 0;
    let sign = num < 0 ? -1 : 1;
    num = Math.abs(num);

    while(num != 0){
        rev = (rev*10) + (num%10);
        num = Math.floor(num / 10);
    }
    return rev*sign;
}
let num = 123;
console.log(reverseInteger(num));
*/


/*6.Write a function `getPrimesUpTo100` which returns an array of all prime numbers up to 100.*/
/*
function getPrimesUpTo100(){
    let res = [];
    for(let i=1; i<=100; i++){
        if(isPrime(i)){
            res.push(i);
        }
    }
    return res;
}
function isPrime(num){
    if(num <= 1 ){return false;}
    for(let i=2; i<=Math.sqrt(num); i++){
        if(num%i == 0){
            return false;
        }
    }

    return true;
}
console.log(getPrimesUpTo100());
*/


/* 5. Write a function `nonrepeat` which takes a string as input and returns the first non-repeating character in the string.
  - Input: "abcab" - Output: "c" */
/*
function nonRepeat(str){
    let res = {};
    for(let i=0; i<str.length; i++){
        if(res[str[i]]){
            res[str[i]]++
        }
        else{
            res[str[i]] = 1;
        }
    }
    for(let ch in res){
        if(res[ch] == 1){
            return ch;
        }
    }
    return null;
}
const str = "aabbcde";
console.log(nonRepeat(str))
*/


/* 4.Write a function `isPerfectNumber` which takes an integer `num` as input and returns a boolean indicating whether the number is a perfect number.
Input: 6 - Output: true , Explanation: The divisors of 6 are 1, 2, and 3. 1 + 2 + 3 = 6, so 6 is a perfect number.*/
/*
function isPerfectNumber(num){
    let sum = 0;
    for(let i=1; i<num; i++){
        if(num%i == 0){
            sum += i;
        }
    }

    return num==sum;
}
let num = 28;
console.log(isPerfectNumber(num));
*/


/*3. Write a function `findDuplicates` which takes an array as input and returns an array containing all the duplicate elements.
input: [10, 20, 30, 10, 40] , Output: [10]*/
/*
function findDuplicates(nums){
    let res = [];
    for(let i=0; i<nums.length; i++){
        let isDuplicate = false;
        for(let j=i+1; j<nums.length; j++){
            if(nums[i] == nums[j]){
                isDuplicate = true;
            }
        }

        if(isDuplicate){
            res.push(nums[i]);
        }
    }
    return res;
}
const nums = [10, 20, 30,20, 10, 40];
console.log(findDuplicates(nums));
*/


/* 2.  Write a function that calculates the time (in seconds) it takes for the JS code to calculate sum from 1 to n, given n as the input.
Try running it for , 1. Sum from 1-100
                    2. Sum from 1-100000
                    3. Sum from 1-1000000000 */
/*
function calculateTime(n){

    // using performance function
    let t1 = performance.now();
    let sum = 0;
    for(let i=1; i<=n; i++){
        sum += i;
    }
    let t2 = performance.now();

    return (t2-t1)/1000;

    // using date function 

    // let date = new Date();
    // let before = date.getSeconds();

    // let sum = 0;
    // for(let i=1; i<=n; i++){
    //     sum += i;
    // }
    // let date2 = new Date();
    // let after = date2.getSeconds();

    // return after-before; 
}
let n = 1000000000;
console.log(calculateTime(n));
*/



/* 1. Implement a function `isPalindrome` which takes a string as argument and returns true/false as its result.
Note: the input string is case-insensitive which means 'Nan' is a palindrom as 'N' and 'n' are considered case-insensitive.*/
/*
function isPalindrome(str){

    return str.toLowerCase() == str.toLowerCase().split('').reverse().join('');
    // using logic
    
    // let str2 = str.toLowerCase();
    // let i=0;
    // let j=str2.length-1;
    // while(i<=j){
    //     if(str2[i++] != str2[j--]){
    //         return false;
    //     }
    // }
    // return true;
    *
}
let str = "RaceCar";
console.log(isPalindrome(str));
*/