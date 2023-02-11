#include "Box.hpp"
#include <iostream>

using namespace std;

Box::Box() = default;

Box::Box(int length, int width, int height, int value, double weight) {
    Box::length = length;
    Box::width = width;
    Box::height = height;
    Box::value = value;
    Box::weight = weight;
}

int arrayValue(Box arr[], int size) {
    int sumValue = 0;
    for (int i = 0; i < size; i++) {
        sumValue += arr[i].value;
    }
    return sumValue;
}

bool ifFits(Box arr[], int size, int maxSumSize) {
    int currentSize;
    for (int i = 0; i < size; i++) {
        currentSize = arr[i].length + arr[i].width + arr[i].height;
        if (currentSize >= maxSumSize) return false;
        return true;
    }
}

double maxWeightsByCond(Box arr[], int size, int maxV) {
    double maxWeight = 0;
    int currentV;
    for (int i = 0; i < size; i++) {
        currentV = arr[i].length * arr[i].width * arr[i].height;
        if (currentV > maxV) {
            if (arr[i].weight > maxWeight) {
                maxWeight = arr[i].weight;
            }
        }
        return maxWeight;
    }
}

bool ifCanBeFolded(Box arr[], int size) {
    int count = 0;
    int countBig = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i != j) && (arr[i].length < arr[j].length) && (arr[i].width < arr[j].width) &&
                (arr[i].height < arr[j].height)) {
                count++;
            }
            if ((i != j) && (arr[i].length == arr[j].length) && (arr[i].width == arr[j].width) &&
                (arr[i].height == arr[j].height)) {
                return false;
            }
        }
        if (count == 0) countBig++;
        /*cout << "big:" << countBig << endl;*/
        if (countBig > 1) return false;
        count = 0;
    }
    return true;
}

bool equals(Box box1, Box box2) {
    if ((box1.length == box2.length) && (box1.width == box2.width) && (box1.height == box2.height) &&
        (box1.weight == box2.weight) && (box1.value == box2.value)) {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, Box &box) {
    return os << "length: " << box.length << " width: " << box.width << " height: " << box.height << " weight: "
              << box.weight
              << " value: " << box.value;
}

istream &operator>>(istream &in, Box &box) {
    return in >> box.length >> box.width >> box.height >> box.weight >> box.value;
}

int Box::getLength() const {
    return length;
}

int Box::getWidth() const {
    return width;
}

int Box::getHeight() const {
    return height;
}

int Box::getValue() const {
    return value;
}

double Box::getWeight() const {
    return weight;
}

void Box::setLength(int length) {
    Box::length = length;
}

void Box::setWidth(int width) {
    Box::width = width;
}

void Box::setHeight(int height) {
    Box::height = height;
}

void Box::setValue(int value) {
    Box::value = value;
}

void Box::setWeight(double weight) {
    Box::weight = weight;
}
