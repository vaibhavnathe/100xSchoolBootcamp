import { getServerSession } from "next-auth";
import { NextRequest, NextResponse } from "next/server";
import { config } from "../auth/[...nextauth]/route";


export const POST = async(req: NextRequest, res: NextResponse) => {
    
    const session = await getServerSession(config);

    if(!session){
        return NextResponse.json({
            message: "Incorrect Credentials, You are not logged In"
        });
    }
    else{
        return NextResponse.json({
            email: session.user?.email,
            message: "Todo Created"
        })
    }
}