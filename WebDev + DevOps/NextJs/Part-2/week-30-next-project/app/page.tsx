// "use client"   -> either make this as client component or create seprate Button client component for dynamic things

// server component :- rendered on server
// client component :- pre-rendered on server and rendered again on client. When need to use - useEffect, useState, onClick ... - which server doesn't understand
//                  - mark as client component at top: "use client" 

// RUle of thumb :- defer the client as much as possible (untill we don't need a client component, prefer using server components)

import Button from "@/components/button";
import { ChatBox } from "@/components/ChatBox";

export default function Home() {
  return (
    <div className="min-w-screen h-screen flex flex-col justify-between">
      <div className="">

      </div> 
      <div>
        <ChatBox/>
      </div>
    </div>
  );
}
