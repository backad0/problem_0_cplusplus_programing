#include <iostream>
#include "Container.hpp"

using namespace std;

int main() {
    Container container(1,1,1,10.0);
    container.addBox(Box(1,1,1,1,1));
    container.addBox(Box(2,2,2,2,1));

    return 0;
}
