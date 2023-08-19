import java.io.*;
import java.util.*;



public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int T;
    static String cmd;

    static int[] dy = { -1, 0, 1, 0 };
    static int[] dx = { 0, 1, 0, -1 };
    public static int solve() {
        int y = 0, x = 0, sy = 0, sx = 0, ey = 0, ex = 0, d = 0;
        for (int i = 0; i < cmd.length(); i++) {
            switch (cmd.charAt(i)) {
                case 'F':
                    y += dy[d];
                    x += dx[d];
                    break;
                case 'B':
                    y -= dy[d];
                    x -= dx[d];
                    break;
                case 'L':
                    d = (d + 1) % 4;
                    break;
                case 'R':
                    d = (d - 1 + 4) % 4;
                    break;
            }
            sy = Math.min(y, sy);
            sx = Math.min(x, sx);
            ey = Math.max(y, ey);
            ex = Math.max(x, ex);
        }
        return (ey - sy) * (ex - sx);
    }

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            cmd = br.readLine();
            bw.write(solve() + "\n");
        }
        bw.flush();
        bw.close();
    }
}