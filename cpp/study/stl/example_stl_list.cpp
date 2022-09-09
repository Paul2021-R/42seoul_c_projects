#include <list>
#include <iostream>

using namespace std;

int main(void)
{
	int nNum;
	list<int> lis;
	list<int>::iterator pos;
  
	for (int i = 0; i < 10; i++)
	{
		lis.push_back(i); // 값을 뒤에 추가
	}
	cout << "현재 배열 값" << endl;
	for (pos = lis.begin(); pos != lis.end(); pos++)
	{
		cout << *pos << endl;
	}
	cout << "0 ~ 9 사이에 삭제할 값을 선택하시오." << endl;
	cin >> nNum;
	for (pos = lis.begin(); pos != lis.end(); pos++)
	{
		if (*pos == nNum)
		{
			lis.erase(pos); // 현 반복자 위치의 노드 삭제
			break ;
		}
	}
	cout << "삭제 후 배열 값" << endl;
	for (pos = lis.begin(); pos != lis.end(); pos++)
	{
		cout << *pos << endl;
	}
	lis.clear();
	return (0);
}
