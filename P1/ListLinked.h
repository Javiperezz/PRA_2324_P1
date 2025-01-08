#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

	private:
		Node<T>* first;
		int n;		

	public:
		ListLinked(): first{nullptr}, n{0}{}
		
		~ListLinked(){
			while(first != nullptr){
				Node<T>* aux= first->next;
				delete first;
				first = aux;
				n--;
			}
		}
		
		T operator[](int pos){
			return get(pos);
		}
		
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			out << "List => [";
			Node<T>*aux = list.first;
			int c=0;
			while(aux != nullptr && c < list.n){
				out << std::endl << "  " << aux->data;
				aux = aux->next;
				c++;
			}
			if(list.n != 0)
				out << std::endl;
			out << "]";
			return out;
		}

		void insert(int pos, T e){
			if(pos >= 0 && pos <= n){
				Node<T>* prev;
				Node<T>* newNode;
				if(pos == 0)
					first = new Node<T>(e, first);	
				
				prev = first; 
				if( pos != 0 ){
					int c=1;
					while(c < pos && prev != nullptr ){
						c++;
						prev = prev->next;
					}
					
							
					newNode = new Node<T>(e, prev->next);
				
					prev->next = newNode;
				}
				n++;

			}else
				throw std::out_of_range("Posición inválida!");
		}

		void append(T e){
			insert(size(), e);
		}
		
		void prepend(T e){//COMPROBAR
			insert(0, e);
		}

		T remove(int pos){
			if(pos >=0 && pos < size()){
				Node<T>* aux = first;
				if( pos != 0){
					Node<T>* prev = aux;
					int c=1;
					while(c < pos){
						c++;
						prev = prev->next;
					}
					aux = prev->next;
					prev->next = aux->next;					
				}else{
					first = aux->next;
				}
				n--;
				return aux->data;	
			}
			throw std::out_of_range("Posición inválida!");	
		}

		T get(int pos){
			if(pos >= 0 && pos < size()){
				int c = 0;
				Node<T>* node = first;
				T a;
				while( c <= pos ){
					c++;
					a = node->data;
					node = node->next;
				}
				return a;
			}
			throw std::out_of_range("Posición inválida!");
		}

		int search(T e){
			int p= 0;
			Node<T>* node=first;
			while(node->data != e && node->next != nullptr){
				p++;
				node = node->next;
			}
			if(node == first || (node->next == nullptr && node->data!=e)){
				p= -1;
			}
			return p;
		}

		bool empty(){
			return n == 0;
		}

		int size(){
			return n;
		}

};
