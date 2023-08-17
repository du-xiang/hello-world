class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0, len = 0;
        int head_pos = 0, tail_pos = -1;
        string s_char;
        string::size_type idx;


        for (int i = 0; i < s.size(); i++)
        {
            s_char = s[i];
            idx = s.substr(head_pos, tail_pos-head_pos+1).find(s_char);

            if (idx == string::npos) 
            {
                tail_pos++, len++;
                if (len > max_length) 
                    max_length = len;
            }else {
                head_pos = head_pos+idx+1;
                tail_pos++;

                len = tail_pos - head_pos + 1;
            }
        }

        return max_length;
    }
};