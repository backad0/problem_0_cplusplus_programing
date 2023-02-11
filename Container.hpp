#include <vector>
#include "Box.hpp"

using namespace std;

class Container {
private:
    vector<Box> boxes;
    int length, width, height;
    double maxWeight;
public:
    Container(int length, int width, int height, double maxWeight);
};

