import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int n, i;
    Node(int n, int i) {this.n = n; this.i = i;}

    public int compareTo(Node rhs) {
        return rhs.n - n;
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static Integer[] A, B;

    public static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        A = new Integer[N]; B = new Integer[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            A[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            B[i] = Integer.parseInt(st.nextToken());
    }

    public static String solve() {
        Arrays.sort(A, (a, b) -> b - a);
        Arrays.sort(B);
        int ans = 0;
        for (int i = 0; i < N; i++)
            ans += A[i] * B[i];
        return String.valueOf(ans);
    }

    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve());
        bw.flush();
        bw.close();
    }
}