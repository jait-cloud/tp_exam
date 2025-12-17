#include "Server.h"
#include <cstdio>

Server::Server() : NetworkDevice(), cpuCores(0) {}

Server::Server(const std::string &hostname, const std::string &ipAddress,
               const std::string &location, const std::string &vendor,
               const std::string &osVersion, int year,
               double powerConsumption, bool isCritical, int cpuCores)
    : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical),
      cpuCores(cpuCores) {}

Server::Server(const Server &other) : NetworkDevice(other), cpuCores(other.cpuCores) {}

Server::~Server() {}

int Server::getCpuCores() const { return cpuCores; }
void Server::setCpuCores(int cpuCores) { this->cpuCores = cpuCores; }

void Server::display() const
{
  printf("Hostname: %s\n", getHostname().c_str());
  printf("IP: %s\n", getIpAddress().c_str());
  printf("Year: %d\n", getYear());
  printf("Power: %.2f W\n", getPowerConsumption());
  printf("CPU Cores: %d\n", cpuCores);
}
