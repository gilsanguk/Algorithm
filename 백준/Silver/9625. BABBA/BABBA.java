import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int K;
    static int A, B;

    private static void solve() {
        A = 1;
        B = 0;
        while (K > 0) {
            int tmpA = A;
            A = B;
            B += tmpA;
            K--;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        K = Integer.parseInt(br.readLine());
        solve();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(A) + " " + String.valueOf(B));
        bw.flush();
        bw.close();
    }
}
