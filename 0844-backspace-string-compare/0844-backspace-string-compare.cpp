class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> st;
        stack<char> ts;

        // Process string s
        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '#') {
                if(!st.empty())
                    st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        string res = "";

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());


        // Process string t
        for(int j = 0; j < t.size(); j++) {

            if(t[j] == '#') {
                if(!ts.empty())
                    ts.pop();
            }
            else {
                ts.push(t[j]);
            }
        }

        string ress = "";

        while(!ts.empty()) {
            ress += ts.top();
            ts.pop();
        }

        reverse(ress.begin(), ress.end());

        return res == ress;
    }
};