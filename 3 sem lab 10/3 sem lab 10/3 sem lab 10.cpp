// 3 sem lab 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"  
#include "fstream"
#include "string.h"
#include <stdlib.h> 
#include <cassert>
    //сортировка по выбору пользователя
    //вывод одиночного  элемента по номеру
    //вывод в диапозоне 
using namespace std;

template <typename T>

class NodeList
{
public:
    T item;
    NodeList<T>* next;
};

template <typename T>

class List
{
private:
    NodeList<T>* HEAD;

public:
    List() { HEAD = nullptr; }
    List(const List& SL)
    {
        NodeList<T>* p;
        NodeList<T>* p2;
        NodeList<T>* p3;

        HEAD = nullptr;
        p3 = nullptr;

        p = SL.HEAD;

        while (p != nullptr)
        {
            try {
                p2 = new NodeList<T>;
            }
            catch (bad_alloc e)
            {
                cout << e.what() << endl;
                return;
            }
            p2->item = p->item;
            p2->next = nullptr;
            if (HEAD == nullptr)
            {
                HEAD = p2;
                p3 = p2;
            }
            else
            {
                p3->next = p2;
                p3 = p3->next;
            }
            p = p->next;
        }
    }
    void Push(T item)
    {
        NodeList<T>* p;
        NodeList<T>* s = HEAD;
        while (s)
        {
            if (s->item == item)
            {
                cout << "\n\nThis element in the list!!!\n\n";
                return;
            }
            s = s->next;
        }
        try {
            p = new NodeList<T>;
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            return;
        }
        p->item = item;
        p->next = HEAD;
        HEAD = p;
    }
    void Empty()
    {
        NodeList<T>* p;
        NodeList<T>* p2;

        p = HEAD;

        while (p != nullptr)
        {
            p2 = p;
            p = p->next;
            delete p2;
        }
        HEAD = nullptr;
    }
    void Print(const char* objName)
    {
        cout << "Object: " << objName << endl;
        if (HEAD == nullptr)
            cout << "List is empty." << endl;
        else
        {
            NodeList<T>* p;
            p = HEAD;
            while (p != nullptr)
            {
                cout << p->item << "\t";
                p = p->next;
            }
            cout << endl;
        }
    }

    void search(T x)
    {
        NodeList<T>* s;
        s = HEAD;
        int flag = 0;
        if (HEAD == nullptr)
            cout << "List is empty." << endl;

        while (s)
        {
            if (s->item == x)
            {
                cout << "\n\n This element is found(serching)\n\n";
                flag = 1;
            }
            s = s->next;
        }
        if (flag == 0) cout << "\nNOT FOUND!!!";

    }

    void del(T x)
    {
        NodeList<T>* q = HEAD;
        NodeList<T>** s = &HEAD;
        NodeList<T>* s1 = nullptr;

        int flag = 0;
        if (HEAD == nullptr)
            cout << "List is empty." << endl;
        while ((*s))
        {

            if ((*s)->item == x)
            {
                if ((*s) != q && (*s)->next != nullptr)
                {
                    (s1)->next = (*s)->next;
                    flag = 1;
                    HEAD = q;
                    break;
                }
                else if ((*s)->next == nullptr)
                {
                    flag = 1;
                    s1->next = nullptr;
                    HEAD = q;
                    break;
                }
                else
                {
                    flag = 1;
                    HEAD = q->next;
                    break;
                }
            }
            s1 = *s;
            (*s) = (*s)->next;
        }
        if (flag == 0) cout << "\nNOT FOUND!!!";
    }

