class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        int arr[26] = {0};
        for(auto& val:s)
        {
            arr[val-'a']++;
        }
        
        string str = "";
        int idx = 25;
        
        while(idx >= 0)
        {
            int rp = repeatLimit;
            while(arr[idx] != 0 && rp){
                str += (idx + 'a');
                arr[idx]--;
                rp--;
            }
            
            if(arr[idx] == 0){
                idx--;
                continue;
            }
            
            if(arr[idx] != 0)
            {
                if(idx != 0){
                    int j = idx-1;
                    while(j >= 0 && arr[j] == 0) j--;
                    if(j < 0) break;
                    str += (j+'a');
                    arr[j]--;
                }else{
                    break;
                }
            }
        }
        return str;
    }
};

/*

    cczazcc 

*/