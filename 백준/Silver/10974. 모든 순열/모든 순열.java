import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static List<int[]> ans = new ArrayList<>();

    static boolean[] visited;
    public static void backtrack(int n, int[] tmp) {
        if (n == N) {
            ans.add(tmp.clone());
            return;
        }
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            tmp[n] = i + 1;
            backtrack(n + 1, tmp);
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        visited = new boolean[N];
        backtrack(0, new int[N]);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int[] arr : ans) {
            for (int i : arr) {
                bw.write(i + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}