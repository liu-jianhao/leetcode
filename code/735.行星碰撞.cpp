/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(int i = 0; i < asteroids.size(); ++i)
        {
            const int size = asteroids[i];
            if(size > 0)
            {
                s.push_back(size);
            }
            else
            {
                if(s.empty() || s.back() < 0)
                {
                    s.push_back(size);
                }
                else if (abs(s.back()) <= abs(size))
                {
                    if(abs(s.back()) < abs(size))
                        --i;

                    s.pop_back();
                }
                
            }
        }

        return s;
    }
};

