import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr;
    static final int INF = 1987654321;
    static int maxV = -INF, minV = INF;
    static int[] operator = {0, 0, 0, 0};

    public static int cal(int acc, int cur, int op) {
        if (op == 0) return acc + cur;
        if (op == 1) return acc - cur;
        if (op == 2) return acc * cur;
        return acc / cur;
    }

    public static void backtrack(int n, int tmp) {
        if (n == N) {
            maxV = Math.max(maxV, tmp);
            minV = Math.min(minV, tmp);
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (operator[i] == 0) continue;
            operator[i]--;
            backtrack(n + 1, cal(tmp, arr[n], i));
            operator[i]++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++)
            operator[i] = Integer.parseInt(st.nextToken());
        backtrack(1, arr[0]);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(maxV + "\n" + minV);
        bw.flush();
        bw.close();
    }
}