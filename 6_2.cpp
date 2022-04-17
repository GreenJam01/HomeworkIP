#include <algorithm>
#include<iostream>
using namespace std;

//������� ���������� ������, ���������� ����� �����. �������� ������, ���������� � ������ ������ �����, ����� ��������. ������� ���������� �����
//������ �������� �������.

struct list
{
    int inf;
    list * next;
    list* prev;
};
void push(list *&h,list*&t,int x){
    list *r = new list; //������� ����� �������
 r->inf = x;
 r->next = nullptr; //������ ���������
 if (!h && !t){ //���� ������ ����
 r->prev = nullptr; //������ �������
 h = r; //��� ������
 }
 else{
 t->next = r; //r - ��������� ��� ������
 r->prev = t; //����� - ���������� ��� r
 }
 t = r; //r ������ �����
 }

 void print ( list *h, list *t){ //������ ��������� ������
 list *p = h; //�������� �� ������
 while (p){ //���� �� ����� �� ����� ������
 cout << p->inf << " ";
 p = p->next; //������� � ���������� ��������
 }
 }
list *find ( list *h, list *t, int x){ //����� ��������� ������
 list *p = h; //�������� �� ������
 while (p){ //���� �� ����� �� ����� ������
 if (p->inf == x) break; // ���� �����, ���������� ����
 p = p->next; //������� � ���������� ��������
 }
 return p;
}
void insert_after ( list *&h, list *&t, list *r, int y){ //��������� ����� r
 list *p = new list; //������� ����� �������
 p->inf = y;
 if (r == t){ //���� ��������� ����� ������
 p->next = nullptr; //����������� ��-� - ���������
 p->prev = r; //��������� ����� r
 r->next = p;
 t = p; //������ ����� - p
 }
 else{ //��������� � �������� ������
 r->next->prev = p; //��� ���������� �� r ��-�� ���������� - p
 p->next = r->next; //��������� �� p - ��������� �� r
 p->prev = r; //p ��������� ����� r
 r->next = p;
 }
}

void del_node(list *&h, list *&t, list *r)//������� ����� r
{ 
 if (r == h && r == t) //������������ ������� ������
 h = t = nullptr;
 else if (r == h){ //������� ������ ������
 h = h->next; //�������� ������
 h->prev = nullptr;

 }
 else if (r == t){ //������� ����� ������
 t = t->prev; //�������� �����
 t->next = nullptr;
 }
 else{
 r->next->prev = r->prev; //��� ���������� �� r ����������

 r->prev->next = r->next; //��� ����������� �� r ���������

 }
 delete r; //������� r
 }
  void del_list( list *&h, list *&t){ //������� ������
 while (h){ //���� ������ �� ����
 list *p = h; //��������� �� ������
 h = h->next; //��������� ������
 h->prev = NULL; //��������
 delete p;
 }
  }
 int main(){
     
     list *h,*t,*h1,*t1,*h2,*t2;
     h=t=h1=t1=h2=t2=nullptr;
     int n,a;
     cout<<"insert quantity\n";
     cin>>n;
     cout<<"Insert digits\n";
     for (int i =0;i<n;++i){
     cin>>a;
     cout<<1;
     push(h,t,a);
     
    }

    while (h)
    {
        if(h->inf %2){push (h1,t1,h->inf);del_node(h,t,h);}
        else{push (h2,t2,h->inf);del_node(h,t,h);}
    }
    del_list(h,t);
    h=nullptr;
    
    while(h2){push(h,t,h2->inf);del_node(h2,t2,h2);}
    while(h1){push(h,t,h1->inf);del_node(h1,t1,h1);}
    print(h,t);

    
     return 0;
 }
