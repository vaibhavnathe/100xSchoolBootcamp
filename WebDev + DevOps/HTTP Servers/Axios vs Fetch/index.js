// axios vs fetch
const axios = require("axios");

// Axios

// get request
const call = async() => {
    const res = await axios.get("https://dummy-json.mock.beeceptor.com/todos");
    console.log(res.data);
    console.log(res.data.length);
}

// post request :- change request method
const call2 = async() => {
    const res = await axios.post("https://www.postb.in/1774079253228-0705876252613",
        {
            username : "Harkirat",
            password : "123467"
        }, 
        {
            headers:{
                "Authorization" : "Bearer 123"
            }
        }
        
    );
    console.log(res.data);
}

// call();
call2();


// Fetch

// POST request
const main3 = async() => {
    const res = await fetch("https://www.postb.in/1774079253228-0705876252613", {
        method : "POST",
        headers:{
            "Authosization" : "Bearer 123"
        },
        body: JSON.stringify({
            username: "HKirat",
            password: "123457"
        })
    });
    const data = await res.text();
    console.log(data);
}
// main3();

// get request
const main = () => {
     fetch("https://dummyjson.com/todos")   // fetch returns a promise
     .then(async(response) => {
        const res = await response.json();
        console.log(res.todos.length);
     })
     .catch((err) => {
        console.log("Error:", err);
     })
}

const main2 = async() => {
     const res = await fetch("https://dummy-json.mock.beeceptor.com/todos");   // fetch returns a promise
    const data = await res.json();

    console.log(data.length);
}



// main();
// main2();