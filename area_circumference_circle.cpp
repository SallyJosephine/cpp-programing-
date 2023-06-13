#include<iostream>
using namespace std;
class Circle{
    public:
    int radius;
    int diameter;
    Circle()
    {
        radius=7;
        diameter=radius+radius;
    }
double areaCircle(){
    return radius*radius*3.142;
}
double circumfCircle(){
return 3.142*diameter;
}
};
int main(){

Circle A;
double areaCircle;
double circumfCircle;
areaCircle= A.areaCircle();
cout<<"The area of circle A=" <<areaCircle << endl;
cout<<"The circumf.. of a circle A id : "<<circumfCircle<<endl;
return 0;
}
