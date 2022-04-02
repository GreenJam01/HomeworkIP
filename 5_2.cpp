#include <algorithm>
#include<iostream>
#include<string>
using namespace std;
//Создать стек, содержащий числа. Удалить из стека все максимальные элементы
struct Stack{//создание класса стек
    Stack * next;
    int inf;
};
void push(Stack *&s,int x){//добавление нового элемента
    Stack *r= new Stack;
    r->inf=x;
    r->next=s;
    s=r; 
}
int pop(Stack *&s){//удаление головы
    int i = s->inf;
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
    int n,a,maxel=INT_MIN;

    Stack* s = nullptr;
    cout<<"insert quantity\n";
cin>>n;
cout<<"Insert digits\n";
for (int i =0;i<n;++i){
    cin>>a;
    push(s,a);
    maxel= max(maxel,a);
}
Stack * rez=nullptr;
while (s)
{
    int a = pop(s);
    if(a!=maxel){//добавление нужных элементов
        push(rez,a);
    }
}
//reverse(rez);
while (rez){
    int i=pop(rez);
    cout<<i<<"  ";
}




    return 0;
}