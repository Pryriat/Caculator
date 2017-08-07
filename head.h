#include<iostream>
#include<string>
#include<vector>
#ifndef HEAD_H
#define HEAD_H
using namespace std;
class num
{
private:
	double data;
	char g;
	friend void operator*(double a, num x);
public:
	void operator+ (const num &a)
	{
		data += a.data;
	}
	void operator=(double a)
	{
		data = a;
	}
	void operator-(const num &a)
	{
		data -= a.data;
	}
	void operator*(const num &a)
	{
		data *= a.data;
	}
	void operator*(double a)
	{
		data *= a;
	}
	void operator/(const num &a)
	{
		data /= a.data;
	}
	void print()
	{
		cout << data << endl;
	}
	num(double a)
	{
		data = a;
	}
	num()
	{
		cout << "error!";
	}
	void err()
	{
		g = '!';
	}
	char erro()
	{
		return g;
	}
	double nums()
	{
		return data;
	}
};
void operator*(double a, num x)
{
	x.data *= a;
}
class brancket
{
	public:
		vector<int> position;
		int times;
		brancket(vector<int> a, int n)
		{
			this->position = a;
			this->times = n;
		}
		brancket()
		{
			this->times = 0;
			vector<int>a;
			this->position = a;
		}
};
class erro_info
{
public:
    int err_num;
    char position1;
    char position2;
    char position3;
    int right_num;
    int left_num;
    erro_info(int a = 0 , char b = ' ', char c = ' ',char d = ' ',int e = 0,int f = 0): err_num(a), position1(b),\
        position2(c), position3(d),left_num(e),right_num(f) {}
};
#endif
