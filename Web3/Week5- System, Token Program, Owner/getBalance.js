const {Connection, PublicKey, clusterApiUrl} = require("@solana/web3.js");

// creating a connection to devnet
// const connection = new Connection("https://api.devnet.solana.com");
const connection = new Connection(clusterApiUrl("devnet"));

const getBalance = async (pubKey) => {
    try{
        // getting balance
        const balance  = await connection.getBalance(new PublicKey(pubKey));
        console.log("Balance :", balance);
    }
    catch(err){
        console.log(err);
    }
}

const pubKey = "FVHJSBBQcGoeoxHc3533ahgahCR7qpaj4NNRjE4WyB3P";
getBalance(pubKey);