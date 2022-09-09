#include <vector> //중요
#include <iostream>

using namespace std;

int main(void)
{
	vector<int> Vect;
    vector<int>::iterator pos;//STL 객체 안에는 해당 컨테이너 접근을 위한 반복자가 있다.
    
    for(int i = 0; i < 7; i++)
    {
    	Vect.push_back(i);//값을 뒤에 추가
    }
    
    for(pos = Vect.begin(); pos != Vect.end(); pos++)
    {
    	cout << *pos << endl;//이터레이터를 사용하여 벤터 내 원소들에 접근
    }
    
    Vect.clear();//벡터 해제
    
    return 0;
}
