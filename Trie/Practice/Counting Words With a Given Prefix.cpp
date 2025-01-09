class Trie {
public:
    
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
        int count;
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        newNode->count=0;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }
    
    /** Initialize your data structure here. */
    trieNode* root;
    
    Trie() {
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                crawler->children[index] = getNode();
            
            crawler = crawler->children[index];
            crawler->count++; 
        }
        
        crawler->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return false; 
            crawler = crawler->children[index]; 
        }
        return (crawler != NULL && crawler->isEndOfWord); 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trieNode *crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            
            if (!crawler->children[index]) 
                return false; 
            
            crawler = crawler->children[index]; 
        }
        if(i==prefix.length())
            return true;
        return false;
    }
    int countPrefix(string prefix) {
        trieNode *crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            
            if (!crawler->children[index]) 
                return 0; 
            
            crawler = crawler->children[index]; 
        }
        return crawler->count;
    }
};


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie* node=new Trie();
        int n=words.size();
        for(int i=0;i<n;i++) {
            node->insert(words[i]);
        }
        return node->countPrefix(pref);
    }
};