#include <iostream>
#include <thread>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

#include "../libgraph/include/Node.h"

using namespace std;

enum side {CENTER, LEFT, RIGHT};
enum type {RTK, ROW, ROWMAN, HOME};

void GnNodeSmashRtkCreator();

class GnNode : public Node { 
public:
    int type,side, row;
    const char *UID;
    GnNode(double lonIN, double latIN, int typeIN, int sideIN, int rowIN, const char *UIDIN):Node(lonIN, latIN) {
        type = typeIN;
        side = sideIN;
        row = rowIN;
        UID = UIDIN;
    };  
};

void GnNodeSmashGnCreator(const GnNode& node1, const GnNode& node2, int row, int agriBotSize);




