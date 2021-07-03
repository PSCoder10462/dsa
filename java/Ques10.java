/**
    @author Himesh Nayak 01216403219
    Write a java program to copy one file to other.
 */

import java.io.*;
import java.util.*;
  
public class Ques10 {
    
    public static void copyContent(File s, File d) throws Exception {
        FileInputStream in = new FileInputStream(s);
        FileOutputStream out = new FileOutputStream(d);
  
        try {
           int n;
              while ((n = in.read()) != -1) {
                out.write(n);
            }
        } finally {
            if (in != null) {
                in.close();
            }
            if (out != null) {
                out.close();
            }
        }
        System.out.println("File Copied");
    } 
  
    public static void main(String[] args) throws Exception
    {
        // source file
        File source = new File("sourceFile.txt");
  
        // destination file
        File destination = new File("destinationFile.txt");
  
        copyContent(source, destination);
    }
}
