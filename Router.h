#ifndef ROUTER_H
#define ROUTER_H

#include "NetworkDevice.h"

class Router : public NetworkDevice
{
private:
    int routingTableSize;

public:
    Router();
    Router(const std::string &hostname, const std::string &ipAddress,
           const std::string &location, const std::string &vendor,
           const std::string &osVersion, int year,
           double powerConsumption, bool isCritical, int routingTableSize);
    Router(const Router &other);
    ~Router();

    int getRoutingTableSize() const;
    void setRoutingTableSize(int routingTableSize);
    void display() const override;
    std::string getDeviceType() const override { return "Router"; }
};

#endif
