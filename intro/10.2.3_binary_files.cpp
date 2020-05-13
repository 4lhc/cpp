/*
 *  10.2.3_binary_files.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Thu 24 Aug 2017 22:57:37 IST
 *  ver    :
 *
 */


#include <iostream>
#include <fstream>

class Point3D
{

    public:
        Point3D();
        Point3D(double input_x, double input_y);
        Point3D(double input_x, double input_y, double input_z);
        ~Point3D(){};

        void Write(std::ofstream &ofs);
        void Read(std::ifstream &ifs);
        void Print();

    private:
        double x{}, y{}, z{};

};

Point3D::Point3D()
    : x{0}, y{0}, z{0}
{}

Point3D::Point3D(double input_x, double input_y)
    : x{input_x}, y{input_y}, z{0}
{}


Point3D::Point3D(double input_x, double input_y, double input_z)
    : x{input_x}, y{input_y}, z{input_z}
{}

void Point3D::Write(std::ofstream &ofs)
{
    ofs.write(reinterpret_cast<const char*>(&x), sizeof(x));
    ofs.write(reinterpret_cast<const char*>(&y), sizeof(y));
    ofs.write(reinterpret_cast<const char*>(&z), sizeof(z));
}

void Point3D::Read(std::ifstream &ifs)
{
    ifs.read(reinterpret_cast<char*>(&x), sizeof(x));
    ifs.read(reinterpret_cast<char*>(&y), sizeof(y));
    ifs.read(reinterpret_cast<char*>(&z), sizeof(z));
}

void OutputToFile(std::string &filename)
{


    int num_of_points{20};
    std::ofstream ofs(filename, std::ios::binary);

    while (num_of_points-- > 0)
    {
        Point3D(2.1*num_of_points, 4.3*num_of_points, 5.12*num_of_points).Write(ofs);
    }
}

void ReadFromFile(std::string &filename)
{

    int num_of_points{20};
    std::ifstream ifs(filename, std::ios::binary);
    Point3D p;
    while (num_of_points-- > 0)
    {
        p.Read(ifs);
        p.Print();
    }
}

void Point3D::Print()
{
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
int main()
{
    //std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    //std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
    //std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
    //std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
    //std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;
    //std::cout << "sizeof(char) = " << sizeof(char) << std::endl;



    std::string filename{"point_data.bin"};
    //OutputToFile(filename);
    ReadFromFile(filename);
    return 0;
}
