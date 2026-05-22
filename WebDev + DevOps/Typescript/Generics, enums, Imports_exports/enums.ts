// Enums (enumerations) - In ts enums are the feautre that allows you to define a set of named constants
//                      - The concept behind enums is to create a human-readable way to represent a set of constant values



// common use in express server
enum ResponseStatus{
    Success = 200,
    NotFound = 404,// if status code get wrong, need to change - we can change direclty from here , no need to go to each response
    Error = 500
}

// app.get("/", (req, res) => {
//     if(!req.query.userId){
//         res.status(ResponseStatus.Error).json({});
//     }
//     // and so on...
//     res.status(ResponseStatus.Success).json({});
// })

app.get("/something", (req, res) => {
    if(!req.query.userId){
        res.status(ResponseStatus.NotFound).json({});
    }
    // and so on...
    res.status(ResponseStatus.NotFound).json({});
})


//one way:-using type, without enum
type key = "Up" | "Down" | "Left" | "Right";

// best way :- using enums
enum Direction {
    Up,     // 0
    Down,   // 1
    Left,   // 2
    Right   // 3
}

function doSomething(keyPressed: Direction) {    // keyPressed: string (tsc won't give an error), keyPressed: key type (one way to do it), keyPressed : Direction(best way)
    // do something based on keyPressed
    if(keyPressed == Direction.Up){
        // logic
    }
}

doSomething(Direction.Up);
doSomething(Direction.Down);
doSomething(Direction.Left);
doSomething(Direction.Right);

console.log(Direction.Up);      // 0
console.log(Direction.Left);   // 2

// the final value stored at run time is still a number (0,1,2,3)
// if want to make as string instead of number make it like 
// enum Direction {
//     Up = "Up",     
//     Down = "Down", 
//     Left = "Left",
//     Right = "Right"
// }

// doSomething("Up");
// doSomething("Down");
// doSomething("kjnfjnjnf");   //for type string- ts will not give any error, woudn't be nice thet ts tell instantly there is bug here
                            // can be done in 2 ways :- type & enums



