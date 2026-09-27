import { getServerSession } from "next-auth"
import { config } from "../api/auth/[...nextauth]/route";

export default async function () {

     const session = await getServerSession(config);

     if(!session?.user?.email){
        return <div>
            You are not logged In
        </div>
     }

    return (
        <div>
           Hi there {session.user.email}
        </div>
    )
}