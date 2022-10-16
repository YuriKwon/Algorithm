const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (input) {
    const len = input.length;
    let set = new Set();
    for (let i = 1; i <= len; i++) {
        for (let j = 0; j < len; j++) {
            const substr = input.substring(j, j + i);
            set.add(substr);
        }
    }
    console.log(set.size);

    rl.close();
}).on('close', function () {
    process.exit();
});
