import java.util.*;

public class ParenthesisMatching {

    public static String positions(int i, int j){

        String pos =  " ("+i+","+j+") ";
        return pos;
    }

    public static void main(String[] args) {
      
        Scanner in = new Scanner(System.in);
      
        Stack<Integer> stack = new Stack<Integer>();
      
        String s = in.nextLine();
      
        String position="";
      
        for (int i = 0; i < s.length(); i++) {
          
            if(s.charAt(i) == '('){
                stack.push(i);
            }
          
            if(s.charAt(i) == ')'){
               position += positions(stack.pop()+1, i+1);
            }
        }
      
        System.out.println(position);
    }
}
