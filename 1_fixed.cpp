#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <random>
using namespace std;
float Xi,Yi,random_Xi, random_Yi, con;
int Cpoint, point, result, b;
float random(float min, float max)
{
    return (float)(rand())/RAND_MAX*(max - min) + min;
}
int main()
{
    point = 0;

    for (int i = 0; i < 5; i++)
    {
        Cpoint = 0;
        Xi= 0;
        Yi= 0;
        cout<<"Введите значение X (по стандарту рекомендуется 0)"<<endl;
        cin>> Xi;
        cout<<"Введите значение Y (по стандарту рекомендуется 0)"<< endl;
        cin>> Yi;
        random_Xi = random (-5.0,5.0);
        random_Yi = random (-5.0,5.0);
        cout<<Xi<<" "<<Yi<<endl;
        Xi = Xi + random_Xi;
        Yi = Yi + random_Yi;
        con = sqrt(Xi*Xi+Yi*Yi);
        cout<<Xi<<" "<<Yi<<endl;
        cout<<"con: "<<con<<endl;
        if (con < 1.0)
        {
            
            Cpoint= Cpoint|5;
        } 
        else if ((1.0 <= con) and (con < 2.0))
        {
            
            Cpoint= Cpoint|4;
        } 
        else if ((2.0 <= con) and (con < 3.0))
        {
            Cpoint= Cpoint|3;
        }
        else if ((3.0 <= con) and (con < 4.0))
        {
            Cpoint= Cpoint|2;  
        } 
        else if ((4.0 <= con) and (con < 5.0))
        {
            Cpoint = Cpoint|1;
        }
        else if (con <= 5.00)
        {
            Cpoint= Cpoint&0;
        }
        cout<<"Cpoint: "<<Cpoint<<endl;
    result = result+Cpoint;
    }
        cout << "Ваш счет: "<< result <<endl;
        if (result < 10)
            cout << "Лузер" << endl;
        else
            cout << "Харош" <<endl;
    return 0;
}
