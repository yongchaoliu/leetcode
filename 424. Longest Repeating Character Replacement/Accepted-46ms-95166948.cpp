// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/
// 

class Solution {
public:
	int characterReplacement(const string& s, int k) {
		int res = 0;
		for (char cur = 'A'; cur <= 'Z'; ++cur)
		{
			int l = 0, r = 0, cnt = k;
			while (r < s.size() )
			{
				if (s[r] == cur)
				{
					r++;
				}
				else
				{
					if (cnt)
					{
						cnt--;
						r++;
					}
					else
					{
						if(s[l] != cur)
							cnt++;
						l++;
					}
				}
				res = max(res, r - l);
			}
		}
		return res;
	}
};


/*
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations. Note: Both the string's length and k will not exceed 104. Example 1: 
Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
 Example 2: 
Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
 Subscribe to see which companies asked this question. Show Similar Problems (H) Longest Substring with At Most K Distinct Characters
*/
