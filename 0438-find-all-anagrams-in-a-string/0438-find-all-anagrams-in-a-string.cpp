class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>freqP;
        unordered_map<char,int>freqS;
        vector<int>ans;
        if(p.size()>s.size()){
            return ans;
        }
        for(int i=0;i<p.size();i++){
            freqP[p[i]]++;
        }

        for(int i=0;i<p.size();i++){
            freqS[s[i]]++;
        }


        if(freqS==freqP){
        ans.push_back(0);
        }
        
        for(int j=p.size();j<s.size();j++){
                 freqS[s[j]]++;

                 freqS[s[j-p.size()]]--;
                
                 if(freqS[s[j-p.size()]] == 0){
                freqS.erase(s[j-p.size()]);
            }
                  if(freqS==freqP){
                     ans.push_back(j-p.size()+1);

        }

        }
            return ans;
    }
};