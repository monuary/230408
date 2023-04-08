#include<iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x=0,int y=0):xpos(x),ypos(y){}
	void ShowPosition()const { cout << "[" << xpos << ", " << ypos << "]" << endl; }
	Point& operator++()	//++pos. 전위연산
	{
		xpos += 1;
		ypos += 1;
		return*this;	//자기 자신을 바꾸기 때문에, 변경 후에 함수에 적용된다.
	}
	const Point operator++(int)	//pos++. int는 후위연산을 구분하기 위함일 뿐, 아무 의미도 없다.
	{
		const Point retobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return retobj;	//함수에서 쓰인 후, retobj를 반환한다.
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
	cpy = pos--;	//후위. 후위연산이기 때문에 cpy=pos가 적용되고 나서 pos++가 실행된다.
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;	//후위
	cpy.ShowPosition();
	pos.ShowPosition();
	return 0;
}