#include "Switch.h"
#include <cstdio>

Switch::Switch() : NetworkDevice(), portCount(0) {}

Switch::Switch(const std::string &hostname, const std::string &ipAddress,
               const std::string &location, const std::string &vendor,
               const std::string &osVersion, int year,
               double powerConsumption, bool isCritical, int portCount)
    : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical),
      portCount(portCount) {}

Switch::Switch(const Switch &other) : NetworkDevice(other), portCount(other.portCount) {}

Switch::~Switch() {}

int Switch::getPortCount() const { return portCount; }
void Switch::setPortCount(int portCount) { this->portCount = portCount; }

void Switch::display() const
{
  printf("Hostname: %s\n", getHostname().c_str());
  printf("IP: %s\n", getIpAddress().c_str());
  printf("Year: %d\n", getYear());
  printf("Power: %.2f W\n", getPowerConsumption());
  printf("Port Count: %d\n", portCount);
}
