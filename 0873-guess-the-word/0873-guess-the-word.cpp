/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int commonCharacters(const string& s1, const string& s2) 
    {
        int matches = 0;
        for (int index = 0; index < s1.length(); index++) 
        {
            if (s1[index] == s2[index]) {
                matches++;
            }
        }
        return matches;
    }

    void findSecretWord(vector<string>& words, Master& master) 
    {
        unordered_set<string> hash(words.begin(), words.end());
        while (!hash.empty()) {
            string frontWord = *hash.begin();
            int numMatchesSecret = master.guess(frontWord);

            for (auto it = hash.begin(); it != hash.end();) {
                if (commonCharacters(*it, frontWord) != numMatchesSecret) 
                {
                    it = hash.erase(it);
                } else it++;
            }

            hash.erase(frontWord);
        }
    }
};