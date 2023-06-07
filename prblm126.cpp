#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> res;
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<string> cur_usage;
    queue<vector<string>> q;
    int lvl = 1;
    q.push({beginWord});
    st.erase(beginWord);
    while (!q.empty())
    {
        vector<string> temp = q.front();
        q.pop();
        if (temp.size() > lvl)
        {
            lvl++;
            for (auto it : cur_usage)
            {
                st.erase(it);
            }
        }

        string word = temp.back();
        if (word == endWord)
        {
            if (res.size() == 0)
            {
                res.push_back(temp);
            }
            else if (res[0].size() == temp.size())
            {
                res.push_back(temp);
            }
        }
        for (int i = 0; i < word.size(); i++)
        {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    temp.push_back(word);
                    q.push(temp);
                    cur_usage.push_back(word);
                    temp.pop_back();
                }
            }
            word[i] = org;
        }
    }

    return res;
}
// The above Solution is timelimit excceded

// The below one is accepted
class Solution
{
    vector<vector<string>> ans;
    unordered_map<string, int> m;
    string b;

private:
    void dfs(string &word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = m[word];
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (m.find(word) != m.end() && steps == m[word] + 1)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        b = beginWord;
        queue<string> q;
        int n = beginWord.size();
        q.push(beginWord);
        m[beginWord] = 1;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front();
            q.pop();
            int level = m[word];
            if (word == endWord)
                break;
            for (int i = 0; i < n; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        q.push(word);
                        m[word] = level + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        if (m.find(endWord) != m.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> res = findLadders("hit", "cog", wordList);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}