
#include <iostream>

using namespace std;

int n, m,* proc;
bool* f;
void BankerAlgorithem(int used[4][3],int required[4][3],int *free) {
int count = 0;

proc = new int[n];

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == false) {

                bool flag = false;
                for (int j = 0; j < m; j++) {
                    if (required[i][j] > free[j]) {
                        flag = true;
                        break;
                    }
                }

                if (flag == false) {
                    proc[count++] = i;
                    cout << "P" << i + 1 << "=>\t";
                    for (int y = 0; y < m; y++) {
                        free[y] += used[i][y];
                        cout << free[y] << "\t";
                    }cout << endl;
                    f[i] = true;
                }
            }
        }
    }

}

void display() {

    int flag = true;
    for (int i = 0; i < n; i++) {
        if (f[i] == false) {
            flag = false;
        }
    }
    if (flag == false) {
        cout << "\tDead Lock\n" << endl;
    }
    if (flag == true)
    {
        cout << "All operations is Done" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << " P" << proc[i]+1 << " ->";
        }
        cout << " P" << proc[n - 1]+1 << endl;
    }

}

int main()
{
    //n = 3, m = 4;
    n = 4, m = 3;

    /*int used[3][4] = {{0, 1, 0, 0},
                       { 1, 0, 0, 2 },
                       { 0, 2, 1, 0 } };

    int required[3][4] = { { 1, 0, 0, 2 },
                       { 0, 1, 0, 1 },
                       { 0, 0, 1, 2 } };
       */
    int used[4][3] = { {1, 1, 5 },
                       { 1, 1, 0 },
                       { 0, 1, 0 },
                       { 1, 1, 0 } };

    int required[4][3] = { {2, 2, 2 },
                       { 7, 6, 5 },
                       { 3, 3, 4 },
                       { 4, 4, 4 } };

    //int available[4] = { 1, 3, 2, 4 };
    int available[3] = { 5, 6, 7};
    f = new bool[n];
    for (int k = 0; k < n; k++) {
        f[k] = false;
    }

    int* SumUsed, sum = 0;
    SumUsed = new int[m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += used[j][i];
        }
        SumUsed[i] = sum;
        sum = 0;
    }
    int* free;
    free = new int[m];
    for (int i = 0; i < m; i++) {
        free[i] = available[i] - SumUsed[i];
    }

    BankerAlgorithem(used, required, free);

    display();
}

