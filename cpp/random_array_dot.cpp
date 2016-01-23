
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

typedef Matrix<double,10000,1> ArrayRandy;

int main()
{

    auto x = ArrayRandy::Random();
    auto y = ArrayRandy::Random();

    cout << "===============\n" << x.dot(y)  << endl;
    
    return 0;
}

