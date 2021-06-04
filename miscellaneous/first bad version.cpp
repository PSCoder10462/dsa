// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int func(int lo, int hi) {
        
        map <int, int> mp;

        if (isBadVersion(1)) return 1;
        else mp[1] = 1;
        
        while (lo <= hi) {
        
            int mid = ((long long)lo+hi)/2;

            bool a, b, c;

            if (!mp[mid-1]) {
                a = isBadVersion(mid-1);
                mp[mid-1] = a ? 2 : 1;
            } else 
                a = (mp[mid-1] == 2);
            if (!mp[mid]) {
                b = isBadVersion(mid);
                mp[mid] = b ? 2 : 1;
            } else 
                b = (mp[mid] == 2);
            if (!mp[mid+1]) {
                c = isBadVersion(mid+1);
                mp[mid+1] = c ? 2 : 1;
            } else 
                c = (mp[mid+1] == 2);


            if (!a && b) return mid;

            if (!b && c) return mid+1;

            if (!b && !c) lo = mid + 1;

            else hi = mid - 1;
        }
        return 1;
    }
    
    int firstBadVersion(int n) {
        return func(1, n);
    }
};
