using System;
/// <summary>
/// 다음 그림과 같이 지뢰가 있는 지역과 지뢰에 인접한 위, 아래, 좌, 우 대각선 칸을 모두 위험지역으로 분류합니다.
/// 지뢰는 2차원 배열 board에 1로 표시되어 있고 board에는 지뢰가 매설 된 지역 1과, 지뢰가 없는 지역 0만 존재합니다.
/// 지뢰가 매설된 지역의 지도 board가 매개변수로 주어질 때, 안전한 지역의 칸 수를 return하도록 solution 함수를 완성해주세요.
/// </summary>
internal class 안전지대
{
    public int solution(int[,] board)
    {
        int answer = 0;
        for (int i = 0; i < board.GetLength(0); i++) // 0차원
        {
            for(int j = 0; j < board.GetLength(1); j++) // 1치원
            {
                if (board[i, j] == 1)
                {
                    if (i - 1 >= 0 && j + 1 < board.GetLength(1))
                        if (board[i - 1, j + 1] == 0)
                            board[i - 1, j + 1] = 2;

                    if (j + 1 < board.GetLength(1))
                        if (board[i, j + 1] == 0)
                            board[i    , j + 1] = 2;

                    if (i + 1 < board.GetLength(0) && j + 1 < board.GetLength(1))
                        if (board[i + 1, j + 1] == 0)
                            board[i + 1, j + 1] = 2;

                    if (i - 1 >= 0)
                        if (board[i - 1, j] == 0)
                            board[i - 1, j    ] = 2;

                    if (i + 1 < board.GetLength(0))
                        if (board[i + 1, j] == 0)
                            board[i + 1, j    ] = 2;

                    if (i - 1 >= 0 && j - 1 >= 0)
                        if (board[i - 1, j - 1] == 0)
                            board[i - 1, j - 1] = 2;

                    if (j - 1 >= 0)
                        if (board[i, j - 1] == 0)
                            board[i    , j - 1] = 2;

                    if (i + 1 < board.GetLength(0) && j - 1 >= 0)
                        if(board[i + 1, j - 1] == 0)
                        board[i + 1, j - 1] = 2;
                }
            }
        }
        for (int i = 0; i < board.GetLength(0); i++)
        {
            for (int j = 0; j < board.GetLength(1); j++)
            {
                if (board[i, j] == 0)
                {
                    answer++;
                }
            }
        }
        return answer;
    }
}

