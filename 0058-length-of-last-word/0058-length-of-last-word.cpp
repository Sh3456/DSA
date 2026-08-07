class Solution {
public:
    int lengthOfLastWord(string s) {
        while(!s.empty()&&s.front()==' '){
            s.erase(0,1);
        }
        while(!s.empty() && s.back()==' '){
            s.pop_back();
        }
        vector<string>sss;
    int i=0;
        while(i<s.size()){

            while(i<s.size() && s[i]==' '){
                    i++;
            }
            string word="";
            while(i<s.size() && s[i]!=' '){
                    word+=s[i];
                    i++;
            }
            if(!word.empty()){
                sss.push_back(word);
            }
        }
      return sss.back().size();
    }
       
  
};