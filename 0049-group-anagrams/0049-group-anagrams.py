class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_dict={}
        for string in strs:
            key=''.join(sorted(string))
            if key in anagram_dict:
                anagram_dict[key].append(string)
            else:
                anagram_dict[key]=[string]
        return list(anagram_dict.values())