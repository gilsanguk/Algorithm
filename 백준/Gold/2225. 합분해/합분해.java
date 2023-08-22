import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, K;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        memo = new Long[N][K];
        for (int i = 0; i < N; i++)
            Arrays.fill(memo[i], -1L);
    }

    static Long[][] memo;
    static Long solve(int n, int k) throws IOException {
        if (n == N || k == K - 1) return 1L;
        if (memo[n][k] != -1) return memo[n][k];
        memo[n][k] = solve(n + 1, k) + solve(n, k + 1);
        return memo[n][k] % 1000000000;
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve(0, 0) + "");
        bw.flush();
        bw.close();
    }
}