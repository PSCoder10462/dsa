class Solution {
public:
    
    int mySqrt(int x) {
        
        long long hi = 46341, lo=0;
        
        if ( x > 0 && x <= 3) return 1;
        
        while (hi >= lo) {
            long long mid = (hi+lo)/2;
            
            if (mid*mid == x) return mid;
            
            if ((mid-1)*(mid-1) <= x && x < mid*mid) return mid-1;
            
            if (mid*mid > x) hi = mid-1;
            
            else lo = mid+1;
        }
     
        return 0;
    }
};
