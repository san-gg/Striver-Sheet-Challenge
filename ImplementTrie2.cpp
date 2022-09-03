class Node {
    vector<Node*> arr;
    int countChar;
    int countWord;
public:
    Node() : arr(26, 0), countChar(0), countWord(0) { }
    void increaseChar() { countChar++; }
    void increaseWord() { countWord++; }
    void addChar(int n, Node *node) { arr[n] = node; }
    Node* getChar(int n) { return arr[n]; }
    Node* containsChar(int n) { return arr[n]; }
    int getCountChar() { return countChar; }
    int getCountWord() { return countWord; }
    void decreaseChar() { --countChar; }
    void decreaseWord() { --countWord; }
};

class Trie{
    Node *root;
public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *tmp = root;
        for(char c : word) {
            int x = c - 'a';
            if(tmp->containsChar(x) == 0) tmp->addChar(x, new Node);
            tmp = tmp->getChar(x);
            tmp->increaseChar();
        }
        tmp->increaseWord();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *tmp = root;
        for(char c : word) {
            int x = c - 'a';
            tmp = tmp->getChar(x);
            if(tmp == 0) return 0;
        }
        return tmp->getCountWord();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *tmp = root;
        int count = INT_MAX;
        for(char c : word) {
            int x = c - 'a';
            tmp = tmp->getChar(x);
            if(tmp == 0) return 0;
            count = min(count, tmp->getCountChar());
            if(count == 0) return 0;
        }
        return count;
    }

    void erase(string &word) {
        // Write your code here.
        Node *tmp = root;
        if(countWordsEqualTo(word) == 0) return;
        for(char c : word) {
            int x = c - 'a';
            tmp = tmp->getChar(x);
            if(tmp == 0) return;
            tmp->decreaseChar();
        }
        tmp->decreaseWord();
    }
};
