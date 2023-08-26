import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static List<List<Integer>> graph;
    static int[] ans;

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        ans = new int[N];
        visited = new boolean[N + 1];
        graph = new ArrayList<>();
        for (int i = 0; i <= N; i++) graph.add(new ArrayList<>());

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
            graph.get(s).add(e);
            graph.get(e).add(s);
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            ans[i] = Integer.parseInt(st.nextToken());
    }

    static boolean[] visited;
    static Queue<Integer> q = new LinkedList<>();
    static String bfs() {
        if (ans[0] != 1) return "0";
        q.offer(1);
        visited[1] = true;
        int idx = 1;
        Set<Integer> set = new HashSet<>();
        while (!q.isEmpty()) {
            int x = q.poll();
            set.clear();
            for (int nx : graph.get(x)) {
                if (visited[nx]) continue;
                visited[nx] = true;
                set.add(nx);
            }
            for (int i = 0; i < set.size(); i++) {
                if (!set.contains(ans[idx])) return "0";
                q.offer(ans[idx++]);
            }
        }
        return "1";
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(bfs());
        bw.flush();
        bw.close();
    }
}