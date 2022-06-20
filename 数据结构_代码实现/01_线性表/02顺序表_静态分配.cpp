#include<iostream>
#include<stdio.h>
using namespace std;
#define MaxSize 10//最大长度

typedef struct
{
    /* data */
    int data[MaxSize];
    int length;
}SqList;

void Init(SqList &L)// 1.初始化
{
    for(int i=0;i<=MaxSize;i++)
    {
        L.data[i]=0;       
    }
    L.length=0;
}

//2. 插入操作，在表L的第i个位置上（位序）插入指定元素e
bool ListInsert(SqList &L,int i,int e) 
{//平均时间复杂度O(n)
    if(i<1||i>L.length+1)//判断i的范围（位序）是否有效
         return false;
    if(L.length>=MaxSize)//当前存储空间已经满了，不能插入
         return false;
    
    for(int j=L.length;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i]=e;
    L.length++;//记得长度+1
    return true;
}

//3.删除操作， 删除第i个位置上的元素,并把删除的值赋给e
bool ListDelete(SqList &L, int i,int &e)
{//平均时间复杂度O(n)
    if(i<1||i>L.length+1) return false;
    e=L.data[i-1];//将被删除的元素赋给e
    for(int j=i;j<L.length;j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;//记得长度-1
    return true;
}

//4.按位查找操作，获取表L中第i个位置的元素的值
int GetElem(SqList L,int  i)//这里就不用加&，因为不会改变原来L的值
{//时间复杂度O(1)
    return L.data[i-1];
}

//5.按值查找操作，在表L中查找具有给定关键字值的元素
int LocateElem(SqList L,int e)//平均时间复杂度：O(n)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
        {
            return i+1;//因为返回的是位序
        }
    }
    return 0;//退出循环，说明查找失败
}

//6.打印操作，打印出表L中的所有元素
void print(SqList L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
    cout<<endl;
}





int main()
{
    int n,m;
    cin>>n>>m;
    SqList L;
    Init(L);//元素赋值为0，长度赋值为0
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        L.data[i]=x;
        L.length++;
    }
    cout<<"Case 0:"<<endl;
    cout<<"Original Data:";
    print(L);
    cout<<"Original Length:"<<L.length<<endl;
    //***************************************
    
    for(int i=1;i<=m;i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        int op;
        cin>>op;
        if(op==1)//插入
        {
            int x,y;
            cin>>x>>y;
            ListInsert(L,x,y);
            cout<<"After Insert: ";
            print(L);
            cout<<"After Insert Length: "<<L.length<<endl;
        }
        else if(op==2)//删除
        {
            int e=-1;//被删除的元素的值
            int x;
            cin>>x;
            ListDelete(L,x,e);
            cout<<"After Delete: ";
            print(L);
            cout<<"Delete Data:"<<e<<endl;
            cout<<"After Delete Length: "<<L.length<<endl;
            
        }
    }
    
    return 0;
}

/*
测试：
假设有一批数据在线性表上，已知最大的数据量为1000，第一行输入n,m,
分别表示原始输入的元素个数和操作个数；第二行输入n个初始的线性表元素；
接下来m行操作，如果第一个数字是1，表示插入操作，如1 x y表示在第x个位置
上插入数值为y,然后输出操作后的结果；如果第一个数字是2，如2 x表示删除第
x个位置上的元素，然后输出操作后的结果以及删除的元素。
[input]
5 2              
1 2 3 4 5
1 2 14
2 4
[output]
Case 0:
Original Data: 1 2 3 4 5
Original Length: 5
Case 1:
After Insert: 1 14 2 3 4 5
After Insert Length: 6
Case 2:
After Delete: 1 14 2 4 5
Delete Data: 3
After Delete Length: 5

*/