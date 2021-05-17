class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            if(st.size() == 0){
                return false;
            }
            
            else if(s[i] == ')'){
                char p = st.top();
                st.pop();
                if(p == '{' || p == '['){
                    return false;
                    break;
                }
            }
            else if(s[i] == ']'){
                 char p = st.top();
                st.pop();
                if(p == '{' || p == '('){
                    return false;
                    break;
                }
            }
            else if(s[i] == '}'){
                 char p = st.top();
                st.pop();
                if(p == '(' || p == '['){
                    return false;
                    break;
                }
            }
        }
        if(st.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};