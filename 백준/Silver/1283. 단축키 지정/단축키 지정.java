import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static boolean[] arr;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static boolean isPossible(String str, char c) {
        if ('a' <= c && c <= 'z') {
            if (!arr[c - 'a']) {
                arr[c - 'a'] = true;
                return true;
            }
        } else if ('A' <= c && c <= 'Z') {
            if (!arr[c - 'A']) {
                arr[c - 'A'] = true;
                return true;
            }
        }
        return false;
    }

    public static String solve(String str) {
        for (int j = 0; j < str.length(); j++) {
            if (j == 0 || str.charAt(j - 1) == ' ') {
                char c = str.charAt(j);
                if (c == ' ') continue;
                if (isPossible(str, c)) {
                    return str.substring(0, j) + '[' + c + ']' + str.substring(j + 1);
                }
            }
        }
        for (int j = 0; j < str.length(); j++) {
            char c = str.charAt(j);
            if (c == ' ') continue;
            if (isPossible(str, c)) {
                return str.substring(0, j) + '[' + c + ']' + str.substring(j + 1);
            }
        }
        return "";
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new boolean[27];
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            String s = solve(str);
            if (s.isEmpty()) bw.write(str + "\n");
            else bw.write(s + "\n");
        }
        bw.flush();
        bw.close();
    }
}