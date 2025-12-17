#include "Router.h"
#include <cstdio>

Router::Router() : NetworkDevice(), routingTableSize(0) {}

Router::Router(const std::string &hostname, const std::string &ipAddress,
               const std::string &location, const std::string &vendor,
               const std::string &osVersion, int year,
               double powerConsumption, bool isCritical, int routingTableSize)
    : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical),
      routingTableSize(routingTableSize) {}

Router::Router(const Router &other) : NetworkDevice(other), routingTableSize(other.routingTableSize) {}

Router::~Router() {}

int Router::getRoutingTableSize() const { return routingTableSize; }
void Router::setRoutingTableSize(int routingTableSize) { this->routingTableSize = routingTableSize; }

void Router::display() const
{
  printf("Hostname: %s\n", getHostname().c_str());
  printf("IP: %s\n", getIpAddress().c_str());
  printf("Year: %d\n", getYear());
  printf("Power: %.2f W\n", getPowerConsumption());
  printf("Routing Table Size: %d\n", routingTableSize);
}
