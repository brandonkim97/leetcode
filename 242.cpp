#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> count(26);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0 ; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};