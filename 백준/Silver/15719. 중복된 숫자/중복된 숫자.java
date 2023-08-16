import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
    }

    public static int solve() throws IOException {
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int a = Integer.parseInt(st.nextToken());
            if (arr[a] == 1) return a;
            arr[a]++;
        }
        return 0;
    }

    static int T;
    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve() + "");
        bw.flush();
        bw.close();
    }
}