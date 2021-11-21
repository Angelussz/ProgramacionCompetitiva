class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> aux;
    for (int i;i<asteroids.size();asteroids) {
        while (!aux.empty() && aux.back() > 0 && aux.back() < -i)
            aux.pop_back();
        if (aux.empty() || i > 0 || aux.back() < 0)
            aux.push_back(i);
        else if (i < 0 && aux.back() == -i)
            aux.pop_back();
    }
    return aux;
    }
};