#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct tree
{
int inf;
tree *left;
tree *right;
tree *parent;
};
tree *node(int x){
 tree *n = new tree;
 n->inf = x;
 n->parent = nullptr;
 n->right = nullptr;
 n->left = nullptr;
 }

 void preorder (tree *tr){ // прямой обход (К-Л-П)

 if (tr){
 cout << tr->inf; //корень
 preorder( tr->left); //левое
 preorder( tr->right); //правое
 }
 }

 void postorder (tree *tr){ // обратный обход (Л-П-К)
 if (tr){
 postorder( tr->left); //левое
 postorder( tr->right); //правое
 cout << tr->inf; //корень
 }
 }

 void inorder (tree *tr){ // симметричный обход (Л-К-П)
 if (tr){
 inorder ( tr->left); //левое
 cout << tr->inf; //корень
 inorder ( tr->right); //правое
 }
 }
 void create(tree *&tr, int n){//create new node
 int x;
 if (n > 0){
 cin >> x;
 tr = node(x);
 int nl = n/2;
 int nr = n - nl - 1;
 create ( tr->left, nl);
 create ( tr->right,nr);
 }
 }
int lefth(tree *tr){//max left branch
 int k = 0;
 tree *x = tr;
 while (x){
 k++;
 x = x->left;
 }
 return k - 1;
 }

 int righth(tree *tr){//max right branch
 int k = 0;
 tree *x = tr;
 while (x){
 k++;
 x = x->right;
 }
 return k - 1;
 }
 void add(tree *&tr, int x){//add new node
 tree *n = node(x);
 tree *y = tr;
 if (lefth ( tr ) == righth(tr)){
 do{
 y = y->left;
 }
 while (y->left);
 if (!y->left) y->left = n;
 else y->right = n;
 }
 else{
 do{
 y = y->right;
 }
 while (y->right);
 if (!y->left) y->left = n;
 else y->right = n;
 }

 }

 void find(tree *tr, int x, tree *&res){//find node
 if (tr){
 if (tr->inf == x){
 res = tr;
 }
 else {
 find ( tr->left, x, res);
 find ( tr->right, x, res);
 }
 }
 }

 void del_n(tree *tr, int val){//dellete node
 tree *y;
 find ( tr , val, y);
 if (y){
 if(lefth( tr ) == 0) tr = nullptr;

else if(lefth(tr) != righth(tr)){
 tree *x = tr->left;
 do{
 x = x->left;
 }
 while(x->left->left);
 if(x->right){
 if(x->right->inf == val){
 x->right = nullptr;
 }
 else{
 y->inf = x->right->inf;
 x->right = nullptr;
 }
 delete x->right;
 }
 else{
 if(x->left->inf == val){
 x->left = nullptr;
 }
 else{
 y->inf = x->left->inf;
 x->left = nullptr;
 }
 
 }
 }
 else{
 tree *x = tr->right;
 do{
 x = x->right;
 }
 while(x->right->right);
 if(x->right){
 if(x->right->inf == val){
 x->right = nullptr;
 }
 else{
 y->inf = x->right->inf;
 x->right = nullptr;
 }
 
 }
 else{
 if(x->left->inf == val){
 x->left = nullptr;
 }
 else{
 y->inf = x->left->inf;
 x->left = nullptr;
 }
 
 }
 }
 }

 }

 void print(tree *tr, int k){//print tree
 if (! tr ) cout << "Empty tree\n";
 else{
 queue<tree*> cur, next;
 tree *r = tr;
 cur.push(r);
 int j = 0;
 while (cur.size()){
 if (j == 0) {
 for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
 cout << " ";
 }
 tree *buf = cur.front () ;
 cur.pop();
 j++;
 if (buf){
 cout << buf->inf;
 next.push(buf->left);
 next.push(buf->right);
 for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
 cout << " ";
 }
if (!buf){
 for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
 cout << " ";
 cout << " ";
 }
 if(cur.empty()){
 cout << endl;
 swap(cur, next);
 j = 0;
 k--;
 }
 }
 }}
 
void printk(tree*tr,int k,int n)
{
    
     if(tr){
     if(k==n){
         cout<<tr->inf<<"   ";
     }
     //recursive call
     k++;
     printk(tr->right,k,n);
     printk(tr->left,k,n);
     }
 }

 
 int main(){
 tree *tr = nullptr;
 int n, x;
 cin >> n;
 create ( tr , n);
 int k = int (log((float)n)/log((float)2.0));
 print ( tr , k);
 preorder( tr );
 cout << endl;
 cin>>n;
 cout<<endl;
 int m=1;
 printk(tr,m,n);
 return 0;
 }
