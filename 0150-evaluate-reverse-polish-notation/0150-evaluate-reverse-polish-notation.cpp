class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st_num;

        for (const string& str : tokens) {
            if (str == "+") {
                int num1 = st_num.top();
                st_num.pop();
                int num2 = st_num.top();
                st_num.pop();
                st_num.push(num1 + num2);
            } else if (str == "-") {
                int num1 = st_num.top();
                st_num.pop();
                int num2 = st_num.top();
                st_num.pop();
                st_num.push(num2 - num1);
            } else if (str == "*") {
                int num1 = st_num.top();
                st_num.pop();
                int num2 = st_num.top();
                st_num.pop();
                st_num.push(num1 * num2);
            } else if (str == "/") {
                int num1 = st_num.top();
                st_num.pop();
                int num2 = st_num.top();
                st_num.pop();
                st_num.push(num2 / num1);
            } else {
                st_num.push(stoi(str));
            }
        }

        return st_num.top();
    }
};