// js shift가 O(n)의 시간복잡도라서 array로 큐 구현 불가
// 연결리스트로..
function Node(val) {
  this.value = val;
  this.next = null;
}

function Queue() {
  this.front = null;
  this.back = null;
  this.size = 0;

  this.insert = function (value) {
    const node = new Node(value);
    if (this.size === 0) {
      this.front = node;
      this.back = node;
    } else {
      this.back.next = node;
      this.back = node;
    }
    this.size++;
  };

  this.pop = function () {
    if (this.size === 0) {
      throw new Error('cannot pop');
    }
    const value = this.front.value;
    this.front = this.front.next;
    this.size--;

    if (this.size === 0) {
      this.back = null;
    }
    return value;
  };

  this.getSum = function () {
    let sum = 0;
    let cur = this.front;
    while (cur != this.back) {
      sum += cur.value;
      cur = cur.next;
    }

    if (this.back) {
      sum += this.back.value;
    }
    return sum;
  };

  // isEmpty, getFirst 등의 메소드도 추가 가능
}

function getArrSum(arr) {
  return arr.reduce((acc, cur) => acc + cur, 0);
}

function solution(queue1, queue2) {
  let answer = 0; // 작업 횟수
  let elementCnt = queue1.length + queue2.length;
  let leftQueueSum = getArrSum(queue1);
  let rightQueueSum = getArrSum(queue2);
  let q1 = new Queue();
  let q2 = new Queue();

  queue1.forEach((element) => {
    q1.insert(element);
  });

  queue2.forEach((element) => {
    q2.insert(element);
  });

  while (leftQueueSum != rightQueueSum) {
    if (answer > elementCnt * 3) return -1;
    if (leftQueueSum > rightQueueSum) {
      // shift가 O(n)이라 시간초과남 - js로 큐 구현할 때 주의하기,,
      const popValue = q1.pop();
      leftQueueSum -= popValue;
      rightQueueSum += popValue;
      q2.insert(popValue);
    } else {
      const popValue = q2.pop();
      leftQueueSum += popValue;
      rightQueueSum -= popValue;
      q1.insert(popValue);
    }
    answer++;
  }
  return answer;
}
