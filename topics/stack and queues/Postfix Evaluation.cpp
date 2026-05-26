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
			bool isOP = a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/"
			 || a[i] == "^" ;
			if (isOP) {
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
