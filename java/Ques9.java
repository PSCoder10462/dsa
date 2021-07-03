/**
    @author Himesh Nayak 01216403219
    Write your own exception class that catch error when the number inputted by user is not between 25 to 100?
 */

class Ques9 {
    public static void main(String[] args) throws NotBetween25To100Exception {
        int num = Integer.parseInt(args[0]);
        try {
            if (num > 100 || num < 25)
                throw new NotBetween25To100Exception("Number not between 25 and 100");
            else 
                System.out.println("Number entered is between 25 and 100");
        } catch (NotBetween25To100Exception e) {
            System.out.println("NotBetween25To100Exception Occured : " + e);
        }
    }
}

class NotBetween25To100Exception extends Exception {
    String message;
    public NotBetween25To100Exception(String message) {
        this.message =  message;
    }
    @Override 
    public String toString() {
        return message;
    }
}
