#include <bits/stdc++.h>
using namespace std;

double mean(vector<double> &v)
{
    double ans = -1;
    for (int i = 0; i < v.size(); i++)
    {
        ans = ans + v[i];
    }
    return ans / (v.size());
}

void print(vector<double> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    int arr[4];
    cout << "Enter the  4 seed values: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    vector<double> g1, g2, g3, g4;
    vector<double> input;
    int size;
    g1.push_back(arr[0]);
    g2.push_back(arr[1]);
    g3.push_back(arr[2]);
    g4.push_back(arr[3]);
    cout << "Enter the size of the list: " << endl;

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        input.push_back((rand() % 100) + 1);
    }
    cout << "Random generated input: " << endl;
    print(input);
    vector<double> v1;
    vector<double> v2;
    vector<double> v3;
    vector<double> v4;

    for (int i = 0; i < 25; i++)
    { // number of epoch iterations
        v1.clear();
        v2.clear();
        v3.clear();
        v4.clear();
        v1.push_back(g1[i]);
        v2.push_back(g2[i]);
        v3.push_back(g3[i]);
        v4.push_back(g4[i]);
        for (int i = 0; i < size; i++)
        {
            double a, b, c, d, flag;
            a = abs(v1[0] - input[i]);
            b = abs(v2[0] - input[i]);
            c = abs(v3[0] - input[i]);
            d = abs(v4[0] - input[i]);
            flag = min(min(min(a, b), c), d);
            if (flag == a)
            {
                v1.push_back(input[i]);
                v1[0] = mean(v1);
            }
            if (flag == b)
            {
                v2.push_back(input[i]);
                v2[0] = mean(v2);
            }
            if (flag == c)
            {
                v3.push_back(input[i]);
                v3[0] = mean(v3);
            }
            if (flag == d)
            {
                v4.push_back(input[i]);
                v4[0] = mean(v4);
            }
        }
        g1.push_back(v1[0]);
        g2.push_back(v2[0]);
        g3.push_back(v3[0]);
        g4.push_back(v4[0]);

        if ((g1[i + 1] == g1[i]) && (g2[i + 1] == g2[i]) && (g3[i + 1] == g3[i]) && (g4[i + 1] == g4[i]))
        {
            break;
        }
    }
    cout << "G1: " << endl;
    print(g1);
    cout << "G2: " << endl;
    print(g2);
    cout << "G3: " << endl;
    print(g3);
    cout << "G4: " << endl;
    print(g4);
    cout << "V1: " << endl;
    print(v1);
    cout << "V2: " << endl;
    print(v2);
    cout << "V3: " << endl;
    print(v3);
    cout << "V4: " << endl;
    print(v4);

    return 0;
}