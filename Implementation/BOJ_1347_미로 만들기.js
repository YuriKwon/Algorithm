const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line) {
  input.push(line);
  if (input.length === 2) rl.close();
}).on('close', function () {
  main();
  process.exit();
});

let input = []; // input 값
// const direction = {
//   S: 0,
//   W: 1,
//   N: 2,
//   E: 3
// };
let startDir = 0;
let startX = 0;
let startY = 0;
let coordinates = new Set();
let minX = 50;
let minY = 50;
let maxX = 0;
let maxY = 0;

function main() {
  const num = input[0];
  const str = input[1];
  coordinates.add({ x: 0, y: 0 });

  for (let i = 0; i < str.length; i++) {
    let char = str[i];
    switch (char) {
      case 'R':
        startDir = (startDir + 1) % 4;
        break;
      case 'L':
        startDir = startDir == 0 ? 3 : startDir - 1;
        break;
      case 'F':
        go();
        break;
    }
  }

  for (let coordinate of coordinates) {
    if (coordinate.x > maxX) maxX = coordinate.x;
    if (coordinate.x < minX) minX = coordinate.x;

    if (coordinate.y > maxY) maxY = coordinate.y;
    if (coordinate.y < minY) minY = coordinate.y;
  }

  for (let y = minY; y <= maxY; y++) {
    for (let x = minX; x <= maxX; x++) {
      let isMove = false;
      for (let coordinate of coordinates) {
        if (coordinate.x == x && coordinate.y == y) isMove = true;
      }
      if (isMove) process.stdout.write('.');
      else process.stdout.write('#');
    }
    console.log('');
  }
}

function go() {
  switch (startDir) {
    case 0:
      startY++;
      break;
    case 1:
      startX--;
      break;
    case 2:
      startY--;
      break;
    case 3:
      startX++;
      break;
  }
  coordinates.add({ x: startX, y: startY });
}

// (coordinates.has({ x: x, y: y })는 비교안됨
// https://bobbyhadz.com/blog/javascript-check-if-set-contains-object
