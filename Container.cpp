#include "Container.hpp"
#include "WeightException.hpp"
#include <exception>

using namespace std;
/*using namespace containerNS;*/

Container::Container(int length, int width, int height, double maxWeight) {
    Container::length = length;
    Container::width = width;
    Container::height = height;
    Container::maxWeight = maxWeight;
}

int Container::addBox(Box box) {
    double cWeight = this->getSumOfWeights();
    if ((cWeight + box.getWeight()) <= Container::maxWeight) {
        /*Box arr[Container::getSize()+1];
        for (int i = 0; i<Container::getSize(); i++){
            arr[i] = Container::boxes[i];
        }
        arr[Container::getSize()] = box;
        if (ifCanBeFolded)*/
        Container::boxes.push_back(box);
        return this->getSize() - 1;
    } else {
        throw WeightException();
    }

}

void Container::delBox(int stand) {
    Container::boxes.erase(Container::boxes.begin()+stand);
}

int Container::getSize() {
    return Container::boxes.size();
}

double Container::getSumOfWeights() {
    double sum = 0;
    for (int i = 0; i < this->getSize(); i++) {
        sum += Container::boxes.at(i).getWeight();
    }
    return sum;
}

int Container::getSumOfValues() {
    int sum = 0;
    for (auto i = Container::boxes.begin(); i != Container::boxes.end(); i++) {
        sum += i->getValue();
    }
    return sum;
}

Box Container::getBox(int stand) {
    return Container::boxes.at(stand);
}

Box& Container::operator[](int stand) {
    return this->boxes.at(stand);
}

ostream &operator<<(ostream &os, Container &container) {
    return os << "Main characteristics: length: " << container.getLength() << ", width: " <<
    container.getWidth() << ", height: " << container.getHeight() << ", maxWeight: " << container.getMaxWeight() << ".";
}

istream &operator>>(istream &in, Container &container) {
    int l, w, h; double mW;
    return in >> l >> w >> h >> mW;
    container.setLength(l);
    container.setWidth(w);
    container.setHeight(h);
    container.setMaxWeight(mW);
}

const vector<Box> &Container::getBoxes() const {
    return boxes;
}

void Container::setBoxes(const vector<Box> &boxes) {
    Container::boxes = boxes;
}

int Container::getLength() const {
    return length;
}

void Container::setLength(int length) {
    Container::length = length;
}

int Container::getWidth() const {
    return width;
}

void Container::setWidth(int width) {
    Container::width = width;
}

int Container::getHeight() const {
    return height;
}

void Container::setHeight(int height) {
    Container::height = height;
}

double Container::getMaxWeight() const {
    return maxWeight;
}

void Container::setMaxWeight(double maxWeight) {
    Container::maxWeight = maxWeight;
}
