#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct Point{
    int x,y;
};
class CONRAN {
public:
    struct Point A[100];
    int DoDai;

    CONRAN() {
        init();
    }

    void init() {
        DoDai = 3;
        A[0] = {10, 10};
        A[1] = {11, 10};
        A[2] = {12, 10};
    }
};
