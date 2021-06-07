#pragma once
#include<iostream>
#include<string>
using namespace std;
int G = 0;//定义全局变量//现有货物的总数
int S = 0;//staff员工总数
double T = 0;//总共的营业额
//创建第一个类（货物）
class goods
{
public:
	string id;//
	string name;//名字
	double price;//价格
	int num;//编号
}goods[10000];//定义数组
class staff//第二个类（职员）
{
public:
	string id;
	string name;
	double sale;//营业额
}staff[1000];
class manager
{
public:
	virtual void show()//虚函数
	{
		cout << "管理基类的show方法" << endl;
	}
};
class salemanager :public manager//派生的一个类
{
public:
	string salemenu;
	salemanager()
	{
		salemenu = "---销售管理---\n1.商品销售\n2.销售退款\n3.新建销售员信息4.销售统计\n0.返回主菜单\n请输入您的选择:";
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
				cout << "请输入销售的员工编号：";
				cin >> b;
				for (i = 1; i <= S; i++)
					if (b == staff[i].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "没有该编号的员工。" << endl;
					system("pause");
					break;
				}
				d = 1;
				cout << "请输入销售商品的编号:" << endl;
				cin >> a;
				for (j = 1; j <= G; j++)
					if (a == goods[j].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "没有该编号的商品。" << endl;
					system("pause");
					break;
				}
				cout << "请输入销售量：" << endl;
				cin >> num;
				if (num > goods[i].num)
					cout << "没有那么多库存。" << endl;
				else
				{
					staff[i].sale += num * goods[j].price;//营业额的计算
					goods[j].num -= num;
					T += num * goods[j].price;
				}
			}
			else if (n == 2)
			{
				int num, d = 1;
				string a, b;
				cout << "请输入退款的员工编号：";
				cin >> b;
				for (i = 1; i <= S; i++)
					if (b == staff[i].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "没有该编号的员工。" << endl;
					system("pause");
					break;
				}
				d = 1;
				cout << "请输入退款商品的编号:" << endl;
				cin >> a;
				for (j = 1; j <= G; j++)
					if (a == goods[j].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "没有该编号的商品。" << endl;
					system("pause");
					break;
				}
				cout << "请输入退还量：" << endl;
				cin >> num;
				staff[i].sale -= num * goods[j].price;
				goods[j].num += num;
				T -= num * goods[j].price;
			}
			else if (n == 3)
			{
				S++;
				cout << "请输入新员工编号：";
				cin >> staff[S].id;
				cout << "请输入新员工姓名：";
				cin >> staff[S].name;
				cout << "请输入新员工营业额：";
				cin >> staff[S].sale;
			}
			else if (n == 4)
			{
				int i;
				cout << "编号\t姓名\t销售额" << endl;
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
		savemenu = "---库存管理---\n1.查询库存\n0.返回主菜单\n请输入您的选择：";
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
				cout << "编号\t名称\t单价\t库存" << endl;
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
		buymenu = "---采购管理---\n1.买入原有商品\n2.买入新商品\n0.返回主菜单\n请输入您的选择：";
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
				cout << "请输入买入的货物编号：";
				cin >> a;
				for (i = 1; i <= G; i++)
					if (a == goods[i].id)
					{
						d = 0;
						break;
					}
				if (d)
				{
					cout << "没有该编号的货物。" << endl;
					system("pause");
					break;
				}
				cout << "请输入买入单价：";
				cin >> p;
				cout << "请输入买入数量：";
				cin >> num;
				goods[i].num += num;
				T -= num * p;
			}
			else if (n == 2)
			{
				G++;
				cout << "请输入新货物编号：";
				cin >> goods[G].id;
				cout << "请输入新货物名称：";
				cin >> goods[G].name;
				cout << "请输入新货物单价：";
				cin >> goods[G].price;
				cout << "请输入新货物数量：";
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
		moneymenu = "---财务管理---\n1.查询营业额\n0.返回主菜单\n请输入您的选择：";
	}
	void show()
	{
		int n;
		do
		{
			cout << moneymenu;
			cin >> n;
			if (n == 1)cout << "营业额为：" << T << endl;
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
	//向菜单类对象添加功能对象
	void addfun(manager* m)
	{
		m->show();
	}
};