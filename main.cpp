#include <iostream>
#include "NetworkInfrastructure.h"
#include "Server.h"
#include "Switch.h"
#include "Router.h"

int main()
{
    NetworkInfrastructure infra("Corporate Network");

    Server *srv1 = new Server("srv1", "192.168.1.1", "Paris", "Dell", "Ubuntu", 2022, 500, true, 16);
    Server *srv2 = new Server("srv2", "192.168.1.2", "Paris", "HP", "Windows", 2021, 450, true, 8);
    Switch *sw1 = new Switch("sw1", "192.168.1.10", "Paris", "Cisco", "IOS", 2020, 100, false, 24);
    Switch *sw2 = new Switch("sw2", "192.168.1.11", "Lyon", "Cisco", "IOS", 2019, 120, false, 48);
    Router *rt1 = new Router("rt1", "192.168.1.100", "Paris", "Juniper", "JunOS", 2021, 200, true, 1000);
    Router *rt2 = new Router("rt2", "192.168.1.101", "Lyon", "Cisco", "IOS", 2020, 180, true, 500);

    infra.addDevice(srv1);
    infra.addDevice(srv2);
    infra.addDevice(sw1);
    infra.addDevice(sw2);
    infra.addDevice(rt1);
    infra.addDevice(rt2);

    infra.displayAllDevices();

    Server unknownDevice("unknown", "192.168.1.50", "Paris", "Dell", "Linux", 2022, 480, true, 12);
    std::string predictedType = infra.predictDeviceType(&unknownDevice, 3, "numerical");
    std::cout << "Predicted Device Type: " << predictedType << std::endl;

    return 0;
}
