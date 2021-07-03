/**
    @author Himesh Nayak 01216403219
    Write a java program to insert comma after every 3 digits from the right of a long number entered by user.
 */

 class Ques7 {
    public static void main(String[] args) {
        String input = args[0], output = "";
        System.out.println("Input : " + input);
        for (int i = 0; i < input.length(); i++) {
            if ((input.length() - i) % 3 == 0 && i != 0) {
                output += ",";
            }
            output += input.charAt(i);
        }
        System.out.println(output);
    }
 }
