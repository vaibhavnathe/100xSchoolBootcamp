"use client"

import axios from "axios";
import { useEffect, useState } from "react";

//Normal React Way of fetching data:- Normal communication between client-server -   client request & server responds
// Then whats feature of NextJs :- Server-side rendering (on the first go, it should render user data)

export default function UserCard(){

    const [user, setUser] = useState({});
    const url = "https://week-13-offline.kirattechnologies.workers.dev/api/v1/user/details";

    useEffect(() => {
        axios.get(url).then(response => {
            setUser(response.data);
        })
    }, [])

    if(!user.name){
        return <div>
            Loading ...
        </div>
    }

    return (
        <div className="flex justify-center items-center h-screen w-screen">
            <div className="p-5 bg-gray-600 text-white border-2 rounded-2xl">
                {user.name}
                <br />
                {user.email}
                <br />
                {user.address?.city}
            </div>
        </div>
    )
}