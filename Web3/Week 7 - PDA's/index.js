import {PublicKey} from "@solana/web3.js";
import {getAssociatedTokenAddress} from "@solana/spl-token";

const mintAddress = new PublicKey("Es9vMFrzaCERmJfrF4H2FYD4KCoNkY11McCe8BenwNYB");          // usdt mint address
// const mintAddress = new PublicKey("2rLCSf42W3up5FPGQUVRhMquWBch4shfYGqiuoeN7fmu");       // mint address of custom token in phantom
const userPubKey = new PublicKey("BnK7nHauCSruQaAXjH1XWmEsBytoBrvGfRMSFWoJ83Gg");           // users pub key

// spl-token library provide getAssociatedTokenAddress function which hides complexity for us :- getAssociatedTokenAddress derived the address of the 
const address = await getAssociatedTokenAddress(
    mintAddress, 
    userPubKey
);
console.log(address.toBase58());


const associatedTokenProgramId = new PublicKey("ATokenGPvbdGVxr1b2hvZbsiqW5xWH25efTNsLJA8knL");     // Associated token program address
const programId = new PublicKey("TokenkegQfeZyiNwAJbNbGKPFXCWuBvf9Ss623VQ5DA");                     // Token Program address

// getAssociatedTokenAddress function internally uses the findProgramAddressSync function which accepts certain params (ATP address + [userPubKey, Token Program address, mint address of specific token])
const [address2] = await PublicKey.findProgramAddressSync(
    [   userPubKey.toBuffer(),     // tobuffer -> converting to bytes
        programId.toBuffer(), 
        mintAddress.toBuffer()
    ],
    associatedTokenProgramId    // A PDA can be derived from any program , generally most of pda's are derived from ATP (Associated Token Program)
);

console.log(address2.toBase58());