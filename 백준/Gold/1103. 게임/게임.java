import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M;
    static char[][] arr;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new char[N][M];
        dist = new int[N][M];
        visited = new boolean[N][M];
        for (int y = 0; y < N; y++) {
            String row = br.readLine();
            for (int x = 0; x < M; x++) {
                arr[y][x] = row.charAt(x);
                dist[y][x] = -1;
            }
        }
    }

    static int[] dy = { -1, 0, 1, 0 };
    static int[] dx = { 0, 1, 0, -1 };
    static int[][] dist;
    static boolean[][] visited;
    static int dfs(int depth, int y, int x) {
        if (0 > y || y >= N || 0 > x || x >= M) return depth;
        if (dist[y][x] >= depth) return dist[y][x];
        dist[y][x] = depth;
        if (arr[y][x] == 'H') return depth;
        if (visited[y][x]) return 987654321;
        visited[y][x] = true;
        int ret = 0;
        int d = arr[y][x] - '0';
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i] * d, nx = x + dx[i] * d;
            ret = Math.max(ret, dfs(depth + 1, ny, nx));
        }
        visited[y][x] = false;
        return ret;
    }

    public static void main(String[] args) throws IOException {
        input();
        int ans = dfs(0, 0, 0);
        if (ans == 987654321) ans = -1;
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }
}