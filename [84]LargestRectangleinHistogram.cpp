class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max = 0;
        int len = height.size();
        
        if (len == 0)
            return max;
        if (len == 1)
            return height[0];
            
        for (int i=0; i<len; ++i)
        {
            int tmp = height[i];
            for (int j=i-1; j>=0; --j)
            {
                if (height[j] <= height[i])
                    tmp += height[j];
                else
                    break;
            }
            
            for (int j=i+1; j<len; ++j)
            {
                if (height[j] <= height[i])
                    tmp += height[j];
                else
                    break;
            }
            
            max = max > tmp? max:tmp;
        }
        
        return max;
    }
};