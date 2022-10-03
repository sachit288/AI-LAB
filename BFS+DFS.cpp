// code by ue203095
// Sachit Sharma
// CSE section-2

#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &mtx, int s, int n, vector<int> &vi)
{
    queue<int> open;
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
    int n, e, s, ch;
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
    cout << "Enter the starting node: " << endl;
    cin >> s;
    cout << "For DFS enter 0 ,for BFS enter 1" << endl;
    cin >> ch;
    if (ch == 0)
    {
        cout << "The DFS is:" << endl;
        DFS(matrix, s, n, visited);
    }
    else if (ch == 1)
    {
        cout << "This is BFS: " << endl;
        BFS(matrix, s, n, visited);
    }

    return 0;
}