class Solution {
public:
    bool static comp(pair<int,int> p1 , pair<int,int> p2) {
        if(p1.second == p2.second) return p1.first < p2.first;
        else return p1.second > p2.second;
    }
    
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
        unordered_map<string,int> pos, neg;
        for(int i = 0; i < positive_feedback.size(); i++){
            pos[positive_feedback[i]] = 3;
        }
        for(int i = 0; i < negative_feedback.size(); i++){
            neg[negative_feedback[i]] = -1;
        }
        
        vector<pair<int,int>> v;
        for(int i = 0; i < report.size(); i++) 
        {
            string s = report[i];
            string c = "";
            int points = 0;
            for(int i = 0; i < s.length(); i++) 
            {
                if(s[i] == ' ') {
                    if(pos.find(c) != pos.end()) points += 3;
                    else if(neg.find(c) != neg.end()) points -= 1;
                    c = "";
                }
                else if(i == s.length() - 1) {
                    c.push_back(s[i]);
                    if(pos.find(c) != pos.end()) 
                        points += 3;
                    else if(neg.find(c) != neg.end()) 
                        points -= 1;
                    
                    c = "";
                }
                else c.push_back(s[i]);
            }
            v.push_back({student_id[i], points});
        }
        
        sort(v.begin(), v.end(), comp);
    
        vector<int> ans;    
        for(int i = 0; i < k ; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
        
    }
};