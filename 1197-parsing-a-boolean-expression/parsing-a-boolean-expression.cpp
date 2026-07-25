class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char c : expression) {
            if (c == '(' || c == ',')
                continue;
            if (c != ')') {
                st.push(c);
            } else {
                int t = 0, f = 0;
                while (st.top() == 't' || st.top() == 'f') {
                    if (st.top() == 't')
                        t++;
                    else
                        f++;
                    st.pop();
                }
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(f ? 't' : 'f');
                }
                else if (op == '&') {
                    st.push(f ? 'f' : 't');
                }
                else { 
                    st.push(t ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};