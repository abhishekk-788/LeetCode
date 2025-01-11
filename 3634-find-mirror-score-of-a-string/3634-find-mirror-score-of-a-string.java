class Solution {
    public long calculateScore(String s) 
    {
        Map<Integer, Stack<Integer>> hash = new HashMap<>();
        long ans = 0;

        for(int i = 0; i < s.length(); i++)
        {
            int ascii = (int)s.charAt(i);
            int mirrorAscii = (122 - (ascii - 97));

            Stack<Integer> stack1 = hash.getOrDefault(mirrorAscii, new Stack<>());
            Stack<Integer> stack2 = hash.getOrDefault(ascii, new Stack<>());
            if(!stack1.isEmpty()) {
                int top = (int) stack1.pop();
                ans = ans + (long)(i - top);

                hash.put(mirrorAscii, stack1);
            }
            else {
                stack2.push(i);
                hash.put(ascii, stack2);
            }

            System.out.println(ascii + " " + mirrorAscii + " " + ans);
        }
        
        return ans;  
    }
}

/*

 b = 98 - 97 = 1
 122 - 1 = y;

*/