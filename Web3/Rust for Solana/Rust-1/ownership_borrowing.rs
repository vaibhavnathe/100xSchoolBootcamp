// Ownership Rules:- Ownership of heap variables
                // i)  Each value in Rust has an owner.
                // ii) There cab only be one owner at a time.
                ///iii) When the owner goes out of Scope, the value will be dropped.

// Borrowing :- - In Rust, borrowing is the mechanism of accessing data without taking ownership of it. 
//              - Instead of transferring ownership (moving) a variable, you create a reference to it, 
//                allowing another part of the code to use the data temporarily before returning control to the original owner.
//              - You can let function borrow the variable

// Borrowing Rules :- i) You can only have one mutable reference(ex. str1 is only mutable in main fn). 
//                      - If there is mutable reference, there can't be other immutable or mutable references
//                      - many immutable borrows if there are no other mutable borrows. 
//                    ii) You can have multiple immutable references
fn main()
{
    let mut str1: String = String::from("Harkirat");
    
    // cloning :- avoiding ownership tranfer - directly passing copy of current value
    // let ch = get_first(str1.clone());   //passing copy (expensive) -> rather than this, just borrow it
    let ch = get_first(&str1);
    println!("char : {}", ch);

    // sol2 (good) :- Using borrowing - not moving full ownership, insted of it give/pass it as reference 
    //                                - Onwer still be the original one, another var (by copy wala) just borrowing for specific time  
    let s = &mut str1;      // first mutable borrow
    let len1 = get_len(s);
    let len2 = get_len2(&str1);   // by passing it as reference
    let len3 = get_len(&mut str1);   //'&' by passing it as reference & 'mut'- str1 can be changable in get_len fn

    // println!("{}", s);  // s is still alive here & above multplie borrows happened -> error - no more multiple borrows if we have one mutable borrow
    println!("{}", len2);
    println!("{}", len3);

    // sol1 (Not good sol) :- transfering ownership back to main fn, the fn returning the value back to original fun
    let (len, str2) = get_len2(str1);    // ownership of "Harkirat" transfer/moved from str1 to str2
    println!("{}", str2);       // ownership tranfer back to to str2, by returnig the same string back here
    println!("{}", len);

    // ownership-> 
    // let len = get_len(str1);    // ownership of "Harkirat" transfer/moved from str1 to str2
    // println!("{}", str1);       // can't access str1
    // println!("{}", len);

   

}


fn get_len(str2: &mut String) -> usize {
    str2.push_str(&String::from(" Singh"));
    return str2.len();  // &str2 - owner is still str1 in main fn, here just borrowing it for some tim
}

fn get_len2(str2: String) -> (usize, String) {
    return s(tr2.len(), str2);  // again we returning/passing ownership back to original fn
}

fn get_firfst(str: String) -> char {
    let x = str.chars().nth(0).unwrap();
    return x;
}