#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

	private:
		// miembros privados
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;

	public:
		// miembros públicos, incluidos los heredados de List<T>
		void insert(int pos, T e){  
			if(pos >= 0 && pos < max){
				for(int i=max; i>=pos; i--){
					arr[i] = arr[i-1];
				}
				arr[pos] = e;
				n++;
			}else
				throw std::out_of_range("Posicion no valida");
		}

		void append(T e){
			insert(n, e);
		}

		void prepend(T e){
			insert(0, e);
		}
		
		T remove(int pos){
			if(pos >= 0 && pos < n){
				T aux=arr[pos];
				for(int i=pos; i<max; i++){
					arr[i] = arr[i+1];
				}
				n--;
				return aux;
			}			
			throw std::out_of_range("Posicion no valida");
		}

		T get(int pos){
			if(pos >= 0 && pos < n)
				return arr[pos];
			throw std::out_of_range("Posicion no valida");
		}
		
		int search(T e){
			for(int i=0; i<n; i++){
				if(arr[i]== e)
					return i;
			}
			return -1;
		}
		
		bool empty(){ 
			return n==0; 
		}
		
		int size(){
			return n;
		}
		


		
		ListArray(){
			arr = new T[MINSIZE];
			max = 4;
			n = 0;
		}

		~ListArray(){
			delete[] arr;
		}


		T operator[](int pos){
			return get(pos);
		}
		
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			out << "List => [";
			for(int i=0; i<list.n; i++){
				out << std::endl << "  " << list.arr[i];			
			}
			if(list.n != 0)
				out << std::endl;
			out << "]";
			return out;
		}

		void resize(int new_size){
			T* new_arr = new T[new_size];
			for(int i=0; i<n; i++){
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;
		}
};
