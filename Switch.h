#ifndef SWITCH_H
#define SWITCH_H

#include "NetworkDevice.h"

class Switch : public NetworkDevice
{
private:
    int portCount;

public:
    Switch();
    Switch(const std::string &hostname, const std::string &ipAddress,
           const std::string &location, const std::string &vendor,
           const std::string &osVersion, int year,
           double powerConsumption, bool isCritical, int portCount);
    Switch(const Switch &other);
    ~Switch();

    int getPortCount() const;
    void setPortCount(int portCount);
    void display() const override;
    std::string getDeviceType() const override { return "Switch"; }
};

#endif
