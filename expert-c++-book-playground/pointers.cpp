#include <iostream>

using namespace std;

struct Point
{
    float x;
    float y;
};

int main()
{
    int ivar = 26;
    char *p = (char *)&ivar;
    // *(p - 1) = 33;

    cout << *p << endl;

    short *sh = (short *)&ivar;
    // print the value in the first two bytes of ivar
    std::cout << *sh << endl;
    // print the value in the last two bytes of ivar
    std::cout << *(sh + 1) << endl;

    cout << sizeof(int) << endl;

    Point *pp = static_cast<Point *>(std::malloc(sizeof(Point)));
    pp->x = 234;
    pp->y = 23;

    cout << pp->x << ", " << pp->y << endl;

    // incorect
    delete pp;
    pp = nullptr;

    // correct
    free(pp);
    return 0;
}