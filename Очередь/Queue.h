#pragma once

class Queue
{
private:

    // Количество элементов, под которое в очереди выделена память.
    unsigned int m_capacity;

    // Массив для хранения данных.
   int* m_queue;

    // Количество элементов в очереди.
    unsigned int m_size;

public:

    Queue();
    Queue(const Queue& queue);

    ~Queue();

    Queue& operator=(const Queue& right);

    // Очистка очереди.
    void Clear();

    // Удаление элемента.
    int Dequeue();

    // Добавление элемента.
    void Enqueue(const int value);

    // Проверка существования элементов в очереди.
    bool IsEmpty();

    // Получение количества элементов в очереди.
    unsigned int GetSize();
};