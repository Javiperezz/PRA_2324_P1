#include "Rectangle.h"

Rectangle::Rectangle(){
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1,0.5);
	vs[1] = Point2D(1,0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
	
}


Rectangle::Rectangle(std::string color, Point2D* vertices){
	if(check(vertices)){
		set_color(color);
		vs = vertices;
	}else{
		throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
	}
		
}

Rectangle::Rectangle(const Rectangle &r): vs{new Point2D[4]}{
	for(int i=0; i< N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
	set_color(r.color);
}

Rectangle::~Rectangle(){
	delete[] vs;
}

bool Rectangle::check(Point2D* vertices){

	return Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3]) && Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[3], vertices[0]);
}

Point2D Rectangle::get_vertex(int ind) const{
	if(ind >= 0 && ind < N_VERTICES){
		return vs[ind];
	}
	throw std::out_of_range("ERROR: Fuera de rango [0, N_VERTICES-1]");
}

Point2D Rectangle::operator[](int ind) const{
	if(ind < 0 || ind >= N_VERTICES)
		throw std::out_of_range("ERROR: Fuera de rango [0, N_VERTICES-1]");
	return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices){	
	if(check(vertices)){
		for(int i=0; i < N_VERTICES; i++){
			vs[0] = vertices[0];
		}
	}else{
		throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
	}

}

Rectangle& Rectangle::operator=(const Rectangle &r){
	for(int i=0; i< N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
	set_color(r.color);
	return *this;  

}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "[Rectangle: color = " << r.get_color();
	for(int i = 0; i < r.N_VERTICES; i++)
		out << "; v" << i << " = " << r.vs[i];
	out << "]";

	return out;
}

double Rectangle::area() const{
	return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() const{
	return 2 * Point2D::distance(vs[0], vs[1]) + 2 * Point2D::distance(vs[1], vs[2]);
}

void Rectangle::translate(double incX, double incY){	
	for(int i=0; i < N_VERTICES; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Rectangle::print(){
	std::cout << *this;
}
