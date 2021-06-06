class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() -1;
        
        int ans = 0;
        
        while (i < j) {
            int len = j-i;
            ans = max(ans, len*min(height[i], height[j]));
            if (height[i] < height[j]) i++;
            else j--;
        }
        
        return ans;
    }
};
