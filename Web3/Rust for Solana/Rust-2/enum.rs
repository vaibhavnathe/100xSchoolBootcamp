// define Enums

#[derive(PartialEq)]
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
}

enum Shape{
    Circle(f32),    // variant with associated data (radius)
    Sqaure(f32),    // variant with associated data (side length)
    Rectabgle(f32, f32);    // variant with associated data (length , width)
}

// implementing enums -> attaching fn to the enum
impl Shape{
    fn calculate_area(&self) -> f32 {
        let ans = match self {
            Shape::Circle(radius) => 3.14 * radius * radius,
            Shape::Square(side) => side * side,
            Shape::Rectangle(width, height) => height*width
        }
        return ans;
    }
}

// using pattern matching in enum
fn calculate_area(shape: Shape) -> f32 {
    
    match shape {
        Shape::Circle(radius) => 3.14 * radius * radius,
        Shape::Square(side) => side * side,
        Shape::Rectangle(width, height) => height*width
    }
    
}

// normal way of enum
fn calc_area(shape: Shape) -> f32 {
    if let Shape::Circle(radius) = shape {
        return 3.14 * radius * radius;
    }
    
    if let Shape::Square(side) = shape {
        return  side * side;
    }
    
    if let Shape::Rectangle(width, height) = shape {
        return width * height;
    }
    
    return 0.0;
}

fn main()
{
    // ** Enums :- They allow you to define a type by enumerating its possible variants **

    //Ex.2
    let circle = Shape::Circle(5.0);
    let square = Shape::Square(4.0);
    let rectangle = Shape::Rectangle(3.0,6.0);

    // using impl enum
    println!("Circle Area : {}", circle.calculate_area());
    println!("Sqaure Area : {}", square.calculate_area());
    println!("Rectangle Area : {}", rectangle.calculate_area());

    // usign pattern matchin
    // println!("Circle Area : {}", calculate_area(circle));
    // println!("Sqaure Area : {}", calculate_area(square));
    // println!("Rectangle Area : {}", calculate_area(rectangle));

    //normal way of checking for enum
    // println!("Circle Area : {}", calc_area(circle));
    // println!("Sqaure Area : {}", calc_area(square));
    // println!("Rectangle Area : {}", calc_area(rectangle));
    

    // Ex.1
    // using enum
    // move_away2(Direction::UP);
    // move_away2(Direction::LEFT);
    
    // normal way-
    // move_away(String::from("UP"));
    // move_away(String::from("DOWN"));

}

// using enum :- if input is not from listed in enum , program will not compile
fn move_away2(direction : Direction) {
    if direction == Direction::UP {
        println!("Moved in the Up direction");
    }
    else if direction == Direction::DOWN {
        println!("Moved in the Down direction");
    }
    else if direction == Direction::LEFT {
        println!("Moved in the Left direction");
    }
    else if direction == Direction::RIGHT{
        println!("Moved in the Right direction");
    }
}
// normal way 
fn move_away(direction: String) {
    if direction == "UP" {
        println!("Moved in the Up direction");
    }
    else if direction == "DOWN" {
        println!("Moved in the Down direction");
    }
    else if direction == "LEFT" {
        println!("Moved in the Left direction");
    }
    else if direction == "RIGHT"{
        println!("Moved in the Right direction");
    }
    else {
        panic!("Wrong inputs passed");
    }
}