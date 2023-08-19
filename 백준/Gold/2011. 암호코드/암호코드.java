import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static String cipher;

    static Long MOD(Long x) {return x % 1000000;}

    static void input() throws IOException {
        cipher = br.readLine();
        N = cipher.length();
        memo = new Long[N];
        Arrays.fill(memo, -1L);
    }

    static Long[] memo;
    static Long solve(int n) {
        if (n == N) return 1L;
        if (memo[n] != -1) return memo[n];
        memo[n] = 0L;
        if (cipher.charAt(n) != '0')
            memo[n] = MOD(solve(n + 1));
        if (n < N - 1) {
            int tmp = Integer.parseInt(cipher.substring(n, n + 2));
            if (9 < tmp && tmp < 27)
                memo[n] = MOD(memo[n] + solve(n + 2));
        }
        return memo[n];
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve(0) + "");
        bw.flush();
        bw.close();
    }
}