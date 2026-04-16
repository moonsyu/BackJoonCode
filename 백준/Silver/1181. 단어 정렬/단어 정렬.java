import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        ArrayList<String> answer = new ArrayList<>();
       
        for(int i = 0; i < n; i++){
            String word = sc.next();
            answer.add(word);
        }
        
        Collections.sort(answer, (s1, s2) -> {
            if(s1.length() != s2.length()){
                return s1.length() - s2.length();
            }
            return s1.compareTo(s2);
        });

        String pre = "";
        for(String ans : answer){
            if (!pre.equals(ans)){
                System.out.println(ans);
            }
            pre = ans;
        }
    }
}
