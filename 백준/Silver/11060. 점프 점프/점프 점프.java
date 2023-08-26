import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static int[] arr;
    static final int INF = 987654321;

    static void input() throws IOException {
       N = Integer.parseInt(br.readLine());
       arr = new int[N];
       memo = new int[N];
       Arrays.fill(memo, -1);
       st = new StringTokenizer(br.readLine());
       for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
    }

    static int[] memo;
    public static int solve(int n) {
        if (n >= N - 1) return 0;
        if (memo[n] != -1) return memo[n];
        memo[n] = INF;
        for (int i = 1; i <= arr[n]; i++) {
            memo[n] = Math.min(memo[n], solve(n + i) + 1);
        }
        return memo[n];
    }

    public static void main(String[] args) throws IOException {
        input();
        int ans = solve(0);
        if (ans == INF) ans = -1;
        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
    }
}