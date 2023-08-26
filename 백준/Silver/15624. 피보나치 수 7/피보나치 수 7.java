import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;

    static void input() throws IOException {
       N = Integer.parseInt(br.readLine());
    }

    static long[] memo = new long[1000001];
    public static long solve(int n) {
        if (n < 3) return 1;
        if (memo[n] != 0) return memo[n];
        return memo[n] = (solve(n - 1) + solve(n - 2)) % 1000000007;
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve(N) + "");
        bw.flush();
        bw.close();
    }
}