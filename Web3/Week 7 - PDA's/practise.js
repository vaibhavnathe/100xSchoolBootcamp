import {Connection, PublicKey, Keypair, clusterApiUrl, LAMPORTS_PER_SOL, SystemProgram, sendAndConfirmRawTransaction} from "@solana/web3.js";
import {getAssociatedTokenAddress} from "@solana/spl-token";

const connection = new Connection(clusterApiUrl("devnet"));

// admin keypair
const adminKey = Keypair.generate();

await connection.requestAirdrop(adminKey, 1*LAMPORTS_PER_SOL);

const keypair = Keypair.generate();     // does have public key, private key

const txn = new Transaction().add(
    SystemProgram.createAccount({
        fromPubkey: adminKey.publicKey,
        newAccountPubkey : keypair.publicKey,
        lamports : 0.001*LAMPORTS_PER_SOL,
        space: 100,
    })
)

const signature = await sendAndConfirmRawTransaction(connection,txn,[adminKey, keypair]);
console.log(signature);