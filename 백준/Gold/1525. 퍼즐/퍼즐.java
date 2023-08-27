import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static String S;
    static final String FIN = "123456780";

    public static void input() throws IOException {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++)
                sb.append(st.nextToken());
        }
        S = sb.toString();
    }

    public static String swap(String s, int a, int b) {
        StringBuilder sb = new StringBuilder(s);
        char tmp = sb.charAt(a);
        sb.setCharAt(a, sb.charAt(b));
        sb.setCharAt(b, tmp);
        return sb.toString();
    }

    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static Set<String> dist = new HashSet<>();
    static Queue<String> q = new LinkedList<>();
    public static int bfs() {
        q.offer(S);
        dist.add(S);
        int cnt = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                String cur = q.poll();
                if (cur.equals(FIN)) return cnt;
                int idx = cur.indexOf('0');
                int y = idx / 3, x = idx % 3;
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if (0 > ny || ny > 2 || 0 > nx || nx > 2) continue;
                    int nidx = ny * 3 + nx;
                    String next = swap(cur, idx, nidx);
                    if (dist.contains(next)) continue;
                    q.offer(next);
                    dist.add(next);
                }
            }
            cnt++;
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(String.valueOf(bfs()));
        bw.flush();
        bw.close();
    }
}