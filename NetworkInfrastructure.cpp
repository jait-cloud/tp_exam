#include "NetworkInfrastructure.h"
#include <iostream>

int NetworkInfrastructure::MAX_DEVICES = 100;

NetworkInfrastructure::NetworkInfrastructure(const std::string &name) : name(name) {}

NetworkInfrastructure::~NetworkInfrastructure()
{
    for (auto device : devices)
        delete device;
}

void NetworkInfrastructure::addDevice(NetworkDevice *device)
{
    if ((int)devices.size() < MAX_DEVICES)
        devices.push_back(device);
}

void NetworkInfrastructure::displayAllDevices() const
{
    std::cout << "=== Infrastructure: " << name << " ===" << std::endl;
    for (auto device : devices)
    {
        device->display();
        std::cout << std::endl;
    }
}

std::string NetworkInfrastructure::predictDeviceType(NetworkDevice *unknownDevice, int k, const std::string &mode)
{
    std::vector<int> neighborIndices;

    if (mode == "numerical")
    {
        KNND knnd(k);
        neighborIndices = knnd.findNearestNeighbors(devices, unknownDevice);
    }

    std::unordered_map<std::string, int> typeCount;
    for (int index : neighborIndices)
    {
        std::string deviceType = devices[index]->getDeviceType();
        typeCount[deviceType]++;
    }

    std::string predictedType;
    int maxCount = 0;
    for (const auto &pair : typeCount)
    {
        if (pair.second > maxCount)
        {
            maxCount = pair.second;
            predictedType = pair.first;
        }
    }

    return predictedType;
}