#ifndef NETWORKINFRASTRUCTURE_H
#define NETWORKINFRASTRUCTURE_H

#include <string>
#include <vector>
#include <unordered_map>
#include "NetworkDevice.h"
#include "KNND.h"

class NetworkInfrastructure
{
private:
    std::string name;
    std::vector<NetworkDevice *> devices;

public:
    static int MAX_DEVICES;

    NetworkInfrastructure(const std::string &name);
    ~NetworkInfrastructure();

    void addDevice(NetworkDevice *device);
    void displayAllDevices() const;
    std::string predictDeviceType(NetworkDevice *unknownDevice, int k, const std::string &mode);
};

#endif
