import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M, K;
    static final int INF = 1000000001;
    static StringBuilder ans = new StringBuilder();

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for (int i = 0; i < 201; i++)
            Arrays.fill(memo[i], -1);
    }

    static int[][] memo = new int[201][201];
    static int dp(int n, int c) {
        if (n == 0 || c == 0) return memo[n][c] = 1;
        if (memo[n][c] != -1) return memo[n][c];
        memo[n][c] = Math.min(dp(n - 1, c) + dp(n, c - 1), INF);
        return memo[n][c];
    }

    static void setAns(int A, int Z, int k) {
        if (A == 0) {
            ans.append("z".repeat(Z));
            return;
        }
        if (Z == 0) {
            ans.append("a".repeat(A));
            return;
        }
        if (k <= memo[A - 1][Z]) {
            ans.append('a');
            setAns(A - 1, Z, k);
        } else {
            ans.append('z');
            setAns(A, Z - 1, k - memo[A - 1][Z]);
        }
    }

    static void solve() throws IOException {
        if (dp(N, M) < K) bw.write("-1");
        else {
            setAns(N, M, K);
            bw.write(ans.toString());
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
        bw.flush();
        bw.close();
    }
}