"use client"
import axios from "axios";
import { useRouter } from "next/navigation";
import { useState } from "react"

export const ChatBox = () => {

    const [message, setMessage] = useState("");
    const router = useRouter();

    return <div className="">
        <input type="text" placeholder="Start typing..." className="w-300 m-5 p-5 border rounded-2xl"
            onChange={(e) => setMessage(e.target.value)}
        />


        <button className="ml-5 mb-5 p-5 bg-black text-white rounded-2xl cursor-pointer border-2 hover:bg-gray-300 hover:text-black "
            onClick={async () => {
                const response = await axios.post("/conversation", {
                    initialPrompt: message
                })
                router.push(`conversation/${response.data.id}`);
                alert("Your new conversation has been created " + response.data.id)
            }}
        >
            Send
        </button>
    </div>
}