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
    int addBox(Box box);
    void delBox(int stand);
    int getSize();
    double getSumOfWeights();
    int getSumOfValues();
    Box getBox(int stand);
};

