#include<iostream>
using namespace std;

int objCount = 0;

class Rational
{
private:
	int num, den;//分子，分母
public:
	Rational(int num = 0,int den = 1)//初始分子分母 默认构造函数
	{
		cout << "newCount" << endl;
		objCount += 1;
	}
	
	Rational(Rational &a)
	:num(a.num),den(a.den)
	{
		cout << "copyCount" << endl;
	}

	~Rational()
	{
		cout << "Discount" << endl;
		objCount -= 1;
	}


	void Set(int x, int y)//设定分子分母
	{	
		num = x;
		den = y;
	}

	void print()//输出x/y
	{
		if (num == 0 || den == 0) {

		}
		else {
			cout << num << "/" << den << endl;
		}
		
	}

	double ToDec()//转换成小数
	{
		double dec = num / den;
		return dec;
	}

	void simple()//化简
	{
		int temp;
		int x = num, y = den;
		while (temp = x % y)//辗转相除法
		{
			x = y;
			y = temp;
		}
		den /= y;
		num /= y;
		if (den < 0) {
			den = -den;
			num = -num;
		}
	}

public:
	Rational plus(const Rational &r1, const Rational &r2)
	{
		Rational r;
		r.num = r1.num*r2.den + r2.num*r1.den;
		r.den = r1.den*r2.den;
		r.simple();
			cout<<"当前对象数："<<objCount<<endl;
		return r;
	}

	Rational sub(const Rational &r1, const Rational &r2)
	{
		Rational r;
		r.num = r1.num*r2.den - r2.num*r1.den;
		r.den = r1.den*r2.den;
		r.simple();
			cout<<"当前对象数："<<objCount<<endl;
		return r;
	}

	Rational mult(const Rational &r1, const Rational &r2)
	{
		Rational r;
		r.num = r1.num*r2.num;
		r.den = r1.den*r2.den;
		r.simple();
			cout<<"当前对象数："<<objCount<<endl;
		return r;
	}

	Rational div(const Rational &r1, const Rational &r2)
	{
		Rational r;
		if (r2.num == 0 || r2.den == 0)
		{
			cout << "分母不得为0" << endl;
		}
		else {
			r.num = r1.num*r2.den;
			r.den = r2.num*r1.den;
		}
		r.simple();
			cout<<"当前对象数："<<objCount<<endl;
		return r;
	}
};

int main()
{
	Rational r1;
	
	r1.Set(1,2);
	cout<<"当前对象数："<<objCount<<endl;
	
	Rational r2(r1);
	Rational r;
	
	cout<<"当前对象数："<<objCount<<endl;
	
	r = r.plus(r1, r2);
	r.print();

	cout<<"当前对象数："<<objCount<<endl;

	getchar();
	getchar();
	return 0;
}

