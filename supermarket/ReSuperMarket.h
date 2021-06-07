#pragma once
#include<iostream>
#include<fstream>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int n = 0; //ȫ������,�������

class Goods
{
protected:
    char name[20]; //��Ʒ����
    double num; //��Ʒ����
    char person[30]; //������
    int price; //������
    double amount; //�����
    Goods* next;
public:
    //�޲ι��캯��
    Goods()
    {
       
    }

    //���캯��
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
    Goods* goods; //��Ʒ����Ʒ���ͷ�ڵ�
    void Clear(); //����ڴ�������

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
    void Add(); //������Ʒ
    void Delete(); //ɾ����Ʒ
    void Modify(); //�޸���Ʒ
    void Query(); //��ѯ��Ʒ
    void Add_up(); //ͳ����Ʒ
    void Save(); //�������ݴ���
    void Load(); //��������װ��
};
void Supermarket::Clear() //����ڴ�����Ʒ���ݣ��ڲ�ʹ�ã�
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


void Supermarket::Add()//�����Ʒ
{
    Goods* p;
    double num, amount;
    char name[20], person[30];
    int price;
    cout << "\n������������Ʒ��Ϣ��\n";
    cout << "��Ʒ����:"; cin >> num;
    cout << "��Ʒ����:"; cin >> name;
    cout << "��Ʒ����:"; cin >> person;
    cout << "��Ʒ����:"; cin >> price;
    cout << "����Ʒ�����:"; cin >> amount;//��������Ʒ����
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
void Supermarket::Delete() //ɾ����Ʒ
{
    char name[20];
    cout << "\n������Ҫɾ������Ʒ����:\n";
    cin >> name;//����Ҫɾ���Ľ��
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
    //ɾ�����
    if (p1 != NULL) //���ҵ���㣬��ɾ��
    {
        if (p1 == goods) //��Ҫɾ���Ľ���ǵ�һ�����
        {
            goods = p1->next;
            delete p1;
            n--;
        }
        else //��Ҫɾ���Ľ���Ǻ������
        {
            p2->next = p1->next;
            delete p1;
            n--;
        }
        cout << "�ҵ���ɾ��\n";
    }
    else //δ�ҵ����
        cout << "Sorry,δ�ҵ�!\n";
}


void Supermarket::Modify() //�޸���Ʒ��Ϣ
{
    double num, amount;
    char name[20], person[30];
    int price;
    cout << "\n �޸���Ʒ��������Ҫ�����Ʒ���ƣ�\n";
    cout << "Name:"; cin >> name;//����Ҫ�޸ĵĽ��
    Goods* p1, * p2; 
    //p1ָ��ͷ�ڵ�
    p2 = p1 = goods;

    while (p1)
    {
        if (strcmp(p1->name, name) == 0) break;
        else
        {
            p2 = p1;
            p1 = p1->next;
        }
    }//�޸Ľ��
    if (p1 != NULL) //���ҵ����
    {
        p1->Output();
        cout << "\n��ѡ��Ҫ�޸ĵ���Ϣ��1����Ʒ���룬2����Ʒ���ƣ�3�����أ�4�����ۣ�5������Ʒ�������6���޸�ȫ����Ϣ��:\n";
        int a;//������Ҫ�޸ĵ���Ʒ����
        cin >> a;
        switch (a)
        {
        case 1:cout << "�������´��룺";
            cin >> num;
            strcpy_s(name, p1->name); 
            strcpy_s(person, p1->person); 
            price = p1->price; amount = p1->amount;
            break;
        case 2:cout << "�����������ƣ�";
            cin >> name;
            num = p1->num; 
            strcpy_s(person, p1->person);
            price = p1->price;
            amount = p1->amount; 
            break;
        case 3:cout << "�������²��أ�";
            cin >> person;
            num = p1->num; 
            strcpy_s(name, p1->name); 
            price = p1->price; amount = p1->amount;
            break;
        case 4:cout << "�������µ��ۣ�"; cin >> price;
            num = p1->num;
            strcpy_s(name, p1->name);
            strcpy_s(person, p1->person); 
            amount = p1->amount;
            break;
        case 5:cout << "�������¿�����ݣ�";
            cin >> amount;
            num = p1->num; 
            strcpy_s(name, p1->name); 
            strcpy_s(person, p1->person);
            price = p1->price; break;
        case 6:cout << "����������Ϣ��\n";
            cout << "��Ʒ����:"; cin >> num;
            cout << "��Ʒ����:"; cin >> name;
            cout << "��Ʒ����:"; cin >> person;
            cout << "��Ʒ����:"; cin >> price;
            cout << "����Ʒ�����:"; cin >> amount; 
            break;
        }//��������Ʒ���


        Goods* p3;
        p3 = new Goods(num, name, person, price, amount);

        //Ա������滻������
        p3->next = p1->next;
        if (p1 == goods) //��Ҫ�滻�Ľ���ǵ�һ�����
            goods = p3;
        else //��Ҫ�滻�Ľ���Ǻ������
            p2->next = p3;

        delete p1; //ɾ��ԭ������Ʒ���
        cout << "�޸ĳɹ�!\n";
    }
    else //δ�ҵ����
        cout << "Sorry,δ�ҵ�!\n";
}


void Supermarket::Query()//��ѯ��Ʒ
{
    cout << "\n****��ѯ��Ʒ****\n";
    char name[20];
    cout << "\n������Ҫ��ѯ����Ʒ���ƣ�\n";
    cin >> name;
    Goods* p1 = goods;
    while (p1)
    {
        if (strcmp(p1->name, name) == 0) break;
        else p1 = p1->next;
    }
    if (p1 != NULL) //���ҵ����
    {
        cout << "\nҪ��ѯ����Ϣ���£�\n";
        cout << "������Ʒ����:\t" << p1->num << "\t" << "������Ʒ����:\t" << p1->name << "\t\n";
        cout << "������Ʒ����:\t" << p1->person << "\t" << "������Ʒ����:\t" << p1->price << "\t\n";
        cout << "������Ʒ�����:\t" << p1->amount << "\t";
    }
    else //δ�ҵ����
        cout << "\nSorry,δ�ҵ�������Ʒ!\n";
}


void Supermarket::Add_up() //ͳ�Ƴ�����Ʒ�������ڼ�ֵ
{
    cout << "\n****��Ʒͳ��****\n";
    double Amount = 0, Value = 0;
    char name[20];
    cout << "\n������Ҫͳ�Ƶ���Ʒ���ƣ�\n";
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
        cout << "��Ʒ�������ǣ�\n";
        cout << Amount;
        cout << "\n��Ʒ�ܼ�ֵ�ǣ�\n";
        cout << Value;
    }
    else
        cout << "\nSorry,δ�ҵ�������Ʒ!\n";
}


void Supermarket::Save() //���ݴ���
{
    cout << "�Ƿ񱣴棿[Y/N]";
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
        cout << "��������ݵı���\n";
    }
}


void Supermarket::Load() //����װ��
{
    Goods* p = goods;
    //������װ���ļ�
    ifstream infile("base.dat", ios::in | ios::binary);//��һ����Ϣ
    if (!infile.good())
        return;
    p = new Goods();
    infile >> p->num >> p->name >> p->person >> p->price >> p->amount;
    while (infile.good())
    {
        //������Ʒ���
        p = new Goods(p->num, p->name, p->person, p->price, p->amount);
        p->next = NULL;
        //��Ʒ������
        if (goods) //���Ѵ��ڽ��
        {
            p->next = goods;
            goods = p;
            //Goods*p2;
            //p2=goods;
            //while(p2->next) //����β���
            //  p2=p2->next;
            //p2->next=p; //����
        }
        else //���
            goods = p; //����
        //����һ����Ϣ
        infile >> p->num >> p->name >> p->person >> p->price >> p->amount;
    }
    cout << "\n��Ʒ�����Ѿ�װ��\n";
}
