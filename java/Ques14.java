 /**
    @author Himesh Nayak 01216403219
    Write a program to generate a fibonacci series.
 */

class Ques14 {
    static int count = 0;
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        System.out.println("Generating Fibonacci Series upto " + n);
        generateFibonacciTillN(0, 1, n);
        System.out.println("\nGenerating Fibonacci Series for " + n + " terms");
        generateFibonacciNTerms(0, 1, n);
    }
    public static void generateFibonacciTillN(int a, int b, int n) {
        if (a > n)
            return;
        System.out.print(a + " ");
        generateFibonacciTillN(b, a+b, n);
    }      
    public static void generateFibonacciNTerms(int a, int b, int n) {
        if (count == n)
            return;
        System.out.print(a + " ");
        count++;
        generateFibonacciNTerms(b, a+b, n);
    }  
}
