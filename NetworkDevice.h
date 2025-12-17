#ifndef NETWORKDEVICE_H
#define NETWORKDEVICE_H

#include <iostream>
#include <string>

class NetworkDevice
{
private:
    std::string hostname;
    std::string ipAddress;
    std::string location;
    std::string vendor;
    std::string osVersion;
    int year;
    double powerConsumption;
    bool isCritical;

public:
    NetworkDevice()
        : hostname(""), ipAddress(""), location(""), vendor(""),
          osVersion(""), year(0), powerConsumption(0), isCritical(false) {}

    NetworkDevice(const std::string &hostname, const std::string &ipAddress,
                  const std::string &location, const std::string &vendor,
                  const std::string &osVersion, int year,
                  double powerConsumption, bool isCritical)
        : hostname(hostname), ipAddress(ipAddress), location(location),
          vendor(vendor), osVersion(osVersion), year(year),
          powerConsumption(powerConsumption), isCritical(isCritical) {}

    NetworkDevice(const NetworkDevice &other)
        : hostname(other.hostname), ipAddress(other.ipAddress),
          location(other.location), vendor(other.vendor),
          osVersion(other.osVersion), year(other.year),
          powerConsumption(other.powerConsumption), isCritical(other.isCritical) {}

    virtual ~NetworkDevice() {}

    std::string getHostname() const { return hostname; }
    std::string getIpAddress() const { return ipAddress; }
    std::string getLocation() const { return location; }
    std::string getVendor() const { return vendor; }
    std::string getOsVersion() const { return osVersion; }
    int getYear() const { return year; }
    double getPowerConsumption() const { return powerConsumption; }
    bool getIsCritical() const { return isCritical; }

    void setHostname(const std::string &hostname) { this->hostname = hostname; }
    void setIpAddress(const std::string &ipAddress) { this->ipAddress = ipAddress; }
    void setLocation(const std::string &location) { this->location = location; }
    void setVendor(const std::string &vendor) { this->vendor = vendor; }
    void setOsVersion(const std::string &osVersion) { this->osVersion = osVersion; }
    void setYear(int year) { this->year = year; }
    void setPowerConsumption(double powerConsumption) { this->powerConsumption = powerConsumption; }
    void setIsCritical(bool isCritical) { this->isCritical = isCritical; }

    virtual void display() const
    {
        std::cout << "Network Device of unkown type:" << std::endl;
        std::cout << "Hostname: " << hostname << std::endl;
        std::cout << "IP: " << ipAddress << std::endl;
        std::cout << "Location: " << location << std::endl;
        std::cout << "Vendor: " << vendor << std::endl;
        std::cout << "OS: " << osVersion << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Power: " << powerConsumption << " W" << std::endl;
        std::cout << "Critical: " << (isCritical ? "Yes" : "No") << std::endl;
    }

    virtual std::string getDeviceType() const { return "NetworkDevice"; }
};

#endif
