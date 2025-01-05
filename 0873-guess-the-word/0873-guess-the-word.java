/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    public int commonCharacters(String s1, String s2) 
    {
        int matches = 0;
        for (int index = 0; index < s1.length(); index++) 
        {
            if (s1.charAt(index) == s2.charAt(index)) {
                matches++;
            }
        }
        return matches;
    }

    public void findSecretWord(String[] words, Master master) {
        Set<String> hash = new HashSet<>(Arrays.asList(words));
        while (!hash.isEmpty()) 
        {
            String frontWord = hash.iterator().next();
            int numMatchesSecret = master.guess(frontWord);

            Iterator<String> it = hash.iterator();
            while (it.hasNext()) {
                String word = it.next();
                if (commonCharacters(word, frontWord) != numMatchesSecret) {
                    it.remove();
                }
            }

            hash.remove(frontWord);
        }
    }
}