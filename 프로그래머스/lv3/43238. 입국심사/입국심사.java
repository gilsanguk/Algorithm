import java.util.Arrays;

class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        long l = 1, r = (long) times[times.length - 1] * n;
        while (l < r) {
            long m = (l + r) / 2;
            long cnt = 0;
            for (int time : times) {
                cnt += m / time;
            }
            if (cnt < n) l = m + 1;
            else r = m;
        }
        return r;
    }
}