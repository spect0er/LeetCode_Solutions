class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(int i = 0 ; i < queries.size() ; i++){
            for(int j = 0 ; j < dictionary.size() ; j++){
                int diff = 0;
                string q = queries[i];
                string d = dictionary[j];
                for(int k = 0 ; k < d.size() ; k++){
                    if(q[k] != d[k]){
                        diff++;
                    }
                    if(diff > 2){
                        break;
                    }
                }
                if(diff <= 2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};