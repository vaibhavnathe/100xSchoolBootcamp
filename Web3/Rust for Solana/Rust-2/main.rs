
// defining Struct

// #[derive(Debug)]     // to print whole object
struct Address {
    city : String,
    pincode : u32,
    country : String
}

// #[derive(Debug)]

struct User {
    name : String,
    age : u32,
    address : Address,
    
    // more complex type -> ex. user have multiple addresses or marks
    // addresses : Vec<Address>,// [{city : "delhi", pincode : 65232, country : "india"}, {city : "chandigarh", pincode : 65232, country : "india"}]
    // marks : Vec<u32>        // [87,89,92,95]
}

// Implementing structs :- attaching fn's to structs
impl User {
    
    fn can_vote(&self, legal_age:u32) -> bool {        // &self as first argument -> it is non-static function otherwiese static function
        if self.age >= legal_age{
            return true;
        }
        return false;
    }
    
    // by default -> every fn is static
    fn hello() -> String {
        return String::from("USer class Static function");
    }
}

fn main()
{

    // *** Structs :- used to define complex types like objects in Js & interfaces in Ts
    /*
    let user1 = User{
        name : String::from("Harkirat"),
        age : 23,
        address : {
            Address {
                city : String::from("Delhi"),
                pincode : 12354,
                country : String::from("India")
            }
        }
    };
    
    let user2 = User {
        name : String::from("Raman"),
        age : 17,
        address : {
            Address {
                city : String::from("Banglore"),
                pincode : 665654,
                country : String::from("India")
            }
        }
    };
    
    let res1 = is_allowed_to_vote(&user1);  // Borrowing of objects/structs
    let res2 = is_allowed_to_vote(&user2);
    println!("{}", res1);
    println!("{}", res2);
    
    // calling static/class function & non-static function of class User
    println!("{}", user1.can_vote(18));
    println!("{}", user2.can_vote(18));
    println!("{}", User::hello());
    
    println!("{}", user1.name);
    println!("{}", user2.name);
    // println!("{:?}", user1);        // using macros -> #[derive[Debug]]
    */
    

    // Privious class -> revise
    /*
    let s: String = String::from("Harkirat");
    let num: usize = 7;
    
    let res = is_longer_than(&s, num);
    
    println!("{}", res);
    println!("{}", s);
    */
}

fn is_allowed_to_vote(u: &User) -> bool {
    // return u.age >= 18;
    
    if u.age >= 18 {
        return true
    }
    false   // or return false -> can write both false / return false ate the end.
    
    
}

fn is_longer_than(s:&String, num: usize) -> bool{
    return s.len() > num;
} 