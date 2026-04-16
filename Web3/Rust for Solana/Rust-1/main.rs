
// Mutability :- By default, all varibles are immutable in rust
//             - Can make mutable by using 'mut'

fn main(){

    // js/java -> slow, because of garbage collector
    // c/c++ -> not memory safe- because of manual allocation & deallocation of memory
    // rust -> diff approach - Ownership :- whenever a value pass to another fun or anything -> the ownership get transfer to new owner
    //                                   - a var/value can have only one owner

    // mutability :- by default all variables are immutable in rust, can make mutable using 'mut'
    let mut x = 54;
    x = 10;
    println!("{}", x);
    
    let mut s: String = String::from("Hello");
    println!("{}", s);
    // s = String::from("Hello World");
    s.push_str(&String::from(" World"));
    println!("{}", s);

    // loops
    let mut ans = 0;
    for i in 1..10{
        ans += i; 
    }
    println!(ans);

    // loop -> type of loop
    /*
    loop {
        if {
            break;
        }
    }
    
    // while loop
    // while(true){
        
    // }
    */

    // functions
    let ans = do_sum(2,3);
    println("{}", ans);

    // Data types :- rust has strict typed language

    //5. Vectors :- not easy - not-fixed size
    let mut vec: Vec<i32> = vec![1,2,3,4,5];    // mut-mutable , size can change
    vec.push(10);
    vec.push(20);
    // println!("{}", vec[0]); // printing 1 ele
    // println!("{:?}", vec);  // printing whole vector

    //4. Arrays :- Easy - fixed size
    // let arr:[i32; 5] = [1,2,3,4,5];
    // println!("{}", arr.len());

    //3. Strings :- not easy- intersting size of string can change during program
    /*
    let mut greeting: String = String::from("hello world");
    greeting.push_str(&String::from(" harkirat"));
    println!("{}", greeting);
    */

    /* 
    // 1. Integers/Numbers :- easy - fixed size
    let x:i32 = 1;  // 32bits, i-signed(can store both +,-) , u-unsigned(only store +) 
    let y:i64 = 12; // 64 bits
    let z:u128 = 100;// 128 bits 
    println!("{}-----{}", x,x);
    println!("{}", y);
    println!("{}", z);
    */

    /*
    // 2. Boolean :- easy - fixed size
    let is_male = false;
    let is_above_18: bool = true;
    println!("{}", is_male);
    
    if is_male{     // rust prefers snake-case (is_male), not camel-case (isMale)
        println!("You are male");
    }
    else{
        println!("You are female");
    }
    
    if is_male && is_above_18{
        println!("You are legal male");
    }
        */  

    // println! -> This is not function call, its macro-invocation call
    // println!("Heelo Wolrd1");
    
}

// functions
pub fn do_sum(a: i32, b:i32){
    return a+b;
}

fn get_len(str2: String) -> usize {
    return str2.len();
}