import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M;
    static int[] arr;
    static List<List<Integer>> graph;

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1];
        graph = new ArrayList<>(N + 1);
        visited = new boolean[N + 1];
        for (int i = 0; i <= N; i++) graph.add(new ArrayList<>());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int parent = Integer.parseInt(st.nextToken());
            if (parent == -1) continue;
            graph.get(parent).add(i);
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken());
            arr[idx] += Integer.parseInt(st.nextToken());
        }
    }

    static boolean[] visited;
    public static void dfs(int x, int sum) {
        if (visited[x]) return;
        visited[x] = true;
        for (int nxt : graph.get(x))
            dfs(nxt, sum + arr[x]);
        arr[x] += sum;
    }

    public static void solve() throws IOException {
        dfs(1, 0);
        for (int i = 1; i <= N; i++)
            bw.write(arr[i] + " ");
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
        bw.flush();
        bw.close();
    }
}