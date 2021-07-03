/**
    @author Himesh Nayak 01216403219
    Write a java program to handle multiple exceptions? Use multiple catch statements.
 */

 class Ques8 {
    public static void main(String[] args) {
        try {
            System.out.println(args[0] + " / " + args[1] + " = " + Integer.parseInt(args[0]) / Integer.parseInt(args[1]));
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException occured : " + e);
        } catch (NumberFormatException e) {
            System.out.println("NumberFormatException occured : " + e);
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException occured : " + e);
        } finally {
            System.out.println("Program ended!");
        }
    }
 }
