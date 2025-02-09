class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> revmap;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.count(index)){
            int no=mp[index];
            revmap[no].erase(index);
            if(revmap[no].size()==0) revmap.erase(no);
        }

        mp[index]=number;
        revmap[number].insert(index);
        
    }
    
    int find(int number) {
        if(revmap.count(number)==0)
            return -1;
        return *(revmap[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */