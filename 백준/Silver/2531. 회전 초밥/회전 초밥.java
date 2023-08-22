import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, d, k, c;
    static int[] arr;
    static Map<Integer, Integer> cnt = new HashMap<>();
    static Deque<Integer> dq = new LinkedList<>();

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(br.readLine());
        cnt.put(c, 1);
    }

    static void solve() throws IOException {
        int ans = 0;
        for (int i = 0; i < N + k; i++) {
            int idx = i % N;
            dq.addLast(arr[idx]);
            cnt.put(arr[idx], cnt.getOrDefault(arr[idx], 0) + 1);
            if (dq.size() == k) {
                ans = Math.max(ans, cnt.size());
                int s = dq.removeFirst();
                cnt.put(s, cnt.get(s) - 1);
                if (cnt.get(s) == 0) cnt.remove(s);
            }
        }
        bw.write(ans + "");
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
        bw.flush();
        bw.close();
    }
}