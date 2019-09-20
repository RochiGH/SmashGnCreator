#include <iostream>

using namespace std;

// TODO : delete 

void printOnConsole(const char * outputMessage);

template <typename C> class String {
    public:
        String();
        explicit String(const C*);
        String(const String&);
        String operator=(const String&);
        // ...
    private:
        static const int shot_max = 15;
        int sz;
        C* ptr;
};

template <typename Coord> 
class NodeT {

private:
    Coord lon, lat;
    int type;
    int side;
    Coord* ptr;

public:
    NodeT();
    NodeT(const Coord* latIN, const Coord* lonIN, int typeIN, int sideIN);
    explicit NodeT(const Coord* latIN, const Coord* lotIN);
    NodeT(const NodeT&);
    Coord& operator +=(Coord latIN);
    void coordUpdate(Coord lon, Coord lat);
    void typeUpdate(int newType);
    void sideUpdate(int side);
    void nodeGenerateGraphReferences(vector<NodeT<double>>& GraphReferences);

};