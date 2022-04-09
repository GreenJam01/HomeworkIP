#include <iostream>
#include<algorithm>

using namespace std;
//Создать очередь, содержащую целые числа. Перед каждым максимальным эле ментом очереди вставить минимальный элемент очереди.


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
   int i = h->inf; //сохраняем значение головы
   h = h->next; //сдвигаем указатель на следующий элемент
    if (!h) //если удаляем последний элемент из очереди
     t = nullptr;
   delete r; //удаляем первый элемент
   return i;
 }
 int main (){
     int minel = INT_MAX, maxel = INT_MIN;
     queue *h,*t,*h1,*t1,*resh,*rest;
     h=t=h1=t1=resh=rest=nullptr;
     int n,a;
     cout<<"insert quantity\n";
     cin>>n;
     cout<<"Insert digits\n";
    for (int i =0;i<n;++i){
    cin>>a;
    minel = min(a,minel);
    maxel = max(maxel,a);
    push(h,t,a);
    }
    while (h){
        a=pop(h,t);
        if(a==maxel){push(resh,rest,minel);push(resh,rest,a);}
        else{push(resh,rest,a);}
    }





       while (resh)
    {
        a=pop(resh,rest);
        cout<<a<<" ";
    }
    

     return 0;
 }