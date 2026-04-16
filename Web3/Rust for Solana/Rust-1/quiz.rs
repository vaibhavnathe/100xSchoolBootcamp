
//Q] Will the code compile? 

fn main()
{
    //3] yes, it will compile -> ref1 (mutable borrow) will get done by line 9, and afer ref2 only accessing ref2 , that's why
    let mut str = String::from("Harkirat");
    let ref1 = &mut str;
    ref1.push_str(" Singh");
    let ref2 = &str;

    println!("{}", ref2);
    // println!("{}", ref1);   // will throw error :- if we acess ref1 here => error- because ref1(mutable borrow) is accessing here while ref2 also borrowin in above line -> only mutable borrow at a time

    //2] No, it won't compile -> only one mutable borrow at a time, no other mutable or immutable borrow
    /*
    let mut str = String::from("Harkirat");
    let ref1 = &mut str;
    let ref2 = &str;

    println!("{} {}", ref1, ref2);
    */

    // 1] yes, it will compile -> multiple immutable refereence
    /*
    let str = String::from("Harkirat");
    let ref1 = &str;
    let ref2 = &str;

    println!("{} {}", ref1, ref2);
    */
}

