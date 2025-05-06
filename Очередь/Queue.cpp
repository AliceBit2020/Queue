#include "Queue.h"

Queue::Queue() : m_capacity(10), m_queue(new int[10]),   m_size(0U)
{
}

Queue::Queue(const Queue& queue) : m_capacity(queue.m_capacity),  m_queue(new int[queue.m_capacity]), m_size(queue.m_size)
{
    for (unsigned int i = 0U; i < queue.m_size; ++i)
    {
        m_queue[i] = queue.m_queue[i];
    }
}

Queue::~Queue()
{
    delete [] m_queue;
}

Queue& Queue::operator=(const Queue& right)
{
    if (this != &right)
    {
        // Очистка очередь.
        delete [] m_queue;

        m_capacity = right.m_capacity;
        m_size = right.m_size;
        m_queue = new int[right.m_capacity];

        for (unsigned int i = 0U; i < right.m_size; ++i)
        {
            m_queue[i] = right.m_queue[i];
        }
    }

    return *this;
}

void Queue::Clear()
{
    // Эффективная "очистка" очереди (данные в массиве все еще существуют, но методы класса, ориентированные на работу 
    // с концом очереди, будут их игнорировать).
    m_size = 0U;
}

int Queue::Dequeue()////черга не дозволяє вилучити будь-який елемент, тому що доступ до першого
{
    int result = 0;

    // Возврат первого элемента, сдвиг остальных и уменьшение размера, если в очереди есть элементы.
    if (!IsEmpty())
    {
        result = m_queue[0];

        for (unsigned int i = 0; i < m_size - 1; ++i)
        {
            m_queue[i] = m_queue[i + 1];//////  m_queue[0]=m_queue[1]     m_queue[1]=m_queue[2] 
        }
        //
        --m_size;
    }
	
    return result;
}

void Queue::Enqueue(const int value)///////додає новий елемент до черги
{

    //////Збільшити розмір черги

    if (m_capacity == m_size)////переповнення черги  m_sizе - реальний розмір черги дорівнює мах розміру m_capacity
    {
        m_capacity *= 2U;/////збільшимо вмістимість черги в 2 рази  

        int* copy = new int[m_capacity];////створюємо динам масив більшого розміру

        for (unsigned int i = 0U; i < m_size; ++i)
        {
            copy[i] = m_queue[i];
        }

        delete[] m_queue;

        m_queue = copy;
    }

    ////записуємо новий єлемент черги
    m_queue[m_size] = value;

    ++m_size;////коли додаємо новий єлемент кількість елементів реальна ++
}

unsigned int Queue::GetSize()
{
    return m_size;
}

bool Queue::IsEmpty()
{
    return m_size == 0U;
}