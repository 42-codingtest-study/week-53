//문제: 1926
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const [ROW, COL] = input.shift().split(" ").map(Number);

  const visited = Array.from({ length: ROW }, () => new Array(COL).fill(false));

  const MAP = input.map((e) => e.split(" ").map(Number));

  const check_valid = (x, y) => {
    if (x >= 0 && x < ROW && y >= 0 && y < COL) {
      return true;
    } else return false;
  };

  const dx = [0, 0, 1, -1];
  const dy = [1, -1, 0, 0];

  const DFS = (x, y, MAP) => {
    const stack = [];
    stack.push([x, y]);

    let len = 0;
    while (stack.length) {
      let [[now_x, now_y]] = stack.splice(stack.length - 1, 1);
      if (visited[now_x][now_y] === false) {
        len++;
        visited[now_x][now_y] = true;
      }

      for (let i = 0; i < 4; i++) {
        if (
          check_valid(now_x + dx[i], now_y + dy[i]) &&
          !visited[now_x + dx[i]][now_y + dy[i]] &&
          MAP[now_x + dx[i]][now_y + dy[i]]
        ) {
          stack.push([now_x + dx[i], now_y + dy[i]]);
        }
      }
    }
    return len;
  };
  let num = 0;
  let max = 0;
  for (let i = 0; i < ROW; i++) {
    for (let j = 0; j < COL; j++) {
      if (MAP[i][j]) {
        let a = DFS(i, j, MAP);
        max = Math.max(max, a);
        if (a) num++;
      }
    }
  }
  console.log(num);
  console.log(max);
}
