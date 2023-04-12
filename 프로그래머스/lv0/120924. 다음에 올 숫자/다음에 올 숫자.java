class Solution {
    public int solution(int[] common) {
        int prv = common[1] - common[0];
        if (common[2] - common[1] == prv) return common[common.length-1] + prv;
        prv = common[1]/common[0];
        if (common[2]/common[1] == prv) return common[common.length-1]*prv;
        return 0;
    }
}