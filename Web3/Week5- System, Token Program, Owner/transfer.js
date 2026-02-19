const {Connection, Keypair, Transaction, SystemProgram, LAMPORTS_PER_SOL, clusterApiUrl, PublicKey, sendAndConfirmTransaction} = require("@solana/web3.js");
require("dotenv").config();

// creating a connection for signing transaction
const connection = new Connection(clusterApiUrl("devnet"), "confirmed");

// senders keypair
const secret = process.env.SECRET_KEY.split(",").map(Number);
const sender = Keypair.fromSecretKey(new Uint8Array(secret));

// recipient address
const recipient = new PublicKey("BnK7nHauCSruQaAXjH1XWmEsBytoBrvGfRMSFWoJ83Gg");
// console.log(recipient.toString());
// console.log(sender.publicKey.toString())


// Build the transaction
// /*
const transaction = new Transaction().add(
    SystemProgram.transfer({
        fromPubkey : sender.publicKey,
        toPubkey : recipient,
        lamports : 0.000001*LAMPORTS_PER_SOL
    })
)

// sign and confirm the transaction
const transfer = async(connection, transaction, sender) => {
    const signature = await sendAndConfirmTransaction(connection, transaction, [sender]);
    console.log(signature);
}

transfer(connection, transaction, sender);
// */



// to get account Info
/** 
const getAccountInfo = async(pubKey) => {
    const accountInfo = await connection.getAccountInfo(new PublicKey(pubKey));
    console.log("Account Info data :", accountInfo);
    console.log("Account Owner ", accountInfo.owner.toBase58())
}
getAccountInfo(sender.publicKey.toString());
 getAccountInfo(recipient.toString());
 */
