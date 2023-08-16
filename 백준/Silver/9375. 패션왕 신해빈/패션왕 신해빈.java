import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static Map<String, Integer> m;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static void solve() throws IOException {
        N = Integer.parseInt(br.readLine());
        m = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String key = br.readLine().split(" ")[1];
            if (m.containsKey(key)) m.put(key, m.get(key) + 1);
            else m.put(key, 1);
        }
        Integer ans = m.values().stream()
                .reduce(1, (a, b) -> a * (b + 1));
        bw.write(ans - 1 + "\n");
    }

    static int T;
    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            solve();
        }
        bw.flush();
        bw.close();
    }
}