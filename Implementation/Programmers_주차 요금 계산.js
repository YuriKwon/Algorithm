// 반성: 구조 분해 할당을 썼으면 코드가 훨씬훨씬 단축됐겠다는 생각..
// 주차 시간(분)
function getTime(inStr, outStr) {
    let inTime = inStr.split(' ')[1];
    let outTime = outStr.split(' ')[1];
    let inHour = inTime.substring(0, 2);
    let inMinute = inTime.substring(3, 5);
    let outHour = outTime.substring(0, 2);
    let outMinute = outTime.substring(3, 5);
    let resHour = outHour - inHour;
    let resMinute = outMinute - inMinute;

    return resHour * 60 + resMinute;
}

// 요금계산
function getFee(fees, minute) {
    let defaultTime = fees[0];
    let defaultFee = fees[1];
    let extraTime = fees[2];
    let extraFee = fees[3];
    let sumFee = 0;
    if (minute <= defaultTime) return defaultFee;
    else {
        sumFee += defaultFee;
        minute -= defaultTime;
        while (minute > 0) {
            sumFee += extraFee;
            minute -= extraTime;
        }
    }
    return sumFee;
}

function solution(fees, records) {
    let len = records.length;
    let obj = {};
    let newResult = {};
    for (let i = 0; i < len; i++) {
        let words = records[i].split(' ');
        let time = words[0];
        let num = words[1];
        let type = words[2];

        if (obj[num] === undefined) obj[num] = [`${type} ${time}`];
        else obj[num].push(`${type} ${time}`);
    }

    // 길이가 홀수일 때 23:59 OUT 넣어주기
    for (let key in obj) {
        if (obj[key].length % 2 !== 0) {
            obj[key].push(`OUT 23:59`);
        }
    }
    let result = {};
    for (let key in obj) {
        let accTime = 0; // 누적 주차 시간
        for (let i = 0; i < obj[key].length / 2; i++) {
            accTime += getTime(obj[key][2 * i], obj[key][2 * i + 1]);
        }

        let fee = getFee(fees, accTime);

        if (obj[key].length % 2 !== 0) {
            obj[key].push(`OUT 23:59`);
        }
        key = +key;
        result[key] = fee;

        Object.keys(result)
            .sort()
            .forEach(function (key) {
                newResult[key] = result[key];
            });
    }
    var answer = [];
    for (let key in newResult) {
        answer.push(newResult[key]);
    }

    return answer;
}
