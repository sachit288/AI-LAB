#include <bits/stdc++.h>

using namespace std;

void Deepening_DFS(vector<vector<int>> &mtx, int s, int n, vector<int> &vi, int d)
{

    cout << s << " ";
    vi[s] = 1;
    for (int i = 0; i < n; i++)
    {
        if (d == 0)
        {
            return;
        }

        else if (mtx[s][i] == 1 && vi[i] == 0)
        {

            Deepening_DFS(mtx, i, n, vi, d - 1);
        }
    }
};

int main()
{
    int n, e, d, ch;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    cout << "enter the number of edges" << endl;
    cin >> e;
    cout << "Enter the starting and ending nodes of the edges(starting form 0) " << endl;

    for (int i = 0; i < e; i++)
    {
        int j, k;
        cin >> j >> k;
        matrix[j][k] = 1;
        matrix[k][j] = 1;
    }
    for (d = 1; d <= 4; d++)
    {
        vector<int> visited(n, 0);
        cout << "For Depth = " << d << endl;
        Deepening_DFS(matrix, 0, n, visited, d - 1);
        cout << endl;
    }

    return 0;
}