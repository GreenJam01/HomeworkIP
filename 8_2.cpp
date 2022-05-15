#include<iostream>
#include<iomanip>
#include<map>
#include<list>
#include<algorithm>
#include<cmath>
#include <fstream>
using namespace std;
//Your selection: ��� ����������������� ����. �������� � ���� �����, ����������� ������� A � B.
ifstream in("8.txt"); //��� ������
bool orient=0;

void add(map<int, list<pair<int, double>>> &l_Adj,int x,int y, int w=0){
    if (!w) //check weight
 w = 1.0;
 auto it_x = l_Adj.find(x); //check existing x
 bool fl = true;
 if (it_x != l_Adj.end()) {//if x exist
 for (auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++)
 if (it_y->first == y) { //
 fl = false; //if y exist already
 break;
 }
 }
 if (orient) {//if orirnt
 if (fl) {//if edge dont exist
 l_Adj[x].push_back(make_pair(y, w));//add edge x -> y 
 if (l_Adj.find(y) == l_Adj.end()) {//if y dont exist add imagine edge 0
 l_Adj[y].push_back(make_pair(0, 0)); //add 0

 auto it = l_Adj.find(y); //
 it->second.erase(it->second.begin()); //erase imagine edge
 //it's only one
 }
 }
 }
 else if (fl) {//if graph isnt oriented
 l_Adj[x].push_back(make_pair(y, w));//edge x->y
 l_Adj[y].push_back(make_pair(x, w));//edge y->x
 }

}

int main(){
map<int, list<pair<int, double>>>l_Adj;
int x,y,w;
bool orient;
while (in.peek() != EOF) {
 in >> x >> y >> w; // input point
 add(l_Adj,x,y,w);
 }

cout<<"input x and y\n";
cin>>x>>y;
add(l_Adj,x,y);
 for (auto it = l_Adj.begin(); it != l_Adj.end(); it++) {//output list of adjacencies
 cout << it->first << " : ";// output point
 if (w) {//weight
 for (auto it_1 = it->second.begin(); it_1 != it->second.end();it_1++){
 cout << "{" << it_1->first << ", " << it_1->second <<"};";}
 }
 else {
 for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++)
cout << it_1->first << "; ";
 }
 cout << endl;
 }
 


return 0;
}