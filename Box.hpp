#include <iostream>

using namespace std;

class Box {
private:
    int length, width, height, value;
    double weight;
public:
    Box();
    Box(int length, int width, int height, int value, double weight);

    friend int arrayValue(Box arr[], int size);
    friend bool ifFits(Box arr[], int size, int maxSumSize);
    friend double maxWeightsByCond(Box arr[], int size, int maxV);
    friend bool ifCanBeFolded(Box arr[], int size);
    friend bool equals(Box box1, Box box2);

    [[nodiscard]] int getLength() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getValue() const;
    [[nodiscard]] double getWeight() const;

    void setLength(int length);
    void setWidth(int width);
    void setHeight(int height);
    void setValue(int value);
    void setWeight(double weight);

    friend ostream& operator << (ostream &os, Box &box);
    friend istream& operator >> (istream &in, Box &box);
};
