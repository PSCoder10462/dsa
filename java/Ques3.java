/**
    @author Himesh Nayak 01216403219
    Write a java program to sort strings.
 */

 import java.util.Arrays;

 class Ques3 {
    public static void main(String[] args)
    {
        String input = "asdfghxcvbnm";
        String output = sortString(input);
          
        System.out.println("Input : " + input);
        System.out.println("Output : " + output);
    }
    public static String sortString(String inputString)
    {
        char tempArray[] = inputString.toCharArray();
        Arrays.sort(tempArray);
        return new String(tempArray);
    }
 }
