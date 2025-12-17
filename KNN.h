#ifndef KNN_H
#define KNN_H

#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

template <typename T>
class KNN
{
protected:
    int k;

public:
    KNN() : k(3) {}
    KNN(int k) : k(k) {}
    int getK() const { return k; }
    void setK(int k) { this->k = k; }
    virtual int similarityMeasure(T *a, T *b) = 0;

    vector<int> findNearestNeighbors(const vector<T *> &traindata, T *target)
    {
        vector<pair<int, int>> distances;
        for (size_t i = 0; i < traindata.size(); ++i)
        {
            int distance = similarityMeasure(traindata[i], target);
            distances.push_back(make_pair(distance, i));
        }
        sort(distances.begin(), distances.end());
        vector<int> neighbors;
        for (int i = 0; i < k && i < (int)distances.size(); ++i)
        {
            neighbors.push_back(distances[i].second);
        }
        return neighbors;
    }
};

#endif
