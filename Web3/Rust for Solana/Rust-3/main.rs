use std::fs;

enum Shape{
    Rect(u32, u32),
    Sqaure(u32),
    Circle(u32)
}

//comes built-in with compiler, Can directly use, no need to write like this
enum Result<T,E> {// Result enum with variants
    Ok(T),
    Err(E)
}

//comes built-in with compiler, Can directly use, no need to write like this
enum Option<T> {    // Option enum with variants
    Some(T), 
    None
}


fn main()
{

    // **** Option Enum -> to handle the nullbility, built-in type used to represent a value that might be either present or absent. 
    // /*
    let index_res_ = find_first_index(String::from("hkirat"));  // return Option enum
    match index_res_ {
        Some(index) => {
            println!("first a is found at index {}", index);
        }
        None => {
            println!("Char not found in the given string");
        }
    }
        // */

    //******  Error HR  andling in Rust -> using result enums (used for error handling for the code which is dangerous/throw an error)
    
    // **** unwrap & its variant like unwrap_or
    /*
    let file_content2 = fs::read_to_string("test.txt").unwrap_or(String::from("file does not exist"));   // either file_content get print or it will print other string(file does not exist)
    println!("{}", file_content2);
    
    let file_content = fs::read_to_string("hello.txt").unwrap();    // unwrap -> if got success- it will get content otherwise it will panic(execution stoppe)
    println!("{}", file_content);   // unwrap -> either panic or get file content
    */
    
    // function to read file
    /*
    let res = read_from_file(String::from("hello.txt"));
    println!("{}", res);
    */
    
    
    /*
    let file_res = fs::read_to_string("./hello.txt");   // Will return result which is -> Result enum
    // Pattern matching - printing values
    match file_res{
        Ok(content) => {
            println!("{}", content);
        }
        
        Err(err) => {
            println!("Error while reading file {}",err);
        }
    }
    */
    
    
}

// it should not return -1(i32) , its for our understanding but ideally
// it should return something -> Option enum : either null or index
fn find_first_index(s:String) -> Option<u32> {  //returning either i32 || none
    
    for (index, ch) in s.chars().enumerate(){
        if ch == 'a' {
            return Some(index as u32);  // some variant of Option enum
        }
    }
    
    return None;    // or Option::None
    // return -1;  // to show nullability -> if char is not present in string
}


fn read_from_file(path: String) -> String {
    
    let enum_file_res = fs::read_to_string(path);   // will return Result<String, Error> enum
    
    match enum_file_res {
        Ok(content) => {
            return content;
        }
        Err(err) => {
            return String::from("Error while reading file");
            
            // panic!("Errr while reading file");      // should not panic, it should return err variant of enum
        }
    }
}