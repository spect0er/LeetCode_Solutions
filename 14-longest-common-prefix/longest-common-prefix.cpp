class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string st = "";
        for(int i = 0 ; i < strs[0].size() ; i++){
            char c = strs[0][i];
            for(int j = 0 ; j < strs.size() ; j++){
                if(st.size() == strs[j].size()) return st;
                if(c != strs[j][i]) return st;
            }
            st += c;
        }
        return st;
    }

};