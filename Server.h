#ifndef SERVER_H
#define SERVER_H

#include "NetworkDevice.h"

class Server : public NetworkDevice
{
private:
    int cpuCores;

public:
    Server();
    Server(const std::string &hostname, const std::string &ipAddress,
           const std::string &location, const std::string &vendor,
           const std::string &osVersion, int year,
           double powerConsumption, bool isCritical, int cpuCores);
    Server(const Server &other);
    ~Server();

    int getCpuCores() const;
    void setCpuCores(int cpuCores);
    void display() const override;
    std::string getDeviceType() const override { return "Server"; }
};

#endif
