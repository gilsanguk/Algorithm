function oneWord(i, s) {
    for (let j = 0; j < s.length; j++){
        if (i !== j && s[i] === s[j]) return false;
    }
    return true;
}

function solution(s) {
    var answer = '';
    for (let i = 0; i < s.length; i++){
        if (oneWord(i, s)) answer += s[i];
    }
    answer = [...answer].sort().join('');
    return answer;
}