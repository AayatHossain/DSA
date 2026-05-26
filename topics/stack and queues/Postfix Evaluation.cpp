Apprach1: Using stack
Time complexity: O(n) where n is the number of elements in the postfix expression
Space complexity: O(n) for the stack
class Solution {
	public:
	
	int calc(int v1, int v2, string t) {
		if (t == "+")return v1 + v2;
		else if (t == "-")return v1 - v2;
		else if (t == "*")return v1*v2;
		else if (t == "/") {
			int q = v1 / v2;
			
			if ((v1 % v2) != 0 && ((v1 < 0) ^ (v2 < 0))) {
				q--;
			}
			
			return q;
		}
		else {
			int a = v1;
			int b = v2;
			int res = 1;
			while (b > 0) {
				if (b & 1) {
					res *= a;
				}
				a *= a;
				b>>= 1;
			}
			return res;
		}
	}
	
	int evaluatePostfix(vector<string>& a) {
		// code here
		int n = a.size();
		stack<int> s;
		for (int i = 0; i < n; i++) {
			bool isChar = a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/"
			 || a[i] == "^" ;
			if (isChar) {
				int v2 = s.top();
				s.pop();
				int v1 = s.top();
				s.pop();
				
				int v = calc(v1, v2, a[i]);
				s.push(v);
			} else {
				s.push(stoi(a[i]));
			}
		}
		return s.top();
		
	}
};
