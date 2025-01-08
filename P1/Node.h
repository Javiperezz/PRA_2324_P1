#include <ostream>

template <typename T> 
class Node {
	public:
		// miembros públicos
		T data;
		Node<T>* next;
		
		Node(T data, Node<T>* next=nullptr): data{data}, next{next} {}


		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << "Data --> " << node.data << std::endl;
			return out;	
		}

};
