import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, W;
    static int[] arr;

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        W = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
    }

    static boolean[] sum = new boolean[800000];
    public static String solve() {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int cur = arr[i] + arr[j];
                if (W < cur) continue;
                if (sum[W - cur]) return "YES";
            }
            for (int j = 0; j < i; j++)
                sum[arr[i] + arr[j]] = true;
        }
        return "NO";
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve());
        bw.flush();
        bw.close();
    }
}