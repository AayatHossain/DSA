Approach 1: Using two traversals, one from left to right and another from right to left.
Time complexity: O(n)
Space complexity: O(1)

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