class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        if (len1 + len2 != len3)
            return false;
        
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        
        dp[0][0] = true;
        for (int i=1; i<=len1; ++i)
            if (s1[i-1] == s3[i-1])
                dp[i][0] = true;
        
        for (int i=1; i<=len2; ++i)
            if (s2[i-1] == s3[i-1])
                dp[0][i] = true;
        
        for (int i=1; i<=len1; ++i)
        {
            for (int j = 1; j<=len2; ++j)
            {
                if (dp[i-1][j] == true && s1[i-1] == s3[i+j-1])
                {
                    dp[i][j] = true;
                    continue;
                }
                
                if (dp[i][j-1] == true && s2[j-1] == s3[i+j-1])
                {
                    dp[i][j] = true;
                    continue;
                } 
            }
        }
        
        return dp[len1][len2];
    }
};