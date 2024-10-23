class Solution {
public:
    unordered_map<string,int> mp1;
    unordered_map<int,string> mp2;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int t=rand();
        while(mp2.find(t)!=mp2.end()) {
            t=rand();
        }
        mp1[longUrl]=t;
        mp2[t]=longUrl;
        return to_string(t);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int t=stoi(shortUrl);
        return mp2[t];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));