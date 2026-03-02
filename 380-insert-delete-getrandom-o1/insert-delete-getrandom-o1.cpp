class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            v.push_back(val);
            mp[val] = v.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int idx = mp[val];
            swap(v[idx],v[v.size()-1]);
            mp[v[idx]] = idx;
            mp.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int ind = rand() % v.size();
        return v[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */