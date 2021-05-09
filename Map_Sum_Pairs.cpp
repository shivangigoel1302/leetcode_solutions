class trienode{
    public:
    vector<trienode*>alpha;
    int counter;
    int val;
    trienode(){
        alpha.resize(26);
        for(int i = 0 ; i < 26; i++){
            alpha[i] = NULL;
        }
        counter = 0;
        val = 0;
    }
};
class MapSum {
public:
    /** Initialize your data structure here. */
    trienode*head;
    map<string,int>m;
    MapSum() {
        head = new trienode();
    }
    trienode* getnode(trienode* head, char c){
        if(head->alpha[c-'a'] == NULL){
            return NULL;
        }
        return head->alpha[c-'a'];
    }
    void insert(string key, int v) {
        trienode*temp = head;
        int val = v-m[key];
        m[key] = v;
        for(int i = 0 ; i < key.size(); i++){
            char c = key[i];
            auto x = getnode(temp,c);
            if(x == NULL){
                trienode* n = new trienode();
                temp->alpha[c-'a'] = n;
                n->counter = val;
            }
            else{
                //cout<<c<<" ";
                x->counter += val;
            }
            temp = temp->alpha[c-'a'];
        }
        temp->val = val;
        //temp->counter += val;
    }

    int sum(string prefix) {
        trienode*temp = head;
        for(int i = 0; i < prefix.size(); i++){
            char c = prefix[i];
            auto x = getnode(temp,c);
            if(x == NULL){
                return 0;
            }
            temp = x;
        }
        //cout<<temp->val<<" ";
        return temp->counter;
    }
};


/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
