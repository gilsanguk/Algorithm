import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr;
    static int[][] memo;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        memo = new int[N][3];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            Arrays.fill(memo[i], -1);
        }
    }

    public static int solve(int n, int prev) {
        if (n == N) return 0;
        if (memo[n][prev] != -1) return memo[n][prev];
        memo[n][prev] = solve(n + 1, 0);
        if (prev != 2)
            memo[n][prev] = Math.max(memo[n][prev], solve(n + 1, prev + 1) + arr[n]);
        return memo[n][prev];
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve(0, 0) + "");
        bw.flush();
        bw.close();
    }
}