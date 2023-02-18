#include <iostream>
#include "Container.hpp"
/*#include "Box.hpp"*/


using namespace std;
/*using namespace containerNS;*/

int main() {
    Container container(1,1,1,10.0);
    container.addBox(Box(1,1,1,1,1));
    container.addBox(Box(2,2,2,2,1));
    Box Box(3,3,3,1,1);
    container[0] = Box;
    cout << container[0];


    return 0;
}
