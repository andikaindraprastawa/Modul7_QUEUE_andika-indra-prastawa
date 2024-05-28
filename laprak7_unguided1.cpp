#include <iostream>
using namespace std;
class Node
{
public:
    string data;
    Node *next;
    Node(string data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class ListQueue2311102033
{
private:
    Node *front;
    Node *back;

public:
    ListQueue2311102033()
    {
        front = nullptr;
        back = nullptr;
    }
    bool Kosong2311102033()
    {
        return front == nullptr;
    }
    void enqueue(string data) 
    {
        Node *newNode = new Node(data);
        if (Kosong2311102033())
        {

            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }
    void dequeue()
    {
        if (Kosong2311102033())
        {
            cout << "Antrian Kosong" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            back = nullptr;
        }
        delete temp;
    }
    int countQueue()
    {
        int count = 0;
        Node *current = front;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    void clearQueue()
    {
        Node *current = front;
        while (current != nullptr)
        {
            
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        front = nullptr;
        back = nullptr;
    }
    void viewQueue()
    {
        cout << "Data Antrian:" << endl;
        Node *current = front;
        int i = 1;
        while (current != nullptr)
        {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
        }
    }
};

int main()
{
    ListQueue2311102033 queueList;

    // menambahkan data antrian
    queueList.enqueue("Andika");
    queueList.enqueue("Indra");
    queueList.enqueue("Prastawa");

    // lihat antrian
    queueList.viewQueue();
    cout << "Jumlah antrian = " << queueList.countQueue() << endl;

    // mengeluarkan data antrian
    queueList.dequeue();
    // melihat update antrian
    cout << "\nUpdate Antrian:" << endl;
    queueList.viewQueue();
    cout << "Jumlah antrian = " << queueList.countQueue() << endl;

    // hapus antrian
    queueList.clearQueue();

    // periksa jika antrian kosong
    if (queueList.Kosong2311102033())
    {
        cout << "\nAntrian Kosong" << endl;
        cout << "Jumlah antrian = " << queueList.countQueue() << endl;
    }
    return 0;
}

