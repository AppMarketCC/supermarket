#pragma once
#include<iostream>
#include<string>
using namespace std;
int G = 0;//����ȫ�ֱ���//���л��������
int S = 0;//staffԱ������
double T = 0;//�ܹ���Ӫҵ��
//������һ���ࣨ���
class goods
{
public:
	string id;//
	string name;//����
	double price;//�۸�
	int num;//���
}goods[10000];//��������
class staff//�ڶ����ְࣨԱ��
{
public:
	string id;
	string name;
	double sale;//Ӫҵ��
}staff[1000];
class manager
{
public:
	virtual void show()//�麯��
	{
		cout << "��������show����" << endl;
	}
};
class salemanager :public manager//������һ����
{
public:
	string salemenu;
	salemanager()
	{
		salemenu = "---���۹���---\n1.��Ʒ����\n2.�����˿�\n3.�½�����Ա��Ϣ4.����ͳ��\n0.�������˵�\n����������ѡ��:";
	}
	void show()
	{
		int n, i, j;
		do
		{
			cout << salemenu;
			cin >> n;
			if (n == 1)
			{
				int num, d = 1;
				string a, b;
				cout << "���������۵�Ա����ţ�";
				cin >> b;
				for (i = 1; i <= S; i++)
					if (b == staff[i].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "û�иñ�ŵ�Ա����" << endl;
					system("pause");
					break;
				}
				d = 1;
				cout << "������������Ʒ�ı��:" << endl;
				cin >> a;
				for (j = 1; j <= G; j++)
					if (a == goods[j].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "û�иñ�ŵ���Ʒ��" << endl;
					system("pause");
					break;
				}
				cout << "��������������" << endl;
				cin >> num;
				if (num > goods[i].num)
					cout << "û����ô���档" << endl;
				else
				{
					staff[i].sale += num * goods[j].price;//Ӫҵ��ļ���
					goods[j].num -= num;
					T += num * goods[j].price;
				}
			}
			else if (n == 2)
			{
				int num, d = 1;
				string a, b;
				cout << "�������˿��Ա����ţ�";
				cin >> b;
				for (i = 1; i <= S; i++)
					if (b == staff[i].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "û�иñ�ŵ�Ա����" << endl;
					system("pause");
					break;
				}
				d = 1;
				cout << "�������˿���Ʒ�ı��:" << endl;
				cin >> a;
				for (j = 1; j <= G; j++)
					if (a == goods[j].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "û�иñ�ŵ���Ʒ��" << endl;
					system("pause");
					break;
				}
				cout << "�������˻�����" << endl;
				cin >> num;
				staff[i].sale -= num * goods[j].price;
				goods[j].num += num;
				T -= num * goods[j].price;
			}
			else if (n == 3)
			{
				S++;
				cout << "��������Ա����ţ�";
				cin >> staff[S].id;
				cout << "��������Ա��������";
				cin >> staff[S].name;
				cout << "��������Ա��Ӫҵ�";
				cin >> staff[S].sale;
			}
			else if (n == 4)
			{
				int i;
				cout << "���\t����\t���۶�" << endl;
				for (i = 1; i <= S; i++)
					cout << staff[i].id << "\t" << staff[i].name << "\t" << staff[i].sale << endl;
			}
		} while (n);
	}
};
class savemanager :public manager
{
public:
	string savemenu;
	savemanager()
	{
		savemenu = "---������---\n1.��ѯ���\n0.�������˵�\n����������ѡ��";
	}
	void show()
	{
		int n, i;
		do
		{
			cout << savemenu;
			cin >> n;
			if (n == 1)
			{
				cout << "���\t����\t����\t���" << endl;
				for (i = 1; i <= G; i++)
					cout << goods[i].id << "\t" << goods[i].name << "\t" << goods[i].price << "\t" << goods[i].num << endl;
			}
		} while (n);
	}
};
class buymanager :public manager
{
public:
	string buymenu;
	buymanager()
	{
		buymenu = "---�ɹ�����---\n1.����ԭ����Ʒ\n2.��������Ʒ\n0.�������˵�\n����������ѡ��";
	}
	void show()
	{
		int n, i;
		do
		{
			cout << buymenu;
			cin >> n;
			if (n == 1)
			{
				int num, d = 1;
				double p;
				string a;
				cout << "����������Ļ����ţ�";
				cin >> a;
				for (i = 1; i <= G; i++)
					if (a == goods[i].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "û�иñ�ŵĻ��" << endl;
					system("pause");
					break;
				}
				cout << "���������뵥�ۣ�";
				cin >> p;
				cout << "����������������";
				cin >> num;
				goods[i].num += num;
				T -= num * p;
			}
			else if (n == 2)
			{
				G++;
				cout << "�������»����ţ�";
				cin >> goods[G].id;
				cout << "�������»������ƣ�";
				cin >> goods[G].name;
				cout << "�������»��ﵥ�ۣ�";
				cin >> goods[G].price;
				cout << "�������»���������";
				cin >> goods[G].num;
				T -= goods[G].num * goods[G].price;
			}
		} while (n);
	}
};
class moneymanager :public manager
{
public:
	string moneymenu;
	moneymanager()
	{
		moneymenu = "---�������---\n1.��ѯӪҵ��\n0.�������˵�\n����������ѡ��";
	}
	void show()
	{
		int n;
		do
		{
			cout << moneymenu;
			cin >> n;
			if (n == 1)cout << "Ӫҵ��Ϊ��" << T << endl;
		} while (n);
	}
};
class form
{
public:
	int n;
	string strword;
	form(string str)
	{
		strword = str;
	}
	void input()
	{
		do
		{
			system("cls");
			cout << strword;
			cin >> n;

			if (n == 1)
			{
				salemanager m;
				addfun(&m);
			}
			else if (n == 2)
			{
				savemanager m;
				addfun(&m);
			}
			else if (n == 3)
			{
				buymanager m;
				addfun(&m);
			}
			else if (n == 4)
			{
				moneymanager m;
				addfun(&m);
			}
		} while (n);
	}
	//��˵��������ӹ��ܶ���
	void addfun(manager* m)
	{
		m->show();
	}
};