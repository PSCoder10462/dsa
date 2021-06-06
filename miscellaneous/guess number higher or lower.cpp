/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = ((long long)lo+hi)/2;
            int x = guess(mid);
            switch(x) {
                case 0:
                    return mid;
                case 1:
                    lo = mid+1;
                    break;
                case -1: 
                    hi = mid-1;
                    break;
            }
        }
        return -1;
    }
};
