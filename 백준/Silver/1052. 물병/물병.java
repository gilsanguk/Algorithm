import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, K;

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
    }

    public static String solve() {
        if (N <= K) return "0";
        int ans = 0;
        while (true) {
            int cnt = 0;
            int tmp = N;
            while (tmp > 0) {
                if (tmp % 2 == 1) cnt++;
                tmp /= 2;
            }
            if (cnt <= K) break;
            N++;
            ans++;
        }
        return String.valueOf(ans);
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve());
        bw.flush();
        bw.close();
    }
}