import "dotenv/config";
import { PrismaClient } from "@prisma/client";
import { PrismaPg } from "@prisma/adapter-pg";
import express from "express";
const app = express();
const adapter = new PrismaPg({
    connectionString: process.env.DATABASE_URL,
});
const client = new PrismaClient({
    adapter
});
app.get("/users", async (req, res) => {
    const users = await client.user.findMany();
    res.json({
        users: users
    });
});
app.get("/todos/:id", async (req, res) => {
    const id = parseInt(req.params.id);
    const todos = await client.user.findFirst({
        where: {
            id: id
        },
        select: {
            todos: true,
            username: true
        }
    });
    res.json({
        todos: todos
    });
});
app.listen(3000, () => {
    console.log("Server started on port 3000");
});
const createUser = async () => {
    await client.user.create({
        data: {
            username: "Harkirat",
            password: "123123",
            age: 30,
            city: "Noida"
        }
    });
    console.log("User Created");
};
const findUser = async (id) => {
    const user = await client.user.findFirst({
        where: {
            id: id
        }
    });
    console.log(user);
};
const findUserWithTodos = async (id) => {
    const user = await client.user.findFirst({
        where: {
            id: id
        },
        include: {
            todos: true
        }
    });
    console.log(user);
};
const createTodo = async () => {
    await client.todo.create({
        data: {
            title: "Go to GYM",
            description: "Do gym everyday",
            done: false,
            user_id: 1
        }
    });
    console.log("Todo Created");
};
// await createUser();
// await createTodo();
// await findUser(10);     // if user not present with thid id -> return null -> type safety 
// await findUserWithTodos(1);
await client.$disconnect();
// Without prisma -> need to write like this , we can also write wuery using prismaClient   
// client.$queryRaw("Insert into user(username, password, age, city) values(Harkirat, 123123, 30, Noida)");
//# sourceMappingURL=index.js.map