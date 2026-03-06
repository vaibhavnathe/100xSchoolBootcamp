/** Create a command line interface CLI that lets the user specify a file path and the nodejs process counts the number of lines inside it. */
// Input - node cli.js /Users/kirat/file.txt
// Output - You have 10 lines in this file

const {Command} = require("commander");
const fs = require("fs");

const program = new Command();

program
  .name('Word Counter')
  .description('CLI to do file based tasks')
  .version('0.8.0');

program.command('count-lines')
    .description('Count the number of lines in a file')
    .argument('<file>', 'file to count number of lines in the file')
    .action((file) => {
        fs.readFile(file, 'utf-8', (err, data) => {
            if(err){
                console.log(err);
            }
            else{
                const lines = data.split('\n').length;
                console.log(`There are ${lines} lines in ${file}`);
            }
        });
    });

program.command('count-words')
    .description('Count the number of words in a file')
    .argument('<file>', 'file to count the no of words in file')
    .action((file) => {
        fs.readFile(file, 'utf-8', (err, data) => {
            if(err){
                console.log(err);
            }
            else{
                const lines = data.split(' ').length;
                console.log(`There are ${lines} words in ${file}`);
            }
        });
    });

program.parse();
