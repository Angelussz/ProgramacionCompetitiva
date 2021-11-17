class Solution {
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int result ;

    string strP = text1.substr(0,text1.size()-1);
    string strQ = text2.substr(0,text2.size()-1);
    if (text1.size() == 0 || text2.size() == 0)
    {
        // cout<<P;
        result = 0;
    }
    
    else if(text1[text1.size()-1] == text2[text2.size()-1]){
        // cout<<str1<<" "<<str2<<"\n";
        result = 1 + longestCommonSubsequence(strP,strQ);
    }else{
        int a = longestCommonSubsequence(strP,text2);
        int b = longestCommonSubsequence(text1,strQ);
        result = max(a,b);
    }
    return result;
    }
    
};