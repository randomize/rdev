
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_map>

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Eigen>

using namespace std;
using namespace Eigen;

int main(int argc, char* argv[]) {
    
    cout << "Hello World" << endl;

    typedef Matrix<double,10000,1> ArrayRandy;
    ArrayRandy x;
    ArrayRandy y;

    x = ArrayRandy::Random();
    y = ArrayRandy::Random();

    cout << x.dot(y)  << endl;

    

    return 0;
}

