import java.io.*;
import java.util.*;

class Solution {
    public String[] solution(String my_str, int n) {
        int len = my_str.length();
        List<String> answer = new ArrayList<>();
        for (int i = 0; i < len / n; i++) {
            answer.add(my_str.substring(i * n, (i + 1) * n));
        }
        if (len % n != 0) {
            answer.add(my_str.substring(len - len % n));
        }
        return answer.toArray(new String[0]);
    }
}