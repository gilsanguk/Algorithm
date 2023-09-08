import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M;
    static int[] arr;

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++)
            arr[i] = Integer.parseInt(st.nextToken());
    }

    public static boolean isPossible(long x) {
        long sum = M;
        for (int i = 0; i < M; i++)
            sum += x / arr[i];
        return sum < N;
    }

    public static void solve() throws IOException {
        if (N <= M) {
            bw.write(String.valueOf(N));
            return;
        }
        long l = 0, r = N * 30L;
        while (l <= r) {
            long m = (l + r) / 2;
            if (isPossible(m)) l = m + 1;
            else r = m - 1;
        }
        long cnt = M;
        for (int i = 0; i < M; i++)
            cnt += (l - 1) / arr[i];
        for (int i = 0; i < M; i++) {
            if (l % arr[i] == 0) cnt++;
            if (cnt == N) {
                bw.write(String.valueOf(i + 1));
                return;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
        bw.flush();
        bw.close();
    }
}