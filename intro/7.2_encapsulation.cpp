/*  
 *  x7.2_encapsulation.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Mon 07 Aug 2017 00:32:09 IST
 *  ver    : 
 *   
 */


#include <iostream>


class Rectangle
{
	public:
		double GetWidth() { return _width; }
		double GetHeight() { return _height; }
		double GetArea() const { return this->_width * this->_height; }

		//declaration of a member function
		//definition is outside class def
		void PrintInfo();

		void AnotherPrintInfo() const
		{
			//this is a const qualified version of PrintInfo() to work with
			//const objects. It this makes a promise to the
			//compiler that it won't try to change the const object
			//GetArea() must also be const qualified
			std::cout << "Area: wxh = " << _width << "x" << _height << " :: ";
			std::cout << GetArea() << std::endl;

			//but we can try to break that promise hehehe...
			//_width = 10;

		}

		//Constructors are member functions
		Rectangle() {}

		//overloading - default value initilization
		//Rectangle(): _width{}, _height{} {}
		Rectangle(int): _width{}, _height{} {}

		Rectangle(double init_width): _width(init_width), _height(init_width)
	{
		std::cout << "A square is being created... " << std::endl;
	}

		Rectangle(double init_width, double init_height ); //definition will be outside class def

	private:
		double _width;
		double _height;

};

Rectangle::Rectangle( double init_width, double init_height)
	: _width{init_width}, _height{init_height}
{}

void Rectangle::PrintInfo()
{
	std::cout << "Area: wxh = " << _width << "x" << _height << " :: ";
	std::cout << GetArea() << std::endl;
}



int main()
{

	Rectangle a;
	a.PrintInfo();

	Rectangle b{0};
	b.PrintInfo();

	Rectangle c{10.0};
	c.PrintInfo();

	Rectangle d{12.1, 13.5};
	d.PrintInfo();

	const Rectangle e{20.0};
	e.AnotherPrintInfo(); 
	//this won't work unless a const qualifier is added to the
	//member funcion as well
	//Now, what if a non-const object try to access const member function?
	
	Rectangle f;
	f.AnotherPrintInfo();
	
	return 0;
}
