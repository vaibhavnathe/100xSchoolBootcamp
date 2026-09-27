"use client";
import axios from "axios";
import { useSession } from "next-auth/react";
import { signOut, signIn } from "next-auth/react";
import { useEffect } from "react";

export default function Home() {

  const { data: session, status } = useSession();

  useEffect(() => {
      axios.post(`/api/todo`, {})
      .then(res => {
        console.log(res.data);
      })
  },[])

  return (
    <div className="flex flex-col flex-1 items-center justify-center bg-zinc-50 font-sans dark:bg-black">
     <h1>Your Friendly neighbourhood Todo App</h1>

    {status === "authenticated" ? (
      <div>
        
        <h2>
          hi {session.user?.email}
          
        </h2>
        <button onClick={() => signOut()} 
                className="bg-white text-black p-2 m-2 rounded-2xl cursor-pointer hover:bg-gray-600 hover:text-white">
          Logout
          </button>
      </div>
    ) : (
      <div>
        <button  className="bg-white text-black p-2 m-2 rounded-2xl cursor-pointer hover:bg-gray-600 hover:text-white"
          onClick={() => signIn()}  
        >
          Signup
          </button>
        <button  className="bg-white text-black p-2 m-2 rounded-2xl cursor-pointer hover:bg-gray-600 hover:text-white"
        onClick={() => signIn()}>
          SignIn
          </button>
      </div>
    )}
    
    </div>
  );
}
