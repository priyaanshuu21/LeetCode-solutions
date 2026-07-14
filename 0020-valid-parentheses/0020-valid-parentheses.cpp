class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        for (char &c : s){
            if(c == '{' || c == '(' || c == '[') stk.push(c);
            else{
                if(stk.empty()) return false; //if there is closing bracket before opening.
                char top = stk.top();
                if(c == ')' && top != '(' || c == '}' && top != '{' || c == ']' && top != '[') return false;
                stk.pop();
            }
        }
        //by this we should get an empty stack
        return stk.empty();
    }
};