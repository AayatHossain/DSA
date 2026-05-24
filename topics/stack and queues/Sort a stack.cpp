Approach: Using a temporary stack to sort the elements in the given stack.
Time complexity: O(n^2) in worst case when the stack is sorted in reverse order
Space complexity: O(n) for the temporary stack

class Solution
{
public:
    void sortStack(stack<int> &s)
    {
        // code here
        stack<int> t;
        while (!s.empty())
        {
            int v = s.top();
            s.pop();
            if (t.empty())
            {
                t.push(v);
            }
            else
            {
                if (v > t.top())
                {
                    while (!t.empty() && v > t.top())
                    {
                        s.push(t.top());
                        t.pop();
                    }
                }
                t.push(v);
            }
        }

        while (!t.empty())
        {
            s.push(t.top());
            t.pop();
        }
    }
};



Approach 2: Using recursion to sort the stack.
Time complexity: O(n^2) in worst case when the stack is sorted in reverse order
Space complexity: O(n) for the recursive stack

class Solution
{
public:

    void push_el(stack<int> &s, int x){
        if(s.empty())return;

        if(s.top() <= x){
            s.push(x);
            return;
        }

        int v = s.top();
        s.pop();

        push_el(s,x);
        s.push(v);
    }


    void sort(stack<int> &s){
        if(s.empty())return;

        int v = s.top();
        s.pop();

        rec(s);
        push_el(s,v);
        
    }

    void sortStack(stack<int> &s)
    {
        sort(s);
    }
};
