Approach: Using a stack.
Time complexity: O(n)
Space complexity: O(n) for the stack

class Solution
{
public:
    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    string infixToPostfix(string &t)
    {
        int n = t.size();
        stack<char> s;
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            char c = t[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                ans += c;
            }
            else if (c == '(')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    ans += s.top();
                    s.pop();
                }
                s.pop();
            }
            else    
            {
                while (!s.empty() &&
                       (prec(s.top()) > prec(c) ||
                        (prec(s.top()) == prec(c) && c != '^')))
                {
                    ans += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }

        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};
