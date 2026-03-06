const fs = require("fs");

// accessing the command line arguments
console.log(process.argv);

const main = async(fileName) => {
    fs.readFile(fileName, "utf-8", (err, data) => {
        if(err){
            console.log(err);
        }
        else{
            const words = data.split(" ").length;
            console.log(words);
        }
    })
}

main(process.argv[1]);