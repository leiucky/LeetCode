//暴力 o(n2)
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


//stack,o(n)

class Solution {
public:
    int Max(int a, int b){return a > b ? a : b;}
    int largestRectangleArea(vector<int> &height) {
    	height.push_back(0);
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while(i < height.size()){
            if(stk.empty() || height[stk.top()] <= height[i]){
                stk.push(i++);
            }else {
                int t = stk.top();
				stk.pop();
                maxArea = Max(maxArea, height[t] * (stk.empty() > 0 ? i : i - stk.top() - 1));
            }
        }
        return maxArea;
    }
};