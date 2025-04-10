#include <iostream>
#include <iomanip> // Untuk manipulasi output
using namespace std;

class Shape
{
public:
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

protected:
    int width, height;
};

class PaintCost
{
public:
    // Metode untuk menghitung biaya pengecatan berdasarkan jumlah warna
    int getCost(int area, int numColors) { return area * 70 * numColors; }
};

class Rectangle : public Shape, public PaintCost
{
public:
    int getArea() { return width * height; }
};

int main()
{
    Rectangle rect;
    rect.setWidth(5);
    rect.setHeight(7);
    int area = rect.getArea();
    int numColors = 3; // Jumlah warna yang digunakan

    cout << "Total area: " << area << " m2" << endl;
    cout << "Total biaya pengecatan untuk " << numColors << " warna: Rp."
         << fixed << setprecision(0) << rect.getCost(area, numColors) << endl;

    return 0;
}