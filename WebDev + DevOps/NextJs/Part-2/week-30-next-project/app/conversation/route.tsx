import { prisma } from "@/lib/db";
import { NextRequest } from "next/server";

export async function POST(req: NextRequest){
    const body = await req.json();
    // console.log(body);
    const response = await prisma.conversation.create({
        data: {
            initialPrompt: body.initialPrompt
        }
    })

    const msgReponse = await prisma.message.create({
        data: {
            conversationId: response.id,
            message: body.initialPrompt,
            role: "User"
        }
    });

    return Response.json({
        message : "Conversation & Message gets Created",
        id: response.id
    });
}

export async function GET(req: NextRequest){
    return Response.json({
        message: "GET request received"
    });
}

