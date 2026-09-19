
import { prisma } from "@/lib/db";

export default async function ({params}) {

    // const params = useParams<{ conversationId: string; }>()
    const realParams = await params;
    const conversationId = realParams.conversationId;

    const messages = await prisma.message.findMany({
        where: {
            conversationId: conversationId
        }
    })

    return (
        <div className="flex flex-col h-screen w-screen justify-between">
            <div>
                {messages.map(message => 
                    <div className="border rounded p-2 m-2 ">
                        {message.message}
                    </div>
                )}
            </div>
            <div>
                <input type="text" placeholder="Start typing..." className="w-300 m-5 p-5 border rounded-2xl"
                     
                />
                <button className="ml-5 mb-5 p-5 bg-black text-white rounded-2xl cursor-pointer border-2 hover:bg-gray-300 hover:text-black ">
                    Send
                </button>
            </div>


        </div>
    )
}