#include<iostream>
#include<iomanip>
#include<map>
#include<list>
#include<algorithm>
#include<cmath>
#include<vector>
#include <fstream>
#include <set>
using namespace std;
//Your selection: Дан неориентированный граф. Определить содержит ли он циклы. Если да, то вывести их.
ifstream in("8.txt"); //для чтения
bool orient=0;
set<vector<int>> cycles;
set<vector<int>>cycles_sort;
int cycle_st, cycle_end;
void insertsort(vector<int>& a){
    int n=a.size();
    for (int i =1;i<n;++i){
        int j=i;
        while ((j>0)&& (a[j]<a[j-1])){
            swap(a[j],a[j-1]);
            --j;
        }
    }
}

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

void DFC(map<int, list<pair<int, double>>> &l_Adj,vector<int>&used,vector<int>&path,int x){
 used[x]=1;
 path.push_back(x);
 auto it = l_Adj.find(x);
 if(it!=l_Adj.end()){
 for (auto it_1 = it->second.begin(); it_1 != it->second.end();it_1++){
    if(used[it_1->first]==0)DFC(l_Adj,used,path,it_1->first);
    }
     
 }
}

void Addcycle(int start, int end,vector<int>&pr){
    int cur = end;
    vector<int>temp;
    while(cur!=start){
        temp.push_back(cur);
        cur=pr[cur];
    }
    temp.push_back(start);
    reverse(temp.begin(),temp.end());
    cycles.insert(temp);
    insertsort(temp);
    cycles_sort.insert(temp);
    
}

void search_cycle(map<int, list<pair<int, double>>> &l_Adj,vector<int>&used,vector<int>&pr,int x){
    used[x]=1;
    auto it = l_Adj.find(x);
    if(it!=l_Adj.end()){
    for (auto it_1 = it->second.begin(); it_1 != it->second.end();it_1++){
      if(it_1->first == pr[x]) continue;
      if(!used[it_1->first])
        {
        pr[it_1->first]=x;
        search_cycle(l_Adj,used, pr,it_1->first);
        }
      else if(used[it_1->first]==1) Addcycle(it_1->first,x,pr);
    } 
    used[x]=0;
}
}
int main(){ 
 map<int, list<pair<int, double>>>l_Adj;
 
 int x,y,w;
 while (in.peek() != EOF) {
  in >> x >> y >> w; // input point
  add(l_Adj,x,y,w);
  }
 vector <int>used(l_Adj.size(),0),path,pr(l_Adj.size(),-1); 
 //auto n = l_Adj.begin()->first;
 //DFC(l_Adj,used,path,n);
 for (auto it = l_Adj.begin(); it != l_Adj.end(); it++) {//output list of adjacencies
 cout << it->first << " : ";// output point
 if (w) {//weight
 for (auto it_1 = it->second.begin(); it_1 != it->second.end();it_1++){
 cout << "{" << it_1->first << ", " << it_1->second <<"};";}
 }
 else {
 for (auto it_1 = it->second.begin(); it_1 != it->second.end(); it_1++){
cout << it_1->first << "; ";}
 }
 cout << endl;
 }
 search_cycle(l_Adj,used,pr, 0);

for(auto it = cycles_sort .begin(); it != cycles_sort.end(); ++it){//output cycles
    for(auto it2 = (*it).begin(); it2 != (*it).end(); ++it2){
        cout<<*it2;
    }
    cout<<endl;
}


return 0;
}