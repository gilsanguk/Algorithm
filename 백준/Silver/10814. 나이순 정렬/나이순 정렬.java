import java.io.*;
import java.util.*;

class Person implements Comparable<Person> {
    int age;
    String name;
    Person(int age, String name) {this.age = age; this.name = name;}

    public int compareTo(Person rhs) {
        return age - rhs.age;
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static Person[] arr;

    public static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new Person[N];
        int age;
        String name;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            age = Integer.parseInt(st.nextToken());
            name = st.nextToken();
            arr[i] = new Person(age, name);
        }
    }

    public static void solve() throws IOException {
        Arrays.sort(arr);
        for (int i = 0; i < N; i++)
            bw.write(arr[i].age + " " + arr[i].name + "\n");
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
        bw.flush();
        bw.close();
    }
}