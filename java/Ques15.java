/**
    @author Himesh Nayak 01216403219
    Write a program to find whether the number inputted by user is prime or not.
 */

import java.util.Scanner;

class Ques15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number to check prime or not: ");
        int n = sc.nextInt();
        System.out.println(n + " is " + checkPrime(n));
    }
    public static String checkPrime(int n) {
        for (long i = 2; i*i < n; i++) {
            if (n % i == 0) {
                return "Not Prime";
            }
        }
        return "Prime";
    }
}
