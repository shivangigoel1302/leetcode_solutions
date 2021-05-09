class ThroneInheritance {
public:
    string root;
    ThroneInheritance(string kingName) {
        // class TreeNode*{
        //   string val;
        //    TreeNode* right;
        //     TreeNode*left;
        // };
        // TreeNode* root->val = kingName;
        // root->right = NULL;
        // root->left = NULL;
        root = kingName;
    }
    map<string,vector<string>>m;
    set<string>dead;
    void birth(string parentName, string childName) {
        m[parentName].push_back(childName);
    }

    void death(string name) {
        dead.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string>order;
        dfs(order,root);
        return order;
    }
    void dfs(vector<string>&order,string root){
        if(dead.find(root) == dead.end()){
            order.push_back(root);
        }
        for(auto child : m[root]){
            dfs(order,child);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
