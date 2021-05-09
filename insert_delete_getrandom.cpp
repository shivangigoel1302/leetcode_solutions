class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    set<int>s;
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int flag=1;
        if(s.find(val)==s.end())
        {
            flag=0;
        }
        s.insert(val);
        if(flag==1)
        {
            return false;
        }
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val)==s.end())
        {
            return false;
        }
        s.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int size=s.size();
        int index=rand()%size;
        auto it=s.begin();
        advance(it,index);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
