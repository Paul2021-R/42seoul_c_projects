#include <vector> //중요
#include <iostream>

using namespace std;

int main(void)
{
	vector<int> Vect;
    
    for(int i = 0; i < 7; i++)
    {
    	Vect.push_back(i);//값을 뒤에 추가
    }
    
    for(int i = 0; i < (int)Vect.size(); i++)
    {
    	cout << Vect[i] << endl;//보통 배열처럼 값에 접근 가능.
    }
    
    Vect.clear();//벡터 해제
    
    return 0;
}
