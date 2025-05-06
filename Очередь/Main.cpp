#include <iostream>

#include "Queue.h"

using namespace std;

int main()
{
    Queue queue;

    int value = 0;

    for (int i = 0; i < 5; ++i)
    {
        cout << "Add " << i + 1 << " element to the queue: ";
        cin >> value;

        queue.Enqueue(value);
    }
	unsigned int size = queue.GetSize();
	//cout << queue.Dequeue() << endl;

    

	queue.Clear();
	queue.Enqueue(100);
	queue.Enqueue(200);
	queue.Enqueue(300);

	size = queue.GetSize();

	for (unsigned int i = 0U; i < size; ++i)
	{
		cout << "Remove element from the query " << queue.Dequeue() << endl;
	}



    return 0;
}