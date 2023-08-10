import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr;

    public static int solve() {
        Arrays.sort(arr);
        for (int i = N; i > 0; i--) {
            if (i <= arr[N - i]) {
                return i;
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(solve()));
        bw.flush();
        bw.close();
    }
}