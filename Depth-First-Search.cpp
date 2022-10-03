#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &mtx, int s, int n, vector<int> &vi)
{
    cout << s << " ";
    vi[s] = 1;
    for (int i = 0; i < n; i++)
    {
        if (mtx[s][i] == 1 && vi[i] == 0)
        {
            DFS(mtx, i, n, vi);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<int> visited(n, 0);
    cout << "Enter the matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << endl
         << "DFS is :" << endl;
    DFS(matrix, 3, n, visited);

    return 0;
}