import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int X, N;
    static int[] arr;

    public static String solve() {
        Arrays.sort(arr);
        int l = 0, r = N - 1;
        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == X) return "yes " + arr[l] + " " + arr[r] + "\n";
            if (sum < X) l++;
            if (sum > X) r--;
        }
        return "danger\n";
    }

    public static void main(String[] args) throws IOException {
        while (true) {
            String str = br.readLine();
            if (str == null) break;
            X = Integer.parseInt(str) * 10000000;
            N = Integer.parseInt(br.readLine());
            arr = new int[N];
            for (int i = 0; i < N; i++)
                arr[i] = Integer.parseInt(br.readLine());
            bw.write(solve());
        }
        bw.flush();
        bw.close();
    }
}