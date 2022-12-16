#include <iostream>
using namespace std;

template <typename T>

/*
* Queue Class
*/

class Queue<T> {
	public:
		Queue (int size) { 
					iMax_size = size;
					data = new T[iMax_size];
					First_Index = -1;
					Next_Index = 0;
					this->size = 0;
					}
		void Push (T element);
		T Pop ();
		int Count();
		int Size();
	
	private:
		T* data;
		int size;
		int iMax_size;
		T element;
};

/*
* Description: Push function of element
* Input: Element
* Output: None
*/
void Queue::Push (T element)
{
	if (
	if (size == iMax_size)
	{
		cout << "Not possible to Write! Full space" << endl;
		return;
	}
	else {
		if (First_Index == -1) {
			First_Index == 0;
		}
		data[Next_Index] = element;
		Next_Index++;
		size++;
	}
}

/*
* Description: Pop function of element
* Input: None
* Output: Element
*/
T Queue::Pop()
{
	if (First_Index == -1){
		cout << "Not possible to read value from the Queue" << endl;
		return 0;
	}
	
	T temp_data = data[First_Index];
	for (int internal_Index = 0; internal_Index < size; internal_Index++) {
		data[internal_Index] = data[internal_Index + 1];
	}
	Next_Index--;
	size--;
	
	if (size == 0) {
		First_Index = -1;
		Next_Index = 0;
	}
	return temp_data;
}

/*
* Description: Maximum Size of elements
* Input: None
* Output: Maximum Size - Integer
*/
int Queue::Size()
{
	return iMax_size;
}

/*
* Description: Current size of the queue
* Input: None
* Output: Size - Integer
*/
int Queue::Count()
{
	return size;
}

main()
{
	int queue_size;
	int imenu_choose;
	int value_push;
	
	cout << "Insert the size of Queue:";
	cin >> queue_size;
	
	Queue<int> queue_task(queue_size);
	
	while(1){
		cout << " Choose the value:"<<endl;
		cout << " 1 - Pop value:" << endl << " 2 - Push Value:" << endl << " 3 - Queue Size" << endl << " 4 - How many elements" << " 5 - Exit" endl;
		cin >> imenu_choose;
		switch(imenu_choose){
			case 1:
				cout << "Next value of the queue: " << queue_task.Pop() << endl;
				break;	
			case 2:
				cout << "Insert the value:";
				cin >> value_push;
				queue_task.Push(value_push);
				break;
			case 3:
				cout << "Queue Size: " << queue_task.Size();
				break;
			case 4:
				cout << "The queue has: " << queue_task.Count() << " Elements" << endl;
				break;
			case 5:
				return 0;
		}
	}
	
	return 0;	
	
}
