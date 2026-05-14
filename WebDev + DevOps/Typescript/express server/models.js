
import mongoose  from "mongoose";

// Schema & models

// Schema's
const userSchema = new mongoose.Schema({
    id: mongoose.Types.id,
    username: String,
    email: String,
    password: String
})

const todoSchema = new mongoose.Schema({
    id: mongoose.Types.id,
    title: String,
    description: String,
    userId: mongoose.Types.ObjectId
})

// models
//new modern exports in ts
export const userModel = mongoose.model("User", userSchema);
export const todoModel = mongoose.model("Todo", todoSchema);

// somtimes file can return only one thing , that is default
// export default userModel;    // exporting only userModel -> default


// old exports in JS
// module.exports = {
//     userModel,
//     todoModel
// }

