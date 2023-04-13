class Solution {
    static int N;
    public int solution(String A, String B) {
        N = A.length();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A.charAt((N - i + j) % N) != B.charAt(j)) {
                    break;
                }
                if (j == N - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
}