#include <iostream>
#include "Box.hpp"

using namespace std;

int main() {
    Box arr[4] = {Box(1, 1, 1, 1, 1.0),
                  Box(2, 2, 2, 1, 1.0),
                  Box(4, 3, 4, 1, 1.0),
                  Box(4, 4, 3, 1, 1.0)

    };
    cout << ifCanBeFolded(arr, size(arr))
         << endl << equals(arr[0], arr[1]);
    /*cin >> arr[1];
    cout << arr[1];*/
    return 0;
}
