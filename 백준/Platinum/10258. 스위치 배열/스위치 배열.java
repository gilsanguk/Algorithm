import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static String str;

    public static String solve() {
        int ret = 0, flag = 1;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '1') {
                ret += (int) (Math.pow(2, str.length() - i) - 1) * flag;
                flag *= -1;
            }
        }
        return String.valueOf(ret);
    }

    public static void main(String[] args) throws IOException {
        int T;
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            str = br.readLine();
            bw.write(solve() + '\n');
        }
        bw.flush();
        bw.close();
    }
}