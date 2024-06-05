/*here you have to find the minimum numbers of count like sabka hash milakr jo last me
end me sabse minimum hoga uss particular character ke liye tab ham uska count store kar lenge
aur phir usko hamne har ek count string me push kiya*/

class Solution
{
public:
    void func(string &m, int hash[26])
    {
        for (auto i : m)
        {
            hash[i - 'a']++;
        }
    }
    vector<string> commonChars(vector<string> &words)
    {
        int n = words.size();
        int count[26] = {0};
        func(words[0], count);

        for (int i = 1; i < n; i++)
        {
            int temp[26] = {0};
            func(words[i], temp);
            for (int j = 0; j < 26; j++)
            {
                count[j] = min(count[j], temp[j]);
            }
        }
        vector<string> s2;

        for (int i = 0; i < 26; i++)
        {
            int l = count[i];
            for (int j = 0; j < l; j++)
            {
                s2.push_back(string(1, i + 'a'));
            }
        }
        return s2;
    }
};