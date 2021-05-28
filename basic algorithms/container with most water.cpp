int maxArea(vector<int>& height) {
    int i=0, j = height.size()-1;
    int ma = 0;
    while (i<j) {
        int h = min(height[i], height[j]);
        int w = j-i;
        ma = max(ma, h*w);
       	if (height[j] > height[i]) i++;
        else j--;
    }
    return ma;
}
