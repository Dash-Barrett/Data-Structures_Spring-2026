#ifndef ROUTE_H
#define ROUTE_H
#include "AirportNode.hpp"


class Route { // The Edge, has weights distance and cost
public:
    AirportNode neighbor; // Refers to the Destination Airport
    int distance; // weight 1
    int cost; // weight 2

    Route(AirportNode n, int d, int c);
};

#endif