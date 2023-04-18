#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
/*
    sort(strs) => O(n*nlogn)
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (!strs.size()) return vector<vector<string>>();
        vector<vector<string>> groups;
        unordered_map<string, vector<string>> map;

        for (string s : strs) {
            string sorted = lowerSort(s);
            map[sorted].push_back(s);
        }

        for (pair<string, vector<string>> p : map) {
            groups.push_back(p.second);
        }

        return groups;
    }
    string lowerSort(string s) {
        vector<int> count(26);
        string ret = "";
        for (char c : s) {
            count[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                ret += i + 'a';
                count[i]--;
            }
        }

        return ret;
    }
};