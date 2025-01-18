class Trie {
public:
    Trie* child[26];
    bool wordEnd;
    
    Trie()
    {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
class Solution {
public:
    unordered_map<string, set<string>> hash;
    void insertWord(Trie *root, string word)
    {
        int n = word.length();
        Trie *curr = root;
        string prefix = "";
        
        for(int i = 0; i < n; i++)
        {
            if(curr->child[word[i]-'a'] == NULL) {
                Trie* rootNode = new Trie();
                curr->child[word[i]-'a'] = rootNode;
            }
            curr = curr->child[word[i]-'a'];
            prefix += word[i];

            hash[prefix].insert(word);
        }
        curr->wordEnd = true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        Trie *root = new Trie();
        for(auto &p: products) {
            insertWord(root, p);
        }
        vector<vector<string>> res;
        int l = searchWord.length();

        string prefix = "";
        for(int i = 0; i < l; i++)
        {
            prefix += searchWord[i];
            vector<string> vec;
            int k = 0;

            for (const string& s : hash[prefix]) 
            {
                if (k < 3) {
                    vec.push_back(s);
                } else {
                    break;
                }
                k++;
            }
            res.push_back(vec);
        }

        return res;
    }
};