import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, K;
    static List<Integer> sensor = new ArrayList<>();

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            sensor.add(Integer.parseInt(st.nextToken()));
        }
    }

    static void solve() throws IOException {
        sensor = sensor.stream().distinct().collect(Collectors.toList());
        Collections.sort(sensor);
        int ans = sensor.get(sensor.size() - 1) - sensor.get(0);
        List<Integer> tmp = new ArrayList<>();
        for (int i = 0; i < sensor.size() - 1; i++) {
            tmp.add(sensor.get(i + 1) - sensor.get(i));
        }
        tmp.sort((a, b) -> b - a);
        for (int i = 0; i < Math.min(tmp.size(), K - 1); i++) {
            ans -= tmp.get(i);
        }
        bw.write(ans + "");
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
        bw.flush();
        bw.close();
    }
}