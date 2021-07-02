/**
    @author Himesh Nayak 01216403219
    Write a java program to find the factorial of a number.
 */

 class Ques4 {
    public static void main (String[] args) {
        int num = 5;
        long factorial = generateFactorial(num);
        System.out.println("Factorial of " + num + " is : " + factorial);
    }
    public static long generateFactorial(int num) {
        if (num == 1)
            return 1;
        return num * generateFactorial(num - 1);
    }
 }
