#include<iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x=0,int y=0):xpos(x),ypos(y){}
	void ShowPosition()const { cout << "[" << xpos << ", " << ypos << "]" << endl; }
	Point& operator++()	//++pos. ��������
	{
		xpos += 1;
		ypos += 1;
		return*this;	//�ڱ� �ڽ��� �ٲٱ� ������, ���� �Ŀ� �Լ��� ����ȴ�.
	}
	const Point operator++(int)	//pos++. int�� ���������� �����ϱ� ������ ��, �ƹ� �ǹ̵� ����.
	{
		const Point retobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return retobj;	//�Լ����� ���� ��, retobj�� ��ȯ�Ѵ�.
	}
	Point& operator--()
	{
		xpos -= 1;
		ypos -= 1;
		return*this;
	}
	const Point operator--(int)
	{
		const Point retobj(xpos, ypos);
		xpos -= 1;
		ypos -= 1;
		return retobj;
	}
};

int main()
{
	Point pos(3, 5);
	Point cpy;
	cpy = pos--;	//����. ���������̱� ������ cpy=pos�� ����ǰ� ���� pos++�� ����ȴ�.
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;	//����
	cpy.ShowPosition();
	pos.ShowPosition();
	return 0;
}