    void Print_element(const char* objName, int number)
    {
        int i = 0;
        int flag = 0;
        cout << "Object: " << objName << ":  ";
        if (HEAD == nullptr)
            cout << "List is empty." << endl;
        else
        {
            NodeList<T>* p;
            p = HEAD;
            while (p != nullptr)
            {
                if (number == i)
                {
                    cout << p->item << "\t";
                    flag = 1;
                    break;
                }
                p = p->next;
                i++;
            }
            if (flag == 0)
                cout << "\nThe number is not correct!!!";
            cout << endl;
        }
    }
    void Print_range(const char* objName, T x, T y)
    {
        int flag = 0;
        cout << "Object(range): " << objName << ":  ";
        if (HEAD == nullptr)
            cout << "List is empty." << endl;
        else
        {
            NodeList<T>* p;
            p = HEAD;
            cout << endl;
            while (p != nullptr)
            {
                if (x <= p->item && p->item <= y)
                {
                    cout << p->item << "\t";
                    flag = 1;
                }
                p = p->next;
            }
            if (flag == 0)
                cout << "\nNOT FOUND ELEMENTS IN THIS RANGE!!!";
            cout << endl;
        }
    }
    void sort()
    {
        NodeList<T>* s = HEAD;
        NodeList<T>* p = HEAD;
        T x;
        int j;
        if (HEAD == nullptr)
            cout << "List is empty." << endl;
        cout << "\n\nHOW DO YOU LIKE SORT?\n1--ASCENDING(+)\n2--DESCENDING\nCHOSE(1/2): ";
        for (int i = 0; i < 1; i++)
        {
            try
            {
                cin >> j;
                if (!(j > 0 && j < 3)) throw 1;
            }
            catch (const exception& ex)
            {
                cout << "ERROR:Uncorrect enter!" << endl;
                cout << ex.what() << endl;
                cin.clear();
                cin.ignore(10, '\n');
                i--;
            }
            catch (int)
            {
                cout << "ERROR:Uncorrect enter,enter 1 or 2!" << endl;
                cin.clear();
                cin.ignore(10, '\n');
                i--;
            }
        }
        switch (j)
        {
        case 1:
            while (p)
            {
                while (s)
                {
                    if (p->item > s->item)
                    {
                        x = p->item;
                        p->item = s->item;
                        s->item = x;
                    }
                    s = s->next;
                }
                p = p->next;
                s = p;
            }
            break;
        case 2:
            while (p)
            {
                while (s)
                {
                    if (p->item < s->item)
                    {
                        x = p->item;
                        p->item = s->item;
                        s->item = x;
                    }
                    s = s->next;
                }
                p = p->next;
                s = p;
            }
            break;
        }

    }
    ~List()
    {
        Empty();
    }
};

void main()
{
    List<int> SL;
    SL.Push(8);
    SL.Push(5);
    SL.Push(5);
    SL.Push(10);
    SL.Push(7);
    SL.Push(1);
    SL.Push(9);
    SL.Push(-1);
    SL.Push(11);
    SL.Print("SL");
    SL.sort();           //доп
    SL.Print("SL");
    SL.Print_element("EL 2",1);  //доп
    SL.Print_range("SL",5,10);  //доп
    //SL.Print("SL");
    SL.search(8);
    SL.del(10);
    SL.Print("SL");
    SL.search(11);
    SL.Empty();



    List<char> SL3;
    SL3.Push('a');
    SL3.Push('c');
    SL3.Push('b');
    SL3.Push('b');
    SL3.Push('f');
    SL3.Print("SL3");
    SL3.sort();           //доп
    SL3.Print("SL");
    SL3.Print_element("EL 3: ",2);  //доп
    SL3.Print_range("SL", 'a', 'c');  //доп
    SL3.search('f');
    SL3.del('f');
    SL3.Print("SL3");
    SL3.search('i');
    SL3.Empty();

    cout << "\n\n";
    List<double> SL2;
    SL2.Push(8.6);
    SL2.Push(5.1);
    SL2.Push(5.2);
    SL2.Push(10.9);
    SL2.Push(7.0);
    SL2.Print("SL2");
    SL2.search(10.9);
    SL2.del(7);
    SL2.Print("SL2");
    SL2.search(111);
    SL2.Empty();
}