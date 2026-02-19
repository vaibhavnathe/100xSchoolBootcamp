// Q: Allocating space after creating an account on solana

const {Connection, Keypair, Transaction, SystemProgram, LAMPORTS_PER_SOL, sendAndConfirmTransaction} = require("@solana/web3.js");
require("dotenv").config();

// creating a connection with devnet
const connection = new Connection("https://api.devnet.solana.com");

const secret = process.env.SECRET_KEY.split(",").map(Number);
console.log(secret);

const newAccount = Keypair.generate();
const myAccount = Keypair.fromSecretKey(new Uint8Array(secret));

// creating transaction
const transaction1 = new Transaction().add(
    SystemProgram.transfer({
        fromPubkey : myAccount.publicKey,
        toPubkey : newAccount.publicKey,
        lamports : 0.1*LAMPORTS_PER_SOL
    })
)
// signing transaction
const sign1 = async() => {
    const signature = await sendAndConfirmTransaction(connection, transaction1, [myAccount]);
    console.log(signature);
}
sign1();

/// wait for 30 sec to confirmed transaction on devnet -> weired on devnet
const wait = async () => {
    await new Promise(r => setTimeout(r,30*1000));
}
wait();


// allocation space -> the newAccouunt's key needs to sign transaction for allocating space for his account not same as above for creation of an account
const transaction2 = new Transaction().add(
    SystemProgram.allocate({
        accountPubkey : newAccount.publicKey,
        space : 100
    })
)

const sign2 = async() => {
    const signature2 = await sendAndConfirmTransaction(connection, transaction2, [newAccount]);
    console.log(signature2)
}
sign2();
