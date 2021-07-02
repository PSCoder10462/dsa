/**
    @author Himesh Nayak 01216403219
    Write a java program to sort array of integers
 */

 class Ques2 {
    public static void main (String[] args) {

        Ques2 q = new Ques2();

        int nums[] = {3, 3, 4, 1, 0, 6, 5};
        System.out.print("Unsorted Array : ");
        q.printArray(nums);
        q.sort(nums);
        System.out.print("Sorted Array : ");
        q.printArray(nums);
    }

    void sort(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length - 1; j++) {
                if (nums[j] > nums[j+1]) {
                    int t = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = t;
                }
            }
        }
    }

    void printArray (int[] nums) {
        for(int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("");
    }
 }
