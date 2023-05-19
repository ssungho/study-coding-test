#include <iostream>

using namespace std;

int main(void) 
{
    int N; // 입력받은 값
    int cnt = 0; // 반복 횟수
    int currNum = 0; // 현재 수
    const int endNum = 666;

    // N을 입력받는다
    cin >> N;

    // N번 반복한다. (cnt가 N이 될때 까지 반복)
    while (cnt < N)
    {
        // 현재 숫자 ++
        currNum++;
        // 대입해서 사용할 숫자 선언
        int num = currNum;
        
        // 666을 포함하는지 확인    
        while (num > 0) 
        {
            if (num % 1000 == endNum)
            {
                cnt++;
                break;
            }
            
            // 666이 포함되지 않는다면 루프 종료
            else
                num /= 10;  
        }
    }

    cout << currNum;
    return 0;
}