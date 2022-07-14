#include <unordered_set>
void recurse(string str, int indx, unordered_set<string> &umap, vector<string> &ans) {
    int beg = indx;
    if(indx >= str.length()) {
        ans.push_back(str);
        return;
    }
    while(indx <= str.length()) {
        if(umap.find(str.substr(beg, indx - beg)) != umap.end()) {
            str.insert(indx, " ");
            recurse(str, indx+1, umap, ans);
            str.erase(indx, 1);
        }
        ++indx;
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary) {
    unordered_set<string> umap(dictionary.begin(), dictionary.end());
    vector<string> ans;
    recurse(s, 0, umap, ans);
    return ans;
}