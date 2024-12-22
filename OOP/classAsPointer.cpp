#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int hight;

public:
    Rectangle()
    {
        length = 0;
        hight = 0;
    }

    Rectangle(int l, int h)
    {
        length = l;
        hight = h;
    }

    Rectangle(Rectangle &rect)
    {
        length = rect.length;
        hight = rect.hight;
    }

    int getLength()
    {
        return length;
    }

    int getHight()
    {
        return length;
    }

    void setLength(int l)
    {
        if (l < 0)
            throw logic_error("Length can't be negative");

        length = l;
    }

    void setHight(int h)
    {
        hight = h;
    }
};

int main()
{
    Rectangle r(123, 234);
    Rectangle *p = new Rectangle(120, 23);
    Rectangle copy_rect = Rectangle(r);

    try
    {
        r.setLength(12);
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
        exit(0);
    }

    // p->setLength(120);

    cout << r.getLength() << endl;
    cout << p->getLength() << endl;
    cout << copy_rect.getLength() << endl;

    return 0;
}