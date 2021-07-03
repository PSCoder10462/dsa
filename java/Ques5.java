/**
    @author Himesh Nayak 01216403219
    Write a java program to print series of student record using multi dimensional arrays.
 */

 import java.util.Arrays;

 class Ques5 {
    public static void main(String[] args) {
        String[][][] student_arr= {
            {
                {"Himesh", "01216403219", "9812345654"},
                {"C++", "Java", "Kotlin"}
            },
            {
                {"Parv", "02416403219", "9847654312"},
                {"C", "Python", "Javascript"},
            }
        };
        // retrieve all the elements from 3D array
        int i, j, k;
 
        for (i = 0; i<2; i++) {
            System.out.println("Name: " + student_arr[i][0][0]);
            System.out.println("Roll Number: " + student_arr[i][0][1]);
            System.out.println("Phone Number: " + student_arr[i][0][2]);
            System.out.print("Subjects : ");
            for (k= 0; k<3; k++) {
                System.out.print(student_arr[i][1][k]+ "\t");
            }
            System.out.println();
            System.out.println();
        } 
    }
 }
