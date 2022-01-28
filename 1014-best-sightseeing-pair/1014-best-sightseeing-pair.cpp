class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxScore = 0;
        int max_AiPlusi = A[0] + 0;
        for(int j = 1; j < A.size(); j++)
        {
            maxScore = max(maxScore, max_AiPlusi + A[j] - j);
            max_AiPlusi = max(max_AiPlusi, A[j] + j);
        }
        return maxScore;
    }
};