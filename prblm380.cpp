#include <bits/stdc++.h>
using namespace std;
class RandomizedSet
{
private:
    std::unordered_map<int, int> mp;
    std::vector<int> nums;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.count(val) == 0)
        {
            mp[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (mp.count(val) != 0)
        {
            int i = mp[val];
            int lastValue = nums.back();
            nums[i] = lastValue;
            nums.pop_back();
            mp[lastValue] = i;
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int randomIndex = std::rand() % nums.size();
        return nums[randomIndex];
    }
};
