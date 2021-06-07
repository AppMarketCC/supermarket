#pragma once
#include<iostream>
#include<fstream>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int n = 0; //全局数据,结点数量

class Goods
{
protected:
    char name[20]; //商品名称
    double num; //商品代码
    char person[30]; //经办人
    int price; //进货价
    double amount; //库存量
    Goods* next;
public:
    //无参构造函数
    Goods()
    {
       
    }

    //构造函数
    Goods(double num, char* name, char* person, int price, double amount)
    {
        this->num = num;
        strcpy_s(this->name, name);
        strcpy_s(this->person, person);
        this->price = price;
        this->amount = amount;
    }
    void Output()
    {
        cout << "num:" << num << " name:" << name << " person:" << person << " price:" << price << " amount:" << amount << endl;
    }
    friend class Supermarket;
};
class Supermarket
{
private:
    Goods* goods; //商品表，商品表的头节点
    void Clear(); //清除内存中数据

public:
    Supermarket()
    {
        goods = NULL;
        Load();
    }~Supermarket()
    {
        Goods* p;
        p = goods;
        while (p)
        {
            p = p->next;
            delete goods;
            goods = p;
        }
        goods = NULL;
    }
    void Add(); //增加商品
    void Delete(); //删除商品
    void Modify(); //修改商品
    void Query(); //查询商品
    void Add_up(); //统计商品
    void Save(); //基础数据存盘
    void Load(); //基础数据装入
};
void Supermarket::Clear() //清除内存中商品数据（内部使用）
{
    Goods* p;
    p = goods;
    while (p)
    {
        goods = p->next;
        delete p;
        p = goods;
    }
}


void Supermarket::Add()//添加商品
{
    Goods* p;
    double num, amount;
    char name[20], person[30];
    int price;
    cout << "\n请输入新增商品信息：\n";
    cout << "商品代码:"; cin >> num;
    cout << "商品名称:"; cin >> name;
    cout << "商品产地:"; cin >> person;
    cout << "商品单价:"; cin >> price;
    cout << "该商品库存量:"; cin >> amount;//创建新商品类结点
    p = new Goods(num, name, person, price, amount);
    p->next = NULL;
    if (goods == NULL)
    {
        goods = p;
        n++;
    }
    else
    {
        Goods* p2 = goods;
        while (p2->next)
            p2 = p2->next;
        p2->next = p;
        n++;
    }
}
void Supermarket::Delete() //删除商品
{
    char name[20];
    cout << "\n请输入要删除的商品名称:\n";
    cin >> name;//查找要删除的结点
    Goods* p1, * p2; 
    p2=p1 = goods;
    
    while (p1)
    {
        if (strcmp(p1->name, name) == 0) break;
        else
        {
            p2 = p1;
            p1 = p1->next;
        }
    }
    //删除结点
    if (p1 != NULL) //若找到结点，则删除
    {
        if (p1 == goods) //若要删除的结点是第一个结点
        {
            goods = p1->next;
            delete p1;
            n--;
        }
        else //若要删除的结点是后续结点
        {
            p2->next = p1->next;
            delete p1;
            n--;
        }
        cout << "找到并删除\n";
    }
    else //未找到结点
        cout << "Sorry,未找到!\n";
}


void Supermarket::Modify() //修改商品信息
{
    double num, amount;
    char name[20], person[30];
    int price;
    cout << "\n 修改商品，请输入要查的商品名称：\n";
    cout << "Name:"; cin >> name;//查找要修改的结点
    Goods* p1, * p2; 
    //p1指向头节点
    p2 = p1 = goods;

    while (p1)
    {
        if (strcmp(p1->name, name) == 0) break;
        else
        {
            p2 = p1;
            p1 = p1->next;
        }
    }//修改结点
    if (p1 != NULL) //若找到结点
    {
        p1->Output();
        cout << "\n请选择要修改的信息（1—商品代码，2—商品名称，3—产地，4—单价，5—该商品库存量，6—修改全部信息）:\n";
        int a;//代表需要修改的商品属性
        cin >> a;
        switch (a)
        {
        case 1:cout << "请输入新代码：";
            cin >> num;
            strcpy_s(name, p1->name); 
            strcpy_s(person, p1->person); 
            price = p1->price; amount = p1->amount;
            break;
        case 2:cout << "请输入新名称：";
            cin >> name;
            num = p1->num; 
            strcpy_s(person, p1->person);
            price = p1->price;
            amount = p1->amount; 
            break;
        case 3:cout << "请输入新产地：";
            cin >> person;
            num = p1->num; 
            strcpy_s(name, p1->name); 
            price = p1->price; amount = p1->amount;
            break;
        case 4:cout << "请输入新单价："; cin >> price;
            num = p1->num;
            strcpy_s(name, p1->name);
            strcpy_s(person, p1->person); 
            amount = p1->amount;
            break;
        case 5:cout << "请输入新库存数据：";
            cin >> amount;
            num = p1->num; 
            strcpy_s(name, p1->name); 
            strcpy_s(person, p1->person);
            price = p1->price; break;
        case 6:cout << "请输入新信息：\n";
            cout << "商品代码:"; cin >> num;
            cout << "商品名称:"; cin >> name;
            cout << "商品产地:"; cin >> person;
            cout << "商品单价:"; cin >> price;
            cout << "该商品库存量:"; cin >> amount; 
            break;
        }//创建新商品结点


        Goods* p3;
        p3 = new Goods(num, name, person, price, amount);

        //员工结点替换到链表
        p3->next = p1->next;
        if (p1 == goods) //若要替换的结点是第一个结点
            goods = p3;
        else //若要替换的结点是后续结点
            p2->next = p3;

        delete p1; //删除原来的商品结点
        cout << "修改成功!\n";
    }
    else //未找到结点
        cout << "Sorry,未找到!\n";
}


