#include <algorithm>
#include<iostream>
#include<string>
using namespace std;
//Ваш выбор: Создать стек, содержащий слова. В новый стек записать все слова, которые не заканчиваются на заданную букву

struct Stack{//создание класса стек
    Stack * next;
    string inf;
};
void push(Stack *&s,string x){//добавление нового элемента
    Stack *r= new Stack;
    r->inf=x;
    r->next=s;
    s=r; 
}
string pop(Stack *&s){//удаление головы
    string i = s->inf;
    Stack *r=s;
    s=s->next;
    delete r;
    return i;
}
void reverse(Stack *&s){//обрптить стек задом наперед
    Stack * r = new Stack;
    while (s){
        push(r, pop(s));
    }
    s=r;
}
int main (){
    string a;
    int n;
    char x;
    Stack* s = nullptr;
    cout<<"insert letter\n";
    cin>>x;
    cout<<"insert quantity\n";
    cin>>n;
cout<<"Insert word\n";
for (int i=0;i<n;++i){
    cin>>a;
    push(s,a);
   
}
Stack * rez=nullptr;
while (s)
{
    string a = pop(s);
    if(a[a.size()-1]!=x){//добавление нужных элементов
        push(rez,a);
    }
}
//reverse(rez);
while (rez){
    string i=pop(rez);
    cout<<i<<"  ";
}




    return 0;
}