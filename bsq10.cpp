#include <bits/stdc++.h>
using namespace std;

void beam_op(vector<vector<int>> &mtx, int s, int n, vector<int> &vi, int w)
{
    queue<int> open;
    open.push(s);
    vi[s] = 1;
    while (open.empty() != 1)
    {
        int a = open.front();
        cout << open.front() + 1 << " ";
        open.pop();

        for (int i = 0; i < n; i++)
        {
            if (mtx[a][i] == 1 && vi[i] == 0)
            {
                if (open.size() < w)
                {
                    open.push(i);
                    vi[i] = 1;
                }
            }
            if (open.size() == w)
            {
                break;
            }
        }
    }
}

int main()
{
    int n, e, s, w;
    n = 10;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<int> visited(n, 0);

    matrix = {{0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
              {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
              {1, 1, 0, 0, 1, 0, 0, 1, 0, 0},
              {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
              {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
              {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, 
              {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
              {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
              {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
              {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}};

    cout << "Enter the starting node:" << endl;
    cin >> s;
    cout << "Enter the value of w: " << endl;
    cin >> w;

    beam_op(matrix, s, n, visited, w);

    return 0;
}