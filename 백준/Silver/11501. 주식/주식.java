import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static int[] arr;

    public static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
    }

    public static String solve() {
        long ans = 0;
        int max = 0;
        for (int i = N - 1; i > -1; i--) {
            max = Math.max(max, arr[i]);
            ans += max - arr[i];
        }
        return String.valueOf(ans);
    }

    public static void main(String[] args) throws IOException {
        int T;
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            input();
            bw.write(solve() + '\n');
        }
        bw.flush();
        bw.close();
    }
}