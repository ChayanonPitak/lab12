#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double data[], int dataAmount, double result[])
{
    double sum = 0;
    for (int i = 0 ; i < dataAmount ; i++) sum += data[i];
    result[0] = sum/dataAmount;
    sum = 0;
    for (int i = 0 ; i < dataAmount ; i++) sum += pow(data[i]-result[0] ,2);
    result[1] = sqrt(sum/(dataAmount));
    sum = 1;
    for (int i = 0 ; i < dataAmount ; i++) sum *= data[i];
    result[2] = pow(sum, 1.0f/dataAmount);
    sum = 0;
    for (int i = 0 ; i < dataAmount ; i++) sum += 1/data[i];
    result[3] = dataAmount/sum;
    sum = data[0];
    for (int i = 1 ; i < dataAmount ; i++) sum = max(sum, data[i]);
    result[4] = sum;
    sum = data[0];
    for (int i = 1 ; i < dataAmount ; i++) sum = min(sum, data[i]);
    result[5] = sum;
}