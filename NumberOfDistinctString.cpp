class Trie {
    vector<Trie*> next;
public:
    Trie() : next(26, 0) { }
    Trie* contains(char ch) {
        return next[ch - 'a'];
    }
    
    Trie* insert(int ch, Trie *t) {
        next[ch - 'a'] = t;
        return t;
    }
};

int getLength(Trie *root, string &word, int pos) {
    Trie *node = root;
    int len = 0;
    while(pos < word.length()) {
        if(node->contains(word[pos])) {
            node = node->contains(word[pos]);
        } else {
            ++len;
            node = node->insert(word[pos], new Trie);
        }
        ++pos;
    }
    return len;
}

int distinctSubstring(string &word) {
    Trie *root = new Trie;
    int answer = 0;
    for(int i = 0; i < word.length(); i++) {
        int len = getLength(root, word, i);
        answer += len;
    }
    return answer;
}
