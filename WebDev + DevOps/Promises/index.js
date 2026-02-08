// Coding Rule : DRY -> Dont't Repeat Yourself

// Inheritance - One class inherit the properties of another class.
//             - Code Reusability

class Shape{
    constructor(color){
        this.color = color;
    }

    paint(){
         console.log(`Painting with color ${this.color}`);
    }

    area(){
        throw new Error("The area method must be implemented in the subclasses.")
    }
}

class Rectangle extends Shape{

    constructor(width, height, color){
        super(color);       // calling parent (shape) class constructor
        this.width = width;
        this.height = height;
    }

    area(){
        const area = this.width * this.height;
        return area;
    }

    perimeter(){
        const perimeter = 2 * (this.width + this.height);
        return perimeter;
    }
}

class Circle extends Shape{
    constructor(radius, color){
        super(color);       // calling parent (shape) class constructor
        this.radius = radius;
    }

    area(){
        return 3.14 * this.radius * this.radius;
    }

    perimeter(){
        return 2 * 3.14 * this.radius;
    }   
}

class Square extends Shape{
    constructor(side, color){
        super(color);       // calling parent (shape) class constructor
        this.side = side;
    }

    area(){
        return this.side * this.side;
    }

    perimeter(){
        return 4 * this.side;
    }
}

const r1 = new Rectangle(10,20, "red");
const c1 = new Circle(25, "yellow");
const s1 = new Square(50, "blue");
console.log(r1.area());
console.log(c1.area());
console.log(s1.area());
s1.paint();
r1.paint();
c1.paint();


// Js built-in classes -> Date 
/**
const d = new Date();
console.log(d.getDay());
console.log(d.getMonth());
console.log(d.getFullYear());
*/


/** 
// Classes , Objects
class Rectangle{
    // constructor
    constructor(width, height, color){
        this.width = width;
        this.height = height;
        this.color = color;
    }

    // static method :- function that belongs to the class itself, rather than to any specific instance (object) of that class. 
    //                  Called on the class directly: ex. Rectabgle.whoami
    static whoami(){
        return "I am a rectangle";
    }

    area(){
        const area = this.width * this.height;
        return area;
    }

    perimeter(){
        const perimeter = 2 * (this.width + this.height);
        return perimeter;
    }

    paint(){
        console.log(`Painting with color ${this.color}`);
    }
}
const r1 = new Rectangle(10,20, "red");
console.log(r1);
console.log(r1.area());
console.log(r1.perimeter());

console.log(Rectangle.whoami());     // calling a static method using directly class
*/


/*
// Primitives
let num = 6;
let str = "Hello";
let isTrue = true;


// Complex Types
let user = {
    name : "HKirat", 
    age : 24,
    gender : "Male",
    cities : ["delhi", "chandigarh", "mumbai"]
}
console.log(user.name);
console.log(user.cities);
console.log(user.cities[0]);

*/