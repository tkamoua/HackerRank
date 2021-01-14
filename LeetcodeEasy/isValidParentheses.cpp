class Solution {
public:
    // loop through string
    // add each character to stack
    // add opening brackets to stack
    // if closing bracket, pop from stack
    int isInputChar(char c){
        if(c == '{' || c == '(' || c =='['){
            return true;
        }
        else{
            return false;
        }
    }

    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> out_in;
        out_in[']']= '[';
        out_in[')'] = '(';
        out_in['}'] = '{';
        
        for(int i = 0; i < s.length();++i){
            if(isInputChar(s[i])){
                st.push(s[i]); 
            }
            else{
                auto it = out_in.find(s[i]);
                
                if(st.empty()){
                    return false;
                }
                if(it->second == st.top()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
    }
    return true;
    }
};
