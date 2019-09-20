#include <vector>
#include <sstream>
#include <iostream>

#include "../include/fltkLibrary.h"
 
using namespace std;

void printOnConsole(const char * outputMessage) {
    cout << outputMessage;
}

template <typename C> 
String<C>::String() : sz(0) {}

String<char> ch;

struct Tracer {
    string mess;
    Tracer(const char *s) : mess {s} { cout <<  "messaggio" ; };
};

void createMessage(const vector<int>& v)
{
    Tracer tr{ "int f()\n"};
}

class Vector {
public:
    Vector(int i);
};


template <typename Coord> 
NodeT<Coord>::NodeT() {
    lon = 0;
    lat = 0;
    
}

template <typename Coord> 
NodeT<Coord>::NodeT(const Coord* latIN, const Coord* lonIN, int typeIN, int sideIN) : 
    lat{latIN}, lon{lonIN}, type{typeIN}, side{sideIN} {}

template<>
NodeT<double>::NodeT(const double* latIN, const double* lonIN, int typeIN, int sideIN) : 
    lat{*latIN}, lon{*lonIN}, type{typeIN}, side{sideIN} {}

template <typename Coord> 
void NodeT<Coord>::coordUpdate(Coord lonIN, Coord latIN) { 
    
    lon = lonIN;
    lat = latIN;
    return;

}
template <typename Coord>
void NodeT<Coord>::typeUpdate(int newTypeIN) {

    type = newTypeIN;      
    return;

}

template <typename Coord> 
void NodeT<Coord>::sideUpdate(int sideIN){

    side = sideIN;      
    return;

}

template <typename Coord> 
void NodeT<Coord>::nodeGenerateGraphReferences(vector<NodeT<double>>& GraphReferences) {

    for(int i = 0; i <= GraphReferences.max_size(); i++) {

        GraphReferences[i].coordUpdate(this->lat + i, this->lon + i);

    }
    return;

} 

template<typename Coord> 
class gnNodeEx {
    vector<NodeT<Coord>>* gnNode; 
public:
    gnNodeEx() : gnNode{new vector<NodeT<Coord>>(4) } { }
    void print_all() const;
};
// error: pointer initialized with int // error: undefined identifier o
