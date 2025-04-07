#include <iostream>
#include <string> // Untuk tipe data string
using namespace std;

class Box
{
public:
    double length;
    void setWidth(double wid);
    double getWidth(void);
    void setMaterial(string mat); // Fungsi untuk mengatur material
    string getMaterial(void);     // Fungsi untuk mengambil material

private:
    double width;
    string material; // Atribut private untuk material
};

// Member functions definitions
double Box::getWidth(void)
{
    return width;
}

void Box::setWidth(double wid)
{
    width = wid;
}

void Box::setMaterial(string mat)
{
    material = mat;
}

string Box::getMaterial(void)
{
    return material;
}

// Main function for the program
int main()
{
    Box box;

    // set box length without member function
    box.length = 10.0; // OK: because length is public
    cout << "Length of box : " << box.length << endl;

    // set box width using member function
    box.setWidth(10.0); // Use member function to set it.
    cout << "Width of box : " << box.getWidth() << endl;

    // set and get box material
    box.setMaterial("Wood");
    cout << "Material of box : " << box.getMaterial() << endl;

    return 0;
}