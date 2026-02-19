import {Connection, Keypair, LAMPORTS_PER_SOL, sendAndConfirmTransaction, SystemProgram, Transaction} from "@solana/web3.js";
import dotenv from "dotenv";
dotenv.config()
if (!process.env.SECRET_KEY) {
  throw new Error("SECRET_KEY missing");
}

// creating a connection
const connection = new Connection("https://api.devnet.solana.com");

const newAccount = Keypair.generate();

const secret = process.env.SECRET_KEY.split(",").map(n => Number(n.trim()));
const myWallet = Keypair.fromSecretKey(new Uint8Array(secret));

/* Creating account */
const transaction1 = new Transaction().add(
    SystemProgram.transfer({
       fromPubkey : myWallet.publicKey,
        toPubkey : newAccount.publicKey,
        lamports : 0.1*LAMPORTS_PER_SOL
    })
)

const signature = await sendAndConfirmTransaction(connection, transaction1, [myWallet]);
console.log("Signature :", signature);

// dvenet pe jaldi transaction jati nahi hai isliye thoda wait karna padega
await new Promise(r => setTimeout(r, 30*1000));


