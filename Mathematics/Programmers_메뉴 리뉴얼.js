// 관련개념: 조합
function getCombinations(arr, selectNumber) {
    let result = [];
    if (selectNumber === 1) return arr.map((value) => [value]);

    // sort 이유: AW, WA가 따로 카운팅 되는 것 방지
    [...arr].sort().forEach((item, index, originArr) => {
        const rest = originArr.slice(index + 1);
        const combinations = getCombinations(rest, selectNumber - 1);
        const attached = combinations.map((combination) => item + combination);
        // console.log(attached);
        result.push(...attached);
    });
    // console.log(result);
    return result;
}

function solution(orders, course) {
    let answer = [];
    let counting = {};
    for (const num of course) {
        orders.forEach((order) => {
            let combination = getCombinations(order, num);
            for (const item of combination) {
                if (counting[item] === undefined) {
                    counting[item] = 1;
                } else {
                    counting[item]++;
                }
            }
        });
    }

    let maxMode = {}; // 각 코스(단품메뉴 개수)별로 가장 많이 주문된 조합의 주문횟수(max값)
    let menus = {}; // 각 코스별로 가장 많이 주문된 조합을 저장
    for (const key in counting) {
        let item = counting[key];
        let len = key.length;
        if (item >= 2) {
            course.forEach((num) => {
                if (len === num) {
                    if (maxMode[num] === undefined) {
                        maxMode[num] = item;
                        menus[num] = [key];
                    } else if (maxMode[num] < item) {
                        maxMode[num] = item;
                        menus[num] = [key];
                    } else if (maxMode[num] == item) {
                        menus[num].push(key);
                    }
                }
            });
        }
    }

    for (const course in menus) {
        menus[course].forEach((menu) => {
            answer.push(menu);
        });
    }
    answer.sort();

    return answer;
}
