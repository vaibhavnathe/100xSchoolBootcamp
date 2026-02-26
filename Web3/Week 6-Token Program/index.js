import {createMint, TOKEN_PROGRAM_ID} from "@solana/spl-token"
import {Connection, Keypair, clusterApiUrl} from "@solana/web3.js";
require("dotenv").config();

const connection = new Connection(clusterApiUrl("devnet"));

// const payer = Keypair.fromSecretKey(new Uint8Array(["Secreat Key Byte Array"]));
const payer = process.env.SECRET_KEY.split(",").map(Number);

const mintAuthority = payer;

const createMintToken = async(payer, mintAuthority) => {
    const mint = await createMint(
                    connection, 
                    payer, 
                    mintAuthority,
                    null,
                    6,
                    TOKEN_PROGRAM_ID
                );
    return mint;
}

const mint = createMintToken(payer, mintAuthority);
console.log("Mint created at :", mint);