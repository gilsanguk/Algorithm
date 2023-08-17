import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static String txt;
    static String pat;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void input() throws IOException {
        txt = br.readLine();
        pat = br.readLine();
        N = txt.length();
        M = pat.length();
    }

    public static int solve() {
        int cnt = 0;
        for (int i = 0; i < N - M + 1; i++) {
            if (txt.substring(i, i + M).equals(pat)){
                cnt++;
                i += M - 1;
            }
        }
        return cnt;
    }

    static int T;
    public static void main(String[] args) throws IOException {
        input();
        bw.write(solve() + "");
        bw.flush();
        bw.close();
    }
}