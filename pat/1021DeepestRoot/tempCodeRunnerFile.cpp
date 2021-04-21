int check(vector<int> root){
    set<int> res;
    for(int i=0;i<root.size();i++){
        res.insert(getRoot(root,i));
    }
    return res.size();
};