#include <functional>
#include <iostream>


using namespace std;

// Y-combinator compatible factorial
int fact(function<int(int)> f, int v)
{
    return v == 0 ? 1 : v * f(v - 1);
}

// Y-combinator for the int type
/* TODO: Make it template */
function<int(int)> y(function<int(function<int(int)>, int)> f)
{
    return bind(f, bind(&y, f), placeholders::_1);
}


int main()
{
    function<int(int) > factorial = y(fact);

    cout << factorial(5) << endl;

    return 0;
}
