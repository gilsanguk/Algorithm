import java.io.*;
import java.util.*;



public class Main {

    static class Edge implements Comparable<Edge> {
        int from, to, w;

        Edge(int from, int to, int w) {
            this.from = from;
            this.to = to;
            this.w = w;
        }

        @Override
        public int compareTo(Edge rhs) {
            return this.w - rhs.w;
        }
    }

    static int N, M, total;
    static List<Edge> graph;
    static int[] parent;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static boolean input() throws IOException {
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        if (M == 0 && N == 0) return true;
        graph = new ArrayList<>();
        parent = new int[M];
        total = 0;
        int x, y, z;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            z = Integer.parseInt(st.nextToken());
            total += z;
            graph.add(new Edge(x, y, z));
        }
        for (int i = 0; i < M; i++)
            parent[i] = i;
        return false;
    }

    public static int solve() {
        int ans = 0;
        Collections.sort(graph);
        for (int i = 0; i < N; i++) {
            Edge e = graph.get(i);
            if (find(e.from) == find(e.to)) continue;
            union(e.from, e.to);
            ans += e.w;
        }
        return total - ans;
    }

    public static int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) parent[x] = y;
    }

    public static void main(String[] args) throws IOException {
        while (!input()) {
            bw.write(solve() + "\n");
        }
        bw.flush();
        bw.close();
    }
}