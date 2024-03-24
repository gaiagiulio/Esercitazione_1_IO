#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double map(double x)
{
    return 3*x/4-7/4;
}

int main()
{
    ifstream data("data.csv");
    if (data.fail())
    {
        cerr << "Error while opening 'data.csv'" << endl;
        return 1;
    };

    ofstream res("result.csv");

    double y;
    double mean = 0.0;
    unsigned int counter= 1;
    res << "# N Mean" << scientific << setprecision(16) << endl;
    while (data >> y)
    {
        double z= map(y);
        mean = (mean*counter + z)/(counter+1);
        res << mean << endl;
        counter++;
    };

    data.close();
    res.close();

    return 0;
}
