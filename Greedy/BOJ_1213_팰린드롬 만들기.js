const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim();

let count = [];
let len = input.length;
for (let i = 0; i < len; i++) {
    const x = input.charCodeAt(i) - 65;
    if (count[x]) {
        count[x]++;
    } else {
        count[x] = 1;
    }
}

const odd = count.filter((v) => v % 2 != 0);
if (odd.length > 1) {
    console.log("I'm Sorry Hansoo");
} else {
    let head = '';
    let body = '';
    let tail = '';

    count.forEach((v, i) => {
        if (v % 2 != 0) {
            body += String.fromCharCode(i + 65);
            v--;
        }
        for (let k = 0; k < v / 2; k++) {
            head += String.fromCharCode(i + 65);
            tail = String.fromCharCode(i + 65) + tail;
        }
    });
    console.log(head + body + tail);
}
