#include <bits/stdc++.h>
using namespace std;

void beam_op(vector<vector<int>> &mtx, int s, int n, vector<int> &vi, int w, vector<int> depth, int d)
{
    queue<int> open;
    open.push(s);
    vi[s] = 1;
    depth[s] = d;

    while (open.empty() != 1)
    {
        int a = open.front();
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            if (mtx[a][i] == 1 && vi[i] == 0 && depth[a] != 0)
            {
                open.push(i);
                depth[i] = depth[a] - 1;
                vi[i] = 1;
                x++;
            }
            if (x == w)
            {
                break;
            }
        }
        cout << open.front() << " ";
        open.pop();
    }
}

int main()
{
    int n, e, s, w;

    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    cout << "enter the number of edges" << endl;
    cin >> e;
    cout << "Enter the starting and ending nodes of the edges(starting from 0): " << endl;
    for (int i = 0; i < e; i++)
    {
        int j, k;
        cin >> j >> k;
        matrix[j][k] = 1;
        matrix[k][j] = 1;
    }

    cout << "Enter the starting node:" << endl;
    cin >> s;

    cout << "Enter the value of w: " << endl;
    cin >> w;
    for (int d = 1; d <= 3; d++)
    {
        vector<int> depth(n, INT_MAX);
        vector<int> visited(n, 0);
        cout << "For depth = " << d << endl;
        beam_op(matrix, s, n, visited, w, depth, d - 1);
        cout << endl;
    }

    return 0;
}