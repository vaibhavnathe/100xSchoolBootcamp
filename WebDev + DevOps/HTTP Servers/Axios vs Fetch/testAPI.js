
const axios = require("axios");

const callApi = async() => {
    // const res = await axios.post("https://httpdump.app/dumps/f9906b5b-71ed-4177-bc9e-de4107bfc35b", 
    //     {
    //         username : "HKirat",
    //         passowrd : "123"
    //     },
    //     {
    //         headers: {
    //             "Authorization" : "Bearer 123"
    //         }
    //     }
    // )

    // we can write like this
    const res = await axios(  
        {
            url : "https://httpdump.app/dumps/f9906b5b-71ed-4177-bc9e-de4107bfc35b",
            method : "PUT",
            headers: {
                "Authorization" : "Bearer 123"
            },
            data:{
                username : "VN",
                password : "vn123"
            }
        }
    )

    console.log(res.data);
}

callApi();