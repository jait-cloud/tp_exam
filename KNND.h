#ifndef KNND_H
#define KNND_H

#include "KNN.h"
#include "NetworkDevice.h"
#include <cmath>

class KNND : public KNN<NetworkDevice>
{
public:
    KNND() : KNN() {}
    KNND(int k) : KNN(k) {}

    int similarityMeasure(NetworkDevice *a, NetworkDevice *b) override
    {
        double diffPower = a->getPowerConsumption() - b->getPowerConsumption();
        double diffYear = a->getYear() - b->getYear();
        return (int)((diffPower * diffPower) + (diffYear * diffYear));
    }
};

#endif
