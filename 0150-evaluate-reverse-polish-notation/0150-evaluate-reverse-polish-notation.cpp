class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) return stoi(tokens[0]);

        stack<int> stk;

        for(string i : tokens){
            if(i != "+" && i != "-" && i != "*" && i != "/"){
                stk.push(stoi(i));
            }
            else if(i == "+"){
                int right_operand = stk.top();
                stk.pop();
                int left_operand = stk.top();
                stk.pop();
                stk.push(left_operand + right_operand);
            }
            else if(i == "-"){
                int right_operand = stk.top();
                stk.pop();
                int left_operand = stk.top();
                stk.pop();
                stk.push(left_operand - right_operand);
            }
            else if(i == "*"){
                int right_operand = stk.top();
                stk.pop();
                int left_operand = stk.top();
                stk.pop();
                stk.push(left_operand * right_operand);
            }
            else{
                int right_operand = stk.top();
                stk.pop();
                int left_operand = stk.top();
                stk.pop();
                stk.push(left_operand / right_operand);
            }
        }
        return stk.top();
    }
};