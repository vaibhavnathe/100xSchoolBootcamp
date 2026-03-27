import {clusterApiUrl, Connection, Keypair, LAMPORTS_PER_SOL, PublicKey, sendAndConfirmRawTransaction, sendAndConfirmTransaction, SystemProgram, Transaction} from "@solana/web3.js";
import { ASSOCIATED_TOKEN_PROGRAM_ID, TOKEN_PROGRAM_ID } from "@solana/spl-token";
require("dotenv").config();

const connection = new Connection(clusterApiUrl("devnet"));
// const myKeyPair = Keypair.fromSecretKey(new Uint8Array(["payers keypair byte array"]))
const myKeyPair = process.env.SECRET_KEY.split(",").map(Number);


const createAccount = async() => {
    const newAccount = Keypair.generate();
    const [randomPDA] = PublicKey.findProgramAddressSync([], ASSOCIATED_TOKEN_PROGRAM_ID);
    
    const transaction = new Transaction().add(
        SystemProgram.createAccount({
            fromPubkey : myKeyPair.publicKey,
            // newAccountPubkey: newAccount.publicKey,
            newAccountPubkey : randomPDA,       // but PDA's don't have private key so how they gonna sign the txn
            lamports: 0.01* LAMPORTS_PER_SOL,
            space : 165,
            programId : TOKEN_PROGRAM_ID
        })
    );

    const blockHash = await connection.getLatestBlockhash();
    console.log(blockHash)

    const signature = await sendAndConfirmTransaction(connection,transaction, [myKeyPair, newAccount]);     // here not direct but somehow we pass the ASS_TOKEN_ADDRESS to sign for PDA
    console.log("TXN Signature :", signature);
    console.log(newAccount.publicKey.toBase58());
}

createAccount();


// PDA's Features:
// 1) Deterministic Account addresses : derive an address using seeds[users pubKey, token mint address, token program addres] & program id (ass token address)
// 2) Enable Program Signing : Q) PDA's don't have private key, so when creating new pda account it need to sign transaction for creating new account
//                          How PDA sign txn for creating account :- Using Program signing 
//        Program Signing  :- Programs(Associated token program) can sign on behalf of pda's
//   Ex. Whenever users needs to create ATA/PDA for custom token, they interact with ass_token_program which internally through CPI's calls System Program,
//       So System program is going to create an account(ata/pda) for that account ass_token_program signs the transaction