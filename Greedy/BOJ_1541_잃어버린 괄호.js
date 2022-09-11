const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (line) {
    // console.log(line);
    let splitByMinus = line.split('-');
    let result = [];
    let sum = 0;
    for (const item of splitByMinus) {
        let splitByPlus = item.split('+');
        let num = 0;
        for (const i of splitByPlus) {
            num += +i;
        }
        result.push(num);
        sum -= num;
    }
    sum += 2 * result[0];
    console.log(sum);
    rl.close();
}).on('close', function () {
    process.exit();
});
