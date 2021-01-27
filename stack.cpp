#include<iostream>
using namespace std;
template <class T>
class l_list
{
    public:
T data;
l_list *ptr;
    l_list(T a)
    {
      ptr=NULL;
      data=a;
    }
};

//****************************************************************************//
template <class T>
class stack
{
l_list<T> *ptr;   //it will point to just below elemenet
int count;
int capacity;
public:
    stack()
    {
        capacity=10;
        count=0;
        ptr=0;

    }
    int is_full(void);
    int is_empty(void);
    void push(T a);
    T pop(void);
    void get_all(void);
    int get_size(void);
    void modify_size();
    
~stack()
{
    l_list <T> *temp;
    if(ptr!=NULL)
    while(ptr)
    {
        temp=ptr->ptr;
        delete ptr;
        ptr=temp;

        
    }
}
    

};


//*******************************************************************************//


template <class T>
void stack<T>::modify_size()
{
    cout<<"enter capacity"<<endl;
    int size;
    cin>>size;
    capacity=size;
}


//***********************
template <class T>
int stack<T>::get_size()
{
    return capacity;
}


//**********************
template <class T>
void stack<T>::push(T a)
{
        if(count==capacity)
        {
            cout<<"stack is full\n";
            return;
        }
        l_list<T> *temp=new l_list<T>(a);
        temp->ptr=ptr;
        ptr=temp;
        count++;
}

//**********************pop***********//
template <class T>
T stack<T>::pop()
{
    T d;
     if(ptr==NULL)
     {
      cout<<"stack is empty"<<endl;
            return d;
    }
     l_list<T> *temp;
     temp=ptr; 
     ptr=ptr->ptr;
     count--;
     d=temp->data;
     delete temp;
     return d;
}


//*************************
template <class T>
void stack<T>::get_all()
{
l_list<T> *temp;
temp=ptr;
while(temp)
{
cout<<temp->data<<" ";
temp=temp->ptr;
}
cout<<endl;
}
template <class T>
int stack<T>::is_full()
{
    if(count==capacity)
    return 1;
    return 0;
}

//***************************
template <class T>
int stack<T>::is_empty()
{
    if(count==0)
    return 1;
    return 0;
}