void Supermarket::Query()//查询商品
{
    cout << "\n****查询商品****\n";
    char name[20];
    cout << "\n请输入要查询的商品名称：\n";
    cin >> name;
    Goods* p1 = goods;
    while (p1)
    {
        if (strcmp(p1->name, name) == 0) break;
        else p1 = p1->next;
    }
    if (p1 != NULL) //若找到结点
    {
        cout << "\n要查询的信息如下：\n";
        cout << "该类商品代码:\t" << p1->num << "\t" << "该类商品名称:\t" << p1->name << "\t\n";
        cout << "该类商品产地:\t" << p1->person << "\t" << "该类商品单价:\t" << p1->price << "\t\n";
        cout << "该类商品库存量:\t" << p1->amount << "\t";
    }
    else //未找到结点
        cout << "\nSorry,未找到该类商品!\n";
}


void Supermarket::Add_up() //统计超市商品总数量于价值
{
    cout << "\n****商品统计****\n";
    double Amount = 0, Value = 0;
    char name[20];
    cout << "\n请输入要统计的商品名称：\n";
    cin >> name;
    Goods* p1;
    p1 = goods;
    while (p1)
    {
        if (strcmp(p1->name, name) == 0) break;
        else p1 = p1->next;
    }
    if (p1)
    {
        while (p1)
        {
            Amount += p1->amount;
            Value += p1->amount * p1->price;
            p1 = p1->next;
        }
        cout << "商品总数量是：\n";
        cout << Amount;
        cout << "\n商品总价值是：\n";
        cout << Value;
    }
    else
        cout << "\nSorry,未找到该类商品!\n";
}


void Supermarket::Save() //数据存盘
{
    cout << "是否保存？[Y/N]";
    char a;
    cin >> a;
    if (a == 'n')return;
    if (a == 'y' || a == 'Y')
    {
        ofstream outfile("base.dat", ios::out | ios::app);
        if (!outfile) { cerr << "open error!"; exit(1); }
        Goods* p; p = goods;
        while (p)
        {
            outfile << p->num << endl;
            outfile << p->name << endl;
            outfile << p->person << endl;
            outfile << p->price << endl;
            outfile << p->amount << endl;
            cout << endl;
            p = p->next;
        }
        outfile.close();
        cout << "已完成数据的保存\n";
    }
}


void Supermarket::Load() //数据装入
{
    Goods* p = goods;
    //将数据装入文件
    ifstream infile("base.dat", ios::in | ios::binary);//读一条信息
    if (!infile.good())
        return;
    p = new Goods();
    infile >> p->num >> p->name >> p->person >> p->price >> p->amount;
    while (infile.good())
    {
        //创建商品结点
        p = new Goods(p->num, p->name, p->person, p->price, p->amount);
        p->next = NULL;
        //商品结点加入
        if (goods) //若已存在结点
        {
            p->next = goods;
            goods = p;
            //Goods*p2;
            //p2=goods;
            //while(p2->next) //查找尾结点
            //  p2=p2->next;
            //p2->next=p; //连接
        }
        else //表空
            goods = p; //连接
        //读下一条信息
        infile >> p->num >> p->name >> p->person >> p->price >> p->amount;
    }
    cout << "\n商品数据已经装入\n";
}
