

// NextJS Way :- Server-side rendering

import axios from "axios"

export default async function UserCard2() {

    // This directly runs on NextJs Server not on clint browser & then send it to client browser
    const url = "https://week-13-offline.kirattechnologies.workers.dev/api/v1/user/details";
    const respponse = await axios.get(url);
    const data = respponse.data;

    // Untill we recieve data -> the page will not show anything like loading => add loading.tsx to usercard2 directory
    //  After adding -> now untill receive data , page will show loading.tsx

    return (
       <div className="flex justify-center items-center h-screen w-screen">
            <div className="p-5 bg-gray-600 text-white border-2 rounded-2xl">
                {data.name}
                <br />
                {data.email}
                <br />
                {data.address?.city}
            </div>
        </div>
    )
}