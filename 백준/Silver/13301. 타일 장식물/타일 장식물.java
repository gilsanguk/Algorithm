import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static int[] memo = new int[81];

    public static int solve(int n) {
        if (n == 1) return 4;
        if (n == 2) return 6;
        if (memo[n] != 0) return memo[n];
        return memo[n] = solve(n - 1) + solve(n - 2);
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        bw.write(String.valueOf(solve(N)));
        bw.flush();
        bw.close();
    }
}