const { Connection, Keypair, LAMPORTS_PER_SOL, clusterApiUrl, PublicKey} = require("@solana/web3.js");
const {getAssociatedTokenAddress, unpackAccount} = require("@solana/spl-token")
require("dotenv").config();

// connecting to the helius rpc to airdrop some sol
// const connection = new Connection("https://devnet.helius-rpc.com/?api-key=d1a0f6fd-8ed9-4832-a15d-dd2df85975d8")
const connection = new Connection("https://api.devnet.solana.com")

// const mySecretKey = Keypair.fromSecretKey(new Uint8Array(["payers keypair byte array"]))
const mySecretKey = process.env.SECRET_KEY.split(",").map(Number);
const mintAddress = new PublicKey("2rLCSf42W3up5FPGQUVRhMquWBch4shfYGqiuoeN7fmu");      // mint address of token created by me

// how would you send this keypair (public key) 1 sol of an airdrop
const requestSol = async() => {
    // const keypair = Keypair.generate(); 
    // await connection.requestAirdrop(keypair.publicKey, 0.1 * LAMPORTS_PER_SOL);  // error :- rpc calls are limited

    // getting account balance of an accounrt
    const balance = await connection.getBalance(mySecretKey.publicKey);
    console.log("Balance :", balance/LAMPORTS_PER_SOL);  // 2 sol
}
// requestSol();



// getting a balance of a custon token :- ex. How much usdc does harkirat have
// 1. Using the @solana/spl-token library 
const getTokenBalance = async(publicKey, mintAddress) => {
    // return the users token balance

    // getting the ata address
    const ataAddress = await getAssociatedTokenAddress(mintAddress, publicKey);
    console.log("PDA/ATA Address:", ataAddress.toBase58());

    //getting the ata accunt's data
    const ataAccountData = await connection.getAccountInfo(ataAddress);
    console.log("Account data:", ataAccountData);

    // getting account info , balance
    const tokenBalance = await connection.getTokenAccountBalance(ataAddress);
    console.log("Balance:", tokenBalance.value);

    // getting amount/balance
    const innerData = await unpackAccount(ataAddress, ataAccountData);
    console.log("Amount : ", innerData.amount);
} 
// getTokenBalance(mySecretKey.publicKey, mintAddress);


// 2. Derive PDA/ATA Without using getAssociatedTokenAccount functin
const getTokenAccountBalanceWithoutSPL = async() => {
    const TOKEN_PROGRAM_ID = new PublicKey('TokenkegQfeZyiNwAJbNbGKPFXCWuBvf9Ss623VQ5DA');
    const ASSOCIATED_TOKEN_PROGRAM_ID = new PublicKey('ATokenGPvbdGVxr1b2hvZbsiqW5xWH25efTNsLJA8knL');

    const [ataAddress, bump] = PublicKey.findProgramAddressSync(
        [   mySecretKey.publicKey.toBuffer(), 
            TOKEN_PROGRAM_ID.toBuffer(),
            mintAddress.toBuffer()
        ]
        ,
        ASSOCIATED_TOKEN_PROGRAM_ID
    );
    console.log(ataAddress.toBase58());
    console.log(bump);

    const ataAccountData = await connection.getAccountInfo(ataAddress);
    console.log(ataAccountData.data);

    const innerData = unpackAccount(ataAddress, ataAccountData);
    console.log(innerData);

}
// getTokenAccountBalanceWithoutSPL();



