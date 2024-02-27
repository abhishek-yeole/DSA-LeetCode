class Solution {
public:
    void solve(int index, string digits, vector<string>&mapping, vector<string>&result, string output){
        //Base casee
        if(index >= digits.length()){
            result.push_back(output);
            return;
        } 
        //1 case hmko baaki recursion smbhal lega
        int digit = digits[index] - '0';
        string value = mapping[digit];
        for(int i=0; i<value.length(); i++){
            char ch = value[i];
            //include
            output.push_back(ch);
            solve(index+1, digits, mapping, result, output);
            //backtraking
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        string output = "";
        if(digits.length() == 0)
            return result;
        int index = 0;
        vector<string>mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        solve(index, digits, mapping, result, output);
        
        return result;
    }
};