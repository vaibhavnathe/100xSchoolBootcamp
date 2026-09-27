import CredentialsProvider from "next-auth/providers/credentials";
import NextAuth from "next-auth";

let ID = 1;
const USERS:{id: string, email: string, password: string}[] = [];

export const config = {
    providers: [
        CredentialsProvider({
            // The name to display on the sign in form (e.g. "Sign in with...")
            name: "Credentials",
            // `credentials` is used to generate a form on the sign in page.
            // You can specify which fields should be submitted, by adding keys to the `credentials` object.
            // e.g. domain, username, password, 2FA token, etc.
            // You can pass any HTML attribute to the <input> tag through the object.
            credentials: {
                username: { label: "username", type: "text", placeholder: "jsmith" },
                password: { label: "Password", type: "password" }
            },
            async authorize(credentials, req) {
                // Add logic here to look up the user from the credentials supplied
                const username = credentials?.username;
                const password = credentials?.password;

                if(!username || !password){
                    return null;
                }

                const existingUser = await USERS.find(u => u.email === username);
                if(existingUser){
                    if(existingUser.password == password){
                        return existingUser;
                    }
                    else{
                        return null;
                    }
                }

                const newUser ={
                    id: ID.toString(),
                    email: username,
                    password: password
                }
                ID++;

                await USERS.push(newUser);
                
                return newUser;
            }
        })
    ]
};

const handler = NextAuth(config);

export { handler as GET, handler as POST }  