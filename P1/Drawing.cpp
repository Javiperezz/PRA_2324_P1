#include "Drawing.h"
#include "Circle.h"
#include "Square.h"

Drawing::Drawing(){
	shapes = new ListLinked<Shape*>();
}

Drawing::~Drawing(){
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape){
	shapes->append(shape);
}

void Drawing::print_all(){
	std::cout << "Drawing contents: " << std::endl;
	for(int i=0; i<shapes->size(); i++){
		if(dynamic_cast<Square*>(shapes->get(i))){
			Square* s = dynamic_cast<Square*>((shapes->get(i)));                                        
			s->print();
			std::cout << std::endl;			
		}
		else if(dynamic_cast<Circle*>(shapes->get(i))){
			Circle* c = dynamic_cast<Circle*>((shapes->get(i)));
			c->print();
			std::cout << std::endl;
		}
		else if(dynamic_cast<Rectangle*>(shapes->get(i))){
			Rectangle* r = dynamic_cast<Rectangle*>((shapes->get(i)));                  
    			r->print();
			std::cout << std::endl;
		}
	}
}

double Drawing::get_area_all_circles(){
	double acu=0;
	for(int i=0; i<shapes->size(); i++){
		if(dynamic_cast<Circle*>(shapes->get(i))){
			Circle* c = dynamic_cast<Circle*>((shapes->get(i)));
			acu += c->area();
	
		}
	}
	return acu;
}

void Drawing::move_squares(double incX, double incY){
	for(int i=0; i<shapes->size(); i++){
		if(dynamic_cast<Square*>(shapes->get(i))){
			Square* s = dynamic_cast<Square*>((shapes->get(i)));
			s->translate(incX, incY);
		}
	}
}
