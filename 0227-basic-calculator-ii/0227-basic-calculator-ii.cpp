class Solution {
public:

    int prec(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='*' || c=='/'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }

    string infixtopostfix(string s){

        stack<char> st;
        string res;

        char prev = '(';

        for(int i=0; i<s.length(); i++){

            if(s[i]==' ')
                continue;

            // Number
            if(s[i]>='0' && s[i]<='9'){

                while(i<s.length() &&
                      s[i]>='0' && s[i]<='9'){

                    res += s[i];
                    i++;
                }

                res += ' ';       // IMPORTANT
                i--;
                prev = 'n';
            }

            // (
            else if(s[i]=='('){

                st.push(s[i]);
                prev = '(';
            }

            // )
            else if(s[i]==')'){

                while(!st.empty() && st.top()!='('){

                    res += st.top();
                    res += ' ';   // separator
                    st.pop();
                }

                if(!st.empty())
                    st.pop();

                prev = ')';
            }

            // Operator
            else{

                // Unary + or -
                if((s[i]=='+' || s[i]=='-') &&
                   (prev=='(' || prev=='+' || prev=='-' ||
                    prev=='*' || prev=='/' || prev=='^')){

                    res += "0 ";
                }

                while(!st.empty() &&
                      st.top()!='(' &&
                      prec(st.top()) >= prec(s[i])){

                    res += st.top();
                    res += ' ';
                    st.pop();
                }

                st.push(s[i]);
                prev = s[i];
            }
        }

        // Remaining operators
        while(!st.empty()){

            res += st.top();
            res += ' ';
            st.pop();
        }

        return res;
    }


    int postfixeval(string s){

        stack<long long> st;

        for(int i=0; i<s.length(); i++){

            if(s[i]==' ')
                continue;

            // Number
            if(s[i]>='0' && s[i]<='9'){

                long long num=0;

                while(i<s.length() &&
                      s[i]>='0' && s[i]<='9'){

                    num = num*10 + (s[i]-'0');
                    i++;
                }

                st.push(num);
                i--;
            }

            // Operator
            else{

                long long op2 = st.top();
                st.pop();

                long long op1 = st.top();
                st.pop();

                if(s[i]=='+')
                    st.push(op1+op2);

                else if(s[i]=='-')
                    st.push(op1-op2);

                else if(s[i]=='*')
                    st.push(op1*op2);

                else if(s[i]=='/')
                    st.push(op1/op2);

                else if(s[i]=='^')
                    st.push(pow(op1,op2));
            }
        }

        return st.top();
    }


    int calculate(string s){

        string p = infixtopostfix(s);

        return postfixeval(p);
    }
};