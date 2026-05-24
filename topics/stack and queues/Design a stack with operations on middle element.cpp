#include <bits/stdc++.h>
using namespace std;

// Stack strcutre
class myStack
{
    stack<int> s;
    deque<int> q;

public:
    myStack() {}

    void push(int data)
    {
        q.push_back(data);
        if (s.size() < q.size())
        {
            s.push(q.front());
            q.pop_front();
        }
    }

    int pop()
    {
        if (s.empty() && q.empty())
            return -1;
        if (q.empty())
        {
            int ans = s.top();
            s.pop();
            return ans;
        }
        int ans = q.back();
        q.pop_back();
        if (s.size() > q.size() + 1)
        {
            q.push_front(s.top());
            s.pop();
        }
        return ans;
    }

    int findMiddle()
    {
        if (s.empty())
            return -1;
        return s.top();
    }

    void deleteMiddle()
    {
        if (s.empty())
            return;
        s.pop();
        if (s.size() < q.size())
        {
            s.push(q.front());
            q.pop_front();
        }
    }
};

int main()
{
    myStack st;
    st.push(1);
    st.push(2);
    cout << st.findMiddle() << " ";
    st.deleteMiddle();
    cout << st.pop();
    return 0;
}