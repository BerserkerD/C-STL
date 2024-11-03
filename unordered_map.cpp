#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
struct VectorHash{
    size_t operator()(const vector<T>& vec) const {
        size_t hash = 0;
        for(const auto& elem : vec) {
            hash ^= std::hash<T>()(elem) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

template <typename T>
struct VectorEqual{
    bool operator()(const vector<T> &a, const vector<T> &b) const {
        return a == b;
    }
};

int main() {

    unordered_map<vector<int>, int, VectorHash<int>, VectorEqual<int>> map1;
    map1[{1, 2, 3}] = 10;

    unordered_map<vector<string>, int, VectorHash<string>, VectorEqual<string>> map2;
    map2[{"1", "2", "3"}] = 20;

    cout << map1[{1, 2, 3}] << endl; // 输出 10
    cout << map2[{"1", "2", "3"}] << endl; // 输出 20

    return 0;
}