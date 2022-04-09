#include <iostream>
#include<algorithm>

using namespace std;
//������� �������, ���������� ����� �����. ����� ������ ������������ ��� ������ ������� �������� ����������� ������� �������.


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

int pop (queue *&h,queue  *&t){ //�������� �������� �� �������
   queue *r = h; //������� ��������� �� ������
   int i = h->inf; //��������� �������� ������
   h = h->next; //�������� ��������� �� ��������� �������
    if (!h) //���� ������� ��������� ������� �� �������
     t = nullptr;
   delete r; //������� ������ �������
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