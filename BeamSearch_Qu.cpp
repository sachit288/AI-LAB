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
    cout << "Enter the number of nodes: " << endl;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<int> visited(n, 0);
    cout << "enter the number of edges" << endl;
    cin >> e;
    cout << "Enter the starting and ending nodes of the edges: " << endl;
    for (int i = 0; i < e; i++)
    {
        int j, k;
        cin >> j >> k;
        matrix[j][k] = 1;
        matrix[k][j] = 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n ;j++)
    //     {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;

    // }
    // matrix = {{0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    //      {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    //      {1, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    //      {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
    //      {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
    //      {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    //      {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
    //      {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    //      {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    //      {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}};

    cout << "Enter the starting node:" << endl;
    cin >> s;
    cout << "Enter the value of w: " << endl;
    cin >> w;

    beam_op(matrix, s, n, visited, w);

    return 0;
}