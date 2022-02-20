/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start

class Solution {
public:
    bool isalpha(char a){
        if((a>=65 && a<=90)||(a>=97 && a<=122)){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
        char temp ;
        // string s=a;
        for(int i=0,j=s.length()-1;i<j;){
            //if letter then we add s[i] which is started from behind
            if(isalpha(s[i]) && isalpha(s[j])){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;j--;
            }
            else if(!isalpha(s[i])){
                i++;
            }
            else if(!isalpha(s[j])){
                j--;
            }
            else{
                i++;j--;
            }                
        }   
        return s;        
    }
};
// @lc code=end

