#include<iostream>
using namespace std;
class Solution{
public:

    string longestPalindrome(string s){
        int n=s.size();
        string result="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    if((j-i+1)>result.size()){
                        result=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return result;
    }


private:
bool isPalindrome(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};