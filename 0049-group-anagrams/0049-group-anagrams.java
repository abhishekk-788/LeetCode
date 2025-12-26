class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> list = new ArrayList<>();

        Map<String, List<String>> hash = new HashMap<>();
        for(String str: strs) 
        {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);

            String sortedStr = new String(chars);
            List<String> group = hash.getOrDefault(sortedStr, new ArrayList<>());
            group.add(str);

            hash.put(sortedStr, group);
        }
        hash.forEach((K, V) -> {
            List<String> anagram = new ArrayList<>();
            anagram.addAll(V);
            
            list.add(anagram);
        });

        return list;
    }
}