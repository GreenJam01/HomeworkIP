#include <algorithm>
#include<iostream>
using namespace std;

//Создать двусвязный список, содержащий целые числа. Изменить список, переместив в начало четные числа, потом нечетные. Порядок следования чисел
//должен остаться прежним.

struct list
{
    int inf;
    list * next;
    list* prev;
};
void push(list *&h,list*&t,int x){
    list *r = new list; //создаем новый элемент
 r->inf = x;
 r->next = nullptr; //всегда последний
 if (!h && !t){ //если список пуст
 r->prev = nullptr; //первый элемент
 h = r; //это голова
 }
 else{
 t->next = r; //r - следующий для хвоста
 r->prev = t; //хвост - предыдущий для r
 }
 t = r; //r теперь хвост
 }

 void print ( list *h, list *t){ //печать элементов списка
 list *p = h; //укзатель на голову
 while (p){ //пока не дошли до конца списка
 cout << p->inf << " ";
 p = p->next; //переход к следующему элементу
 }
 }
list *find ( list *h, list *t, int x){ //поиск элементов списка
 list *p = h; //укзатель на голову
 while (p){ //пока не дошли до конца списка
 if (p->inf == x) break; // если нашли, прекращаем цикл
 p = p->next; //переход к следующему элементу
 }
 return p;
}
void insert_after ( list *&h, list *&t, list *r, int y){ //вставляем после r
 list *p = new list; //создаем новый элемент
 p->inf = y;
 if (r == t){ //если вставляем после хвоста
 p->next = nullptr; //вставляемый эл-т - последний
 p->prev = r; //вставляем после r
 r->next = p;
 t = p; //теперь хвост - p
 }
 else{ //вставляем в середину списка
 r->next->prev = p; //для следующего за r эл-та предыдущий - p
 p->next = r->next; //следующий за p - следующий за r
 p->prev = r; //p вставляем после r
 r->next = p;
 }
}

void del_node(list *&h, list *&t, list *r)//удаляем после r
{ 
 if (r == h && r == t) //единственный элемент списка
 h = t = nullptr;
 else if (r == h){ //удаляем голову списка
 h = h->next; //сдвигаем голову
 h->prev = nullptr;

 }
 else if (r == t){ //удаляем хвост списка
 t = t->prev; //сдвигаем хвост
 t->next = nullptr;
 }
 else{
 r->next->prev = r->prev; //для следующего от r предыдущим

 r->prev->next = r->next; //для предыдущего от r следующим

 }
 delete r; //удаляем r
 }
  void del_list( list *&h, list *&t){ //удаляем список
 while (h){ //пока список не пуст
 list *p = h; //указатель на голову
 h = h->next; //переносим голову
 h->prev = NULL; //обнуляем
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
