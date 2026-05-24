Approach 1 : Using two traversals, one from left to right and another from right to left.Time complexity : O(n) Space complexity : O(1)

                                                                                                                                       class Solution
{
public:
    int maxLength(string &s)
    {
        int n = s.size();
        int co = 0, cc = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                co++;
            else
                cc++;

            if (co < cc)
            {
                co = cc = 0;
            }
            else if (co == cc)
            {
                ans = max(ans, 2 * co);
            }
        }

        co = 0, cc = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                co++;
            else
                cc++;

            if (cc < co)
            {
                co = cc = 0;
            }
            else if (co == cc)
            {
                ans = max(ans, 2 * cc);
            }
        }
        return ans;
    }
};

Approach 2: Using a stack.
Time complexity: O(n)   
Space complexity: O(n) for the stack

class Solution
{
public:
    int maxLength(string &s)
    {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

Approach 3: dynamic programming.
Time complexity: O(n)
Space complexity: O(n) for the dp array

class Solution
{
public:
    int maxLength(string &s)
    {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if(s[i-1] == '('){
                    if(i-2 >= 0){
                        dp[i] = dp[i-2] + 2;
                    }else{
                        dp[i] = 2;
                    }
                }else if(i-dp[i-1] -1 >= 0 && s[i-dp[i-1] -1] == '('){
                    if(i-dp[i-1]-2 >= 0){
                        dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                    }else{
                        dp[i] = dp[i-1] + 2;
                    }
                    
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};