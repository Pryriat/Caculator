#include<iostream>
#include<vector>
#include<fstream>
#include"head.h"
#include<stdio.h>
#include<string>
#ifndef csl
#define csl

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::string;
inline void pow(num& x, num& y)
{
	double time = y.nums();
	double temp = x.nums();
	if (time > 0)
		for (int z = 1; z < (int)time; z++)
			x * temp;
	else if (time == 0)
		x = time + 1.0;
	else if (time < 0)
	{
		for (int z = 1; z < -(int)time; z++)
			x*temp;
		temp = 1 / x.nums();
		x = temp;
	}
}
void analyze(string &a)
{
	int n = 0, num = 0, sign = 0,left_bracket=0,right_bracket=0;
	while (a[n] != '\0')
	{
		if (a[n] >= '0'&&a[n] <= '9')
		{
            if ((a[n + 1] >= '0'&&a[n+1] <= '9')||a[n+1]=='.')
			{
				n++;
				continue;
			}
			num++;
			n++;
		}
        else if (a[n] == '+' || a[n] == '-' || a[n] == '*' || a[n] == '/' || a[n] == '='||a[n] == '^')
		{
            if (a[n + 1] == '^'|| a[n + 1] == '+'|| a[n + 1] == '-'|| a[n + 1] == '*'|| a[n + 1] == '/'||a[n+1]=='=')
			{
                throw erro_info(7,a[n-1],a[n],a[n+1]);
			}
			sign++;
			n++;
		}
        else if (a[n] == '(')
		{
			if (a[n + 1] == '-')
				sign--;
			left_bracket++;
			n++;
		}
        else if (a[n] == ')')
		{
			right_bracket++;
			n++;
		}
        else if (a[n] == '.')
		{
			n++;
		}
        else
		{
            throw erro_info(8,a[n]);
		}
	}
    if (num - sign != 0)
        throw erro_info(1);
    if (a[n - 1] != '=')
        throw erro_info(2);
    if (left_bracket != right_bracket)
        throw erro_info(3,' ',' ',' ',left_bracket,right_bracket);
}
vector<num> numbers(string &a)
{
	vector<num> equ;
	double tempdata,l_temp=0,g=1;
	int n = 0, t = 0,dots=0;
	while (a[n] != '\0')
	{
		while (a[n] >= '0'&&a[n] <= '9')
		{
			if (t == 0 && a[n] != 0)
				tempdata = a[n] - '0';
			else
			{
				tempdata *= 10;
				if (g == -1)
					tempdata  -= a[n] - '0';
				else
					tempdata  += a[n] - '0';
			}
			if(n>=2)
				if (a[n - 1] == '-'&&a[n - 2] == '(')
				{
					g = -1;
					tempdata *= -1;
					a.erase(a.begin() + n - 2);
					a.erase(a.begin() + n - 2);
					n -= 2;
					for (int i = n;; i++)
						if (a[i] == ')')
						{
							a.erase(a.begin() + i);
							break;
						}
				}
			t++;
			n++;
		}
		if (a[n] == '.')
		{
			dots++;
			g /= 10;
			n++;
			while (a[n] >= '0'&&a[n] <= '9')
			{
				l_temp += (a[n] - '0') * g;
				g /= 10;
				n++;
			}
			if (a[n] == '.')
			{
                throw erro_info(4,a[n-2],a[n-1],a[n]);
			}
		}
		if (a[n] == '+' || (a[n] == '-'&&a[n-1]!='(') || a[n] == '*' || a[n] == '/' || a[n] == '='||a[n] == '^')//����������ֹͣ��ȡ
		{
			equ.push_back(tempdata+l_temp);
			tempdata = 0;
			l_temp = 0;
			t = 0;
			g = 1;
			n++;
		}
		else
			n++;
	}
	return equ;
}
vector<char> signs(string a)
{
	vector<char> signs;
	int n = 0;
	while (a[n] != '\0')
	{
        if ((a[n] < '0' || a[n] > '9')&&a[n]!='='&&a[n]!='.')
		{
			signs.push_back(a[n]);
		}
		n++;
	}
	return signs;
}
brancket checksign(vector<char>a)
{
	vector<int> temp_data;
	int times = 0;
	int position = 0;
	for (position; position < a.size(); position++)
	{
        if (a[position] == '(')
		{
			times++;
			temp_data.push_back(position);
		}
	}
	brancket temp(temp_data, times);
	return temp;
}
vector<num> coustom_caculate(vector<num>numbers, vector<char>signs, brancket checksign)
{
    if (numbers[0].erro() == 'g')
		return numbers;
    else if (numbers.size() == 0)
	{
        throw erro_info(5);
	}
    for (int time = checksign.times; time > 0; time--)
	{
		int right_brancket = 0;
		int position = checksign.position[time - 1];
		int temp_int = position;
		for (int i = 0; i < position; i++)
			if (signs[i] == ')')
				right_brancket++;
		for (position; signs[position] != ')'; position++)
		{
			if (signs[position] == '^')
			{
					pow(numbers[position - time - right_brancket], numbers[position - time - right_brancket + 1]);
					int temp = position - time - right_brancket;
					numbers.erase(numbers.begin() + temp + 1);
					signs.erase(signs.begin() + position);
					position--;
					temp = 0;
			}
		}
		position = temp_int;
        for (position; signs[position] != ')'; position++)
		{
			if (signs[position] == '*')
			{
				numbers[position - time - right_brancket] * numbers[position - time - right_brancket + 1];
				int temp =  position - time - right_brancket;
				numbers.erase(numbers.begin() + temp + 1);
				signs.erase(signs.begin() + position);
				position--;
				temp = 0;
			}
			else if (signs[position] == '/')
			{
                if (numbers[position - time + 1 - right_brancket].nums() == 0)
				{
                    throw erro_info(6,signs[position],' ',' ',numbers[position - time - right_brancket].nums(),\
                           numbers[position - time + 1 - right_brancket].nums());
				}
				numbers[position - time + -right_brancket] / numbers[position - time - right_brancket + 1];
				int temp = position - time - right_brancket;
				numbers.erase(numbers.begin() + temp + 1 );
				signs.erase(signs.begin() + position);
				position--;
				temp = 0;
			}
		}
		position = temp_int;
		for (position; signs[position] != ')'; position++)
		{
			if (signs[position] == '+')
			{
				numbers[position - time - right_brancket] + numbers[position - time - right_brancket + 1];
				int temp = position - time - right_brancket;
				numbers.erase(numbers.begin() + temp + 1 );
				signs.erase(signs.begin() + position);
				position--;
				temp = 0;
			}
			else if (signs[position] == '-')
			{
				numbers[position - time - right_brancket] - numbers[position - time - right_brancket + 1];
				int temp = position - time - right_brancket;
				numbers.erase(numbers.begin() + temp + 1 );
				signs.erase(signs.begin() + position);
				position--;
				temp = 0;
			}
		}
		signs.erase(signs.begin() + position);
		signs.erase(signs.begin() + temp_int);
	}
    int position = 0;
	for (position = 0; position < signs.size(); position++)
	{
		if (signs[position] == '^')
		{
			pow(numbers[position], numbers[position + 1]);
			numbers.erase(numbers.begin() + position + 1);
			signs.erase(signs.begin() + position);
			position--;
		}
	}
	for (position = 0; position < signs.size(); position++)
	{
		if (signs[position] == '*')
		{
			numbers[position] * numbers[position + 1];
			numbers.erase(numbers.begin() + position + 1);
			signs.erase(signs.begin() + position);
			position--;
		}
		else if (signs[position] == '/')
		{
			if (numbers[position + 1].nums() == 0)
			{
                throw erro_info(6,signs[position],' ',' ',numbers[position].nums(),numbers[position + 1].nums());
			}
			numbers[position] / numbers[position + 1];
			numbers.erase(numbers.begin() + position + 1);
			signs.erase(signs.begin() + position);
			position--;
		}
	}
	for (position = 0; position < signs.size(); position++)
	{
		if (signs[position] == '-')
		{
			numbers[position] - numbers[position + 1];
			numbers.erase(numbers.begin() + position + 1);
			signs.erase(signs.begin() + position);
			position--;
		}
		else if (signs[position] == '+')
		{
			numbers[position] + numbers[position + 1];
			numbers.erase(numbers.begin() + position + 1);
			signs.erase(signs.begin() + position);
			position--;
		}
	}
	return numbers;
}
#endif
