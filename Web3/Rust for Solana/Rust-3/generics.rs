struct User{
    name: String,
    age: u32
}

// instead of defining structs for deff types -> use generic

struct Rect<T>{
    width: T,
    height: T
}

// struct Rect {
//     width: u32,
//     height: u32
// }
// struct Rect {
//     width: f32,
//     height: f32
// }
// struct Rect {
//     width: i32,
//     height: i32
// }

// generic on enum
enum Shape<T>{
    Circle(T),
    Rect(T, T),
    Square(T),
}

// enum Shape{
//     Circle(u32),
//     Rect(u32, u32),
//     Square(u32),
// }

// enum Shape<i32>{
//     Circle(i32),
//     Rect(i32, i32),
//     Square(i32),
// }

fn main() 
{
    
    // ******** Generics :- abstract placeholders that allow you to write code—such as functions, structs, enums, and traits—that can operate on many different concrete data types without code duplication

    // note -> it means vec<i32> is also struct which takes generic

    // generics on enums
    let s1 = Shape::Circle(5);
    let s2 = Shape::Rect(6.0, 4.0);

    // ** generics on structs & fields of struct
    let r1 = Rect{width: 30, height:40};    // r1 type -> Rect<i32>
    let r2 = Rect{width: 10.2, height:20};  // r2 type -> Rect<f32>


    // ** generics on vectors
    /*
     let v = vec![10,20,30];
    let v2 = vec![String::from("Harkirat"), String::from("Singh")];
    let v3 = vec![11.2,12.4,20.5];
    let v4 = vec![User{name: String::from("Kirat"), age: 23}, User{name: String::from("Raama"), age: 25}];
    
    println!("{}", get_first_ele(v));
    println!("{}", get_first_ele(v2));
    println!("{}", get_first_ele(v3));
    println!("{}", get_first_ele(v4).name);
    */

    // ** generics on numbers types
    // let res = mult_u32(2,4);
    // let res2 = mult_i32(3,5);
    // let res3 = mult_f32(6.0,8.0);
    
    // let res = mult_generic(4,6);
    // let res2 = mult_generic(4.0,7.0);
    // println!("{}", res);
    // println!("{}", res2);
}

// instead of writing diff fn for same body - can use Generics
fn get_first_ele<T> (v: Vec<T>) -> T {
    return v.into_iter().nth(0).unwrap();
}

// repeated logic in all three functions
fn get_first_ele_num(v: Vec<i32>) -> i32 {
    // return v.iter().nth(0);    // will return an Option<i32> enum
    return v.into_iter().nth(0).unwrap();
}
fn get_first_ele_str(v: Vec<String>) -> String{
    // return v.iter().nth(0);    // will return an Option<i32> enum
    return v.into_iter().nth(0).unwrap();
}
fn get_first_ele_float(v: Vec<f32>) -> f32 {
    // return v.iter().nth(0);    // will return an Option<i32> enum
    return v.into_iter().nth(0).unwrap(); 
}


// instead of writing diff fn for same body - can use Generics
fn mult_generic<T: std::ops::Mul<Output = T>>(a: T, b:T) -> T { // a,b & return type is generic or same
    return a*b;
}

fn mult_u32(a:u32, b:u32) -> u32 {
    return a*b;
}

fn mult_i32(a: i32, b:i32) -> i32 {
    return a*b;
}

fn mult_f32(a: f32, b:f32) -> f32 {
    return a*b;
}
