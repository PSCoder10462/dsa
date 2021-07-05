/**
    @author Himesh Nayak 01216403219
    Write a java program to demonstrate the polymorphism and inheritance.
*/

class BaseClass {
    BaseClass() {
        System.out.println("BaseClass Object Created");
    }
    void show() {
        System.out.println("BaseClass Show");
    }
}

class DerivedClass extends BaseClass {
    DerivedClass() {
        System.out.println("DerivedClass Object Created");
    }
    void show() {
        System.out.println("DerivedClass Show");
    }
}

public class Ques12 {
    public static void main(String[] args) {
        BaseClass b = new BaseClass(); 
        // BaseClass Constructor is called
        DerivedClass d = new DerivedClass(); 
        // BaseClass Constructor is called and then DerviedClass constructor is called
        b.show();
        // BaseClass show method is called
        d.show();
        // DerivedClass overrided the show method, which is called 
    }
}
