class Trie {
   public:
    vector<int> chr;
    vector<Trie*> next;
    vector<int> complete;
    Trie() : chr(26, 0), next(26, 0), complete(26, 0) {
    }
};

void insert(Trie &t, string &str, int pos = 0) {
    if(pos == str.length()) {
        return;
    }
    int n = str[pos]-'a';
    if(t.chr[n] == 1) {
        insert(*(t.next[n]), str, pos+1);
        if(pos+1 == str.length()) t.complete[n] = 1;
        return;
    }
    t.chr[n] = 1;
    t.next[n] = new Trie;
    insert(*(t.next[n]), str, pos+1);
    if(pos+1 == str.length()) t.complete[n] = 1;
    return;
}

int search(Trie &t, string &str, int pos = 0) {
    if(str.length() == pos) return 0;
    int n = str[pos]-'a';
    if(t.chr[n] == 1 && t.complete[n] == 1) {
        int x = search(*(t.next[n]), str, pos+1); 
        return x == -1 ? -1 : 1;
    }
    return -1;
}

string completeString(int n, vector<string> &a){
    string answer;
    Trie trie;
    for(auto &x : a) {
        insert(trie, x);
    }
    for(auto &x : a) {
        int n = search(trie, x);
        //cout << answer << " | " << x << " | " << n << endl;
        if(n == -1)
            continue;
        else if(x.length() > answer.length())
            answer = x;
        else if(x.length() == answer.length() && answer.compare(x) > 1)
            answer = x;
    }
    if(answer.length() == 0) {
        answer = "None";
    }
    return answer;
}