// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// 1. The town judge trusts nobody.
// 2. Everybody (except for the town judge) trusts the town judge.
// 3. There is exactly one person that satisfies properties 1 and 2.

// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. 

// If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

// Example 1:

// Input: n = 2, trust = [[1,2]]
// Output: 2

// Example 2:

// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3

// Example 3:

// Input: n = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1


class Solution {
public:
    int findJudge(int n, vector<vector<int>> trust) {
        if (trust.size() == 0 && n == 1) 
            return 1;
        vector<int> count(n + 1);
        for (auto i : trust) {
            count[i[0]]--;
            count[i[1]]++;
        }

        for (int i = 0; i < count.size(); i++) {
            if (count[i] == n - 1) return i;
        }
        return -1;
    }
};
