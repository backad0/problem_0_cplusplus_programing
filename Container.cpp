#include "Container.hpp"
#include "WeightException.hpp"
#include <exception>

using namespace std;
using namespace containerNS;

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
    return os << "Main characteristics: length: " << container.length << ", width: " <<
    container.width << ", height: " << container.height << ", maxWeight: " << container.maxWeight << ".";
}

istream &operator>>(istream &in, Container &container) {
    return in >> container.length >> container.width >> container.height >> container.maxWeight;
}
