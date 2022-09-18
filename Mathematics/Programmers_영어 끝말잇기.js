function isProperWord(prevWord, currentWord) {
    if (prevWord === '') return true;
    let prevLen = prevWord.length;
    if (prevWord[prevLen - 1] === currentWord[0]) return true;
    return false;
}

// 이미 나온 단어면 true
function isAppearWord(word, wordList) {
    return wordList.includes(word);
}

function solution(n, words) {
    let prevWord = '';
    let wordList = [];
    let maxTurnCnt = words.length;

    let turnCnt = 0;
    for (let i = 1; i <= maxTurnCnt; i++) {
        turnCnt++;
        let word = words[i - 1];
        if (word.length === 1 || !isProperWord(prevWord, word) || isAppearWord(word, wordList)) {
            console.log(word);
            let mode = turnCnt % n;
            let person = mode === 0 ? n : mode;
            let turn = mode === 0 ? Math.floor(turnCnt / n) : Math.floor(turnCnt / n) + 1;
            return [person, turn];
        }
        wordList.push(word);
        prevWord = word;
    }
    return [0, 0];
}
