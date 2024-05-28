#include <iostream>
using namespace std;

class Node {
public:
    string name;
    string nim;
    Node *next;
    Node(string name, string nim) {
        this->name = name;
        this->nim = nim;
        this->next = nullptr;
    }
};

class QueueList {
private:
    Node *front;
    Node *back;

public:
    QueueList() {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string name, string nim) {
        Node* newNode = new Node(name, nim);
        if (isEmpty()) {
            front = newNode;
            back = newNode; 
        } else {
            back->next = newNode;
            back = newNode; 
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian Kosong" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
    }

    int countQueue() {
        int count = 0;
        Node *current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clearQueue() {
        Node *current = front;
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        front = nullptr;
        back = nullptr;
    }

    void viewQueue() {
        cout << "Data Antrian:" << endl;
        Node *current = front;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". Name: " << current->name << ", NIM: " << current->nim << endl;
            current = current->next;
            i++;
        }
    }
};

int main() {
    QueueList queueList;

    // Tambahkan data antrian
    queueList.enqueue("Andika", "2311102033");
    queueList.enqueue("Indra", "2311102033");
    queueList.enqueue("Prastawa", "2311102033");

    // Tampilkan data antrian
    queueList.viewQueue();
    // menghitung jumlah antrian
    cout << "Jumlah antrian = " << queueList.countQueue() << endl;
    // hapus data antrian
    queueList.dequeue();

    // tampilkan data yang sudah di update
    cout << "\nUpdated Queue:" << endl;
    queueList.viewQueue();
    cout << "Jumlah antrian = " << queueList.countQueue() << endl;
    // hapus semua antrian
    queueList.clearQueue();

    // periksa antrian jika kosong
    if (queueList.isEmpty()) {
        cout << "\nAntrian Kosong" << endl;
        cout << "Jumlah antrian = " << queueList.countQueue() << endl;
    }
    return 0;
}
