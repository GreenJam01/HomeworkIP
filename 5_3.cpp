#include <iostream>
#include<algorithm>

using namespace std;
//Your selection: —оздать очередь, содержащую числа. ¬ новой очереди сначала вывести отрицательные, потом положительные числа.

struct queue{
    int inf;
    queue *next;
};

void push(queue *&h,queue *&t,int x){
    queue *r = new queue;
    r->inf=x;
    r->next=nullptr;
    if (!h && !t){
        h=t=r;
    }
    else{
        t->next=r;
        t=r;
    }
}

int pop (queue *&h,queue  *&t){ //удаление элемента из очереди
   queue *r = h; //создаем указатель на голову
   int i = h->inf; //сохран€ем значение головы
   h = h->next; //сдвигаем указатель на следующий элемент
    if (!h) //если удал€ем последний элемент из очереди
     t = nullptr;
   delete r; //удал€ем первый элемент
   return i;
 }
 int main (){
     queue *h,*t,*h1,*t1,*resh,*rest;
     h=t=h1=t1=resh=rest=nullptr;
     int n,a;
     cout<<"insert quantity\n";
     cin>>n;
     cout<<"Insert digits\n";
    for (int i =0;i<n;++i){
    cin>>a;
    push(h,t,a);
    }
    
    /*while (h)
    {
        
        a=pop(h,t);
        cout<<a;
    }*/
    
    while (h){
        
        if (h->inf>0){
            a=pop(h,t);
            push(h1,t1,a);}
        else{a=pop(h,t);
            push(resh,rest,a);}
    }
    while(h1){a=pop(h1,t1);
            push(resh,rest,a);
        
    }
    
    while (resh)
    {
        a=pop(resh,rest);
        cout<<a<<" ";
    }
    

     return 0;
 }
 

