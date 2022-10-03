#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &mtx, int s, int n, vector<int> &vi)
{   queue<int> open;
    open.push(s);
    vi[s] = 1;
    while (open.empty() != 1)
    {
        int a = open.front();
        for (int i = 0; i < n; i++)
        {
            if (mtx[a][i] == 1 && vi[i] == 0)
            {
                open.push(i);
                vi[i] = 1;
            }
        }
        cout << open.front() << " ";
        open.pop();
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
    
    BFS(matrix, 0, n, visited);
    
    return 0;
}