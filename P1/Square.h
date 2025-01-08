#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle{
	private:
		static bool check(Point2D* vetices);
	
	public:
		//CONSTRUCTORES Y DESTRUCORES
		Square();
		Square(std::string color, Point2D* vertices);

		//FUNCIONES
		void set_vertices(Point2D* vertices);
		friend std::ostream& operator<<(std::ostream &out, const Square &square);

		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print() override;


};
#endif
