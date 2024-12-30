class Solution {
    public long dividePlayers(int[] skill) 
    {
        int s = 0, n = skill.length;
        for(int e: skill) {
            s += e;
        }    

        if(s % (n/2) != 0) return -1;
        Arrays.sort(skill);

        int i = 0, j = n-1;
        long score = -1, ans = 0;
        while(i <= j)
        {
            long team = (long)(skill[i] + skill[j]);
            if(score != -1 && team != score) {
                return -1;
            }
            score = team;
            ans += ((long)skill[i] * (long)skill[j]);

            i++; j--;
        }

        return ans;
    }
}

/*

[3,2,5,1,3,4]
1,2,3,3,4,5

*/