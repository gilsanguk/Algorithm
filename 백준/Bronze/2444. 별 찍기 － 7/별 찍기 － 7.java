import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt() - 1;
    for (int i = -n; i <= n; i++) {
      int s = Math.abs(i);
      System.out.println(" ".repeat(s)+"*".repeat(2*(n-s)+1));
    }
  }
}