#include <iostream>
#include <string>
#include <queue>
using namespace std;
//第一行给出树结点数量0---n-1
//n行 对于节点给出左节点和右节点

typedef struct node{
    int num;
    struct node* left,*right;
}*Node;

queue <Node> numbers;

typedef struct record{
    int left;
    int right;
}Record;

Node createNode(Record *r,int id){
    if(id!=-1){
        
    Record* cur=&r[id];
    Node newNode=new struct node;
    //cout<<"id "<<id<<" left"<<cur->left<< "  right"<<cur->right<<endl;
    newNode->num=id;
    newNode->left=createNode(r,cur->left);
    newNode->right=createNode(r,cur->right);
    Node exchange = newNode->left;
    newNode->left = newNode->right;
    newNode->right = exchange;
    return newNode;
    }
    else return NULL;
    
}
//lev=1;
int i=0;
void level(){
    while(numbers.size()!=0){
        Node printNode=numbers.front();
        if(i!=0)cout<<' ';
        cout<<printNode->num;
        i=1;
        numbers.pop();
        if(printNode->left!=NULL)numbers.push(printNode->left);
        if(printNode->right!=NULL)numbers.push(printNode->right);
    }
    return;
}

void inv(Node n){
    if(n!=NULL){
        inv(n->left);
        if(i!=0)cout<<' ';
        cout<<n->num;
        i=1;
        inv(n->right);
    }
    else return;
}

//找到那个没有被点击过的结点
int main(){
    int n;
    scanf("%d\n",&n);
    int* count=new int[n];
    for(int i=0;i<n;i++){count[i]=-1;}
    Record *rec=new Record[n];
    for(int i=0;i<n;i++){
        char a,b;
        scanf("%c %c\n",&a,&b);
        //这里参考 https://www.liuchuo.net/archives/2166
        //可以使用string读入
        //然后转化成数字 方法是 int i = stoi(stringName);
        rec[i].left=rec[i].right=-1;
        if(a<='9'&&a>='0'){
            count[a-'0']=1;
            rec[i].left=a-'0';
        }
        if(b<='9'&&b>='0'){
            count[b-'0']=1;
            rec[i].right=b-'0';
        }        
    }
    int index;
    for(index = 0;index < n; index++ ){
        if(count[index]==-1)break;
    }
    //cout<<"index "<<index<<endl;
    //找到第一层的index
    Node tree = createNode(rec,index);
    i=0;
    numbers.push(tree);
    level();
    cout<<endl;
    i=0;
    inv(tree);
}
//vector<node> v2(v1); 将v1的所有元素放到v2中