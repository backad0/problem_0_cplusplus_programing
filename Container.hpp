#include <vector>
#include "Box.hpp"

using namespace std;

/*namespace containerNS {*/

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

        const vector<Box> &getBoxes() const;

        void setBoxes(const vector<Box> &boxes);

        int getLength() const;

        void setLength(int length);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        double getMaxWeight() const;

        void setMaxWeight(double maxWeight);

        Box getBox(int stand);

        Box &operator[](int stand);

        friend ostream &operator<<(ostream &os, Container &container);

        friend istream &operator>>(istream &in, Container &container);


    };

/*}*/

