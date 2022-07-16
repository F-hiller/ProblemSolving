#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int board[101][101];

void moving(int first_board, int second_board, int &value, int &ans_value);
vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    int i, j, itemp;
    // set array
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= columns; j++)
        {
            board[i][j] = ((i - 1) * columns + j);
        }
    }

    // simulate query
    for (auto &&pos : queries)
    {
        pii first_pos = pii(pos[0], pos[1]);
        pii second_pos = pii(pos[2], pos[3]);
        int value = board[first_pos.first][first_pos.second];
        int ans_value = 987654321;
        for (i = first_pos.second + 1; i <= second_pos.second; i++)
        {
            moving(first_pos.first, i, value, ans_value);
        }
        for (i = first_pos.first + 1; i <= second_pos.first; i++)
        {
            moving(i, second_pos.second, value, ans_value);
        }
        for (i = second_pos.second - 1; i >= first_pos.second; i--)
        {
            moving(second_pos.first, i, value, ans_value);
        }
        for (i = second_pos.first - 1; i >= first_pos.first; i--)
        {
            moving(i, first_pos.second, value, ans_value);
        }
        answer.push_back(ans_value);
    }

    return answer;
}
void moving(int first_board, int second_board, int &value, int &ans_value)
{
    int itemp = board[first_board][second_board];
    board[first_board][second_board] = value;
    value = itemp;
    ans_value = min(ans_value, value);
}