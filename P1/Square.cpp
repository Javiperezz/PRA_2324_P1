#include "Square.h"

Square::Square(){
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1,1);
	vs[1] = Point2D(1,1);
	vs[2] = Point2D(1, -1);
	vs[3] = Point2D(-1, -1);
	
}


Square::Square(std::string color, Point2D* vertices){
	if(check(vertices)){
		set_color(color);
		vs = vertices;
	}else{
		throw std::invalid_argument("Provided vertices do not build a valid square!");
	}
		
}

bool Square::check(Point2D* vertices){
	return Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3]) && Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[3], vertices[0]) && Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[1], vertices[2]);
}

void Square::set_vertices(Point2D* vertices){	
	if(check(vertices)){
		for(int i=0; i < N_VERTICES; i++){
			vs[0] = vertices[0];
		}
	}else{
		throw std::invalid_argument("Provided vertices do not build a valid square!");
	}

}


std::ostream& operator<<(std::ostream &out, const Square &square){
	out << "[Square: color = " << square.get_color();
	for(int i = 0; i < square.N_VERTICES; i++)
		out << "; v" << i << " = " << square.vs[i];
	out << "]";

	return out;
}

double Square::area() const{
	return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Square::perimeter() const{
	return 2 * Point2D::distance(vs[0], vs[1]) + 2 * Point2D::distance(vs[1], vs[2]);
}

void Square::translate(double incX, double incY){	
	for(int i=0; i < N_VERTICES; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Square::print(){
	std::cout << *this;
}
