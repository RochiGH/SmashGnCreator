#include <iostream>
#include <thread>
#include <random>
#include <algorithm>
#include <cmath>
#include <vector>

#include "../include/GnNode.h"

using namespace std;

vector<GnNode> gnPoints;
vector<GnNode> gnRtk; 

double agriBotSize = 20;
double tiltFactor = -150.0;
double startRowX = -700;
double rowsize = 100;

/**
 * GnNodeSmashRtkCreator
 * GnNodeSmashRtkCreator read the RTK log file and build up the input GnNode vectors 
 * that should be used to calculate the graph. Every RTK node is references to the 
 * start ROW and the end ROW poles , like L0,H0 Ln,Hn where L stands for Low and H for High
 * keeping the south,west priority.
 *
 * @param file path ???
 * @param file name ???
 */

void GnNodeSmashRtkCreator() {
    // TODO : read from a file and create the GnRtk vector.

#ifdef CASTELLANI
    Node L0 {10.57285563, 43.59387513};
    Node H0 {10.57254472, 43.59468386};
    Node L1 {10.57288571, 43.59388056};
    Node H1 {10.57254472, 43.59468386};
#endif
    GnNode L0 {100 , 0, RTK, CENTER, 0, "TEST"};
    gnRtk.push_back(L0);
    GnNode H0 {100 + tiltFactor, 200, RTK, CENTER, 0, "TEST"};
    gnRtk.push_back(H0);
    GnNode L1 {200, -100, RTK, CENTER, 1, "TEST"};
    gnRtk.push_back(L1);
    GnNode H1 {200 + tiltFactor, 300, RTK, CENTER, 1, "TEST"};
    gnRtk.push_back(H1);
    GnNode L2 {300, -200, RTK, CENTER, 2, "TEST"};
    gnRtk.push_back(L2);
    GnNode H2 {300 + tiltFactor, 300, RTK, CENTER, 2, "TEST"};
    gnRtk.push_back(H2);
    GnNode L3 {400, 0, RTK, CENTER, 3, "TEST"};
    gnRtk.push_back(L3);
    GnNode H3 {400 + tiltFactor, 500, RTK, CENTER, 3, "TEST"};
    gnRtk.push_back(H3);
    GnNode L4 {500, 0, RTK, CENTER, 4, "TEST"};
    gnRtk.push_back(L4);
    GnNode H4 {500 + tiltFactor, 500, RTK, CENTER, 4, "TEST"};
    gnRtk.push_back(H4);
    GnNode L5 {600, 0, RTK, CENTER, 5, "TEST"};
    gnRtk.push_back(L5);
    GnNode H5 {600 + tiltFactor, 300, RTK, CENTER, 5, "TEST"};
    gnRtk.push_back(H5);
    GnNode L6 {900, -400, RTK, CENTER, 6, "TEST"};
    gnRtk.push_back(L6);
    GnNode H6 {900 + tiltFactor, 200, RTK, CENTER, 6 ,"TEST"};
    gnRtk.push_back(H6);

    int row = 0;
    for (int i = 0; i < gnRtk.size() - 1; i+=2) {
        if(tiltFactor >= 0) {
            GnNodeSmashGnCreator(gnRtk[i], gnRtk[i+1], row, agriBotSize);
        } else {
            GnNodeSmashGnCreator(gnRtk[i+1], gnRtk[i], row, agriBotSize);
        }
        row++;
    }
}

/**
 * GnNodeSmashGnCreator
 * GnNodeSmashGnCreator read the RTK node , that is references to the 
 * start ROW and the end ROW poles , like L0,H0 Ln,Hn where L stands for Low and H for High
 * keeping the south,west priority and create the 4 gn nodes related to that ROW node.
 * 2 are start/end Row nodes placed on left or right and 2 are nodes for maneuvres.
 *
 * @param node1
 * @param node2
 * @param row
 * @param agriBotSize 
 */

void GnNodeSmashGnCreator(const GnNode& node1, const GnNode& node2, int row, int agriBotSize) {
    
    double n0x, n0y;
    double x1, x2, x3, x4;
    double y1, y2, y3, y4;

    double n3x, n3y;
    double x5, x6, x7, x8;
    double y5, y6, y7, y8;

    double m = ( node2.lat - node1.lat ) / ( node2.lon - node1.lon );
    double q = - m * node1.lon + node1.lat;

    n0x = node1.lon - agriBotSize;
    n0y = m * n0x + q;
    n3x = node2.lon + agriBotSize;
    n3y = m * n3x + q;

    if(node1.lon != node2.lon || node1.lat != node2.lat) {
        x1 = n0x + agriBotSize;
        y1 = - (1 / m) * ( x1 - n0x ) + n0y;
        x2 = n0x - agriBotSize;
        y2 = - (1 / m) * ( x2 - n0x ) + n0y;
        x3 = node1.lon + agriBotSize;
        y3 = - (1 / m) * ( x3 - node1.lon ) + node1.lat;
        x4 = node1.lon - agriBotSize;
        y4 = - (1 / m) * ( x4 - node1.lon ) + node1.lat;
        x5 = node2.lon - agriBotSize;
        y5 = - (1 / m) * ( x5 - node2.lon ) + node2.lat;
        x6 = node2.lon + agriBotSize;
        y6 = - (1 / m) * ( x6 - node2.lon ) + node2.lat;
        x7 = n3x + agriBotSize;
        y7 = - (1 / m) * ( x7 - n3x ) + n3y;
        x8 = n3x - agriBotSize;
        y8 = - (1 / m) * ( x8 - n3x ) + n3y;
    } 

    // TODO : missing parallel axes algorithm .
    GnNode LMR {x1, y1, 0 ,0, row, "LMR"};
    gnPoints.push_back(LMR);
    GnNode LML {x2, y2, 0 ,0, row, "LML"};
    gnPoints.push_back(LML);
    GnNode LR  {x3, y3, 0, 0, row, "LR"};
    gnPoints.push_back(LR);
    GnNode LL  {x4, y4, 0, 0, row, "LL"};
    gnPoints.push_back(LL);
    GnNode HL  {x5, y5, 0 ,0, row, "HL"};
    gnPoints.push_back(HL);
    GnNode HR  {x6, y6, 0 ,0, row, "HR"};
    gnPoints.push_back(HR);
    GnNode HMR {x7, y7, 0, 0, row, "HMR"};
    gnPoints.push_back(HMR);
    GnNode HML {x8, y8, 0, 0, row, "HML"};
    gnPoints.push_back(HML);

    return;
}