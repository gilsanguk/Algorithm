import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] arr;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static boolean binarySearch(int target) {
        int l = 0, r = N - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == target) return true;
            if (target > arr[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }

    public static void solve() throws IOException {
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            int target = Integer.parseInt(st.nextToken());
            if (binarySearch(target)) bw.write("1\n");
            else bw.write("0\n");
        }
    }


    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        M = Integer.parseInt(br.readLine());
        Arrays.sort(arr);
        solve();
        bw.flush();
        bw.close();
    }
}