
# include <cstdlib>
# include <malloc.h>
# include <iostream>
#include <string>
using namespace std;
int *p1 = (int *)malloc(300 * sizeof(int));
int *p = (int *)malloc(400* sizeof(int));
string bit(16, ' ');
void P1()
{

    for (int i = 0; i <= 60; i++) {
        p[i] = i;
        cout <<"p[" <<i << "]=" << p[i]<< endl;
    }
}
void P2()
{
    int k = 0;
    for (int i = 1; i <= 60; i++) {
        if (p[i]%2==0) {
            p1[k] = p[i];
            cout <<"p1["<< k << "]=" << p1[k] << endl;
            k++;

        }
    }
    free (p);
}
void P3() {
    char k[16];
    for (int l = 0; l <= 60; l++) {
        if (p1[l] >= 0) {
            int p2 = p1[l];
            for (int i = 0; i <= 16; i++) {
                bit[i] = (p2 % 2);
                p2 /= 2;
            }
            if ((bit[1] == '0') && (bit[2] == '0') && (bit[3] == '1') && (bit[4] == '1') && (bit[5] == '1') && (bit[6] == '1')) {
                cout <<"p1[" << l << "]=" << p1[l] << " true" << endl;
            }
                else cout <<"p1[" << l << "]=" << p1[l] << " false" << endl;
        }
    }
}
void P4() {
    char k[16];
    int p2 =0;
    int **dv = (int **)malloc(60 * 5);
    for (int l = 0; l <= 60; l++) {
        if (p1[l] >= 0) {

            if (p1[l] == 10000) p2 = 5;
            if (p1[l] < 10000) p2 = 4;
            if (p1[l] < 1000) p2 = 3;
            if (p1[l] < 100) p2 = 2;
            if (p1[l] < 10) p2 = 1;
            cout << "p1[" << l << "]=" <<p1[l]<< " " << p2 <<endl;
            dv[l] = (int*)malloc(size_t(60 * p2));
            int z = p1[l];
            for (int j = p2; j > 0; j--) {
                dv[l][j] = z%10;
                z = z - z % 10;
            }
        }


    }
    for (int l = 0; l <= 60; l++) {
        for (int j = 0; j < p2; j++) {
            dv[l][j] = dv[l-1][j-1] - 1;
            if (dv[l][j] = 0) dv[l][j] = 9;
        }
    }
    int sum = 0;
    for (int l = 0; l <= 60; l++) {
        for (int j = 0; j <p2; j++) {
            dv[l][j] = dv[l-1][j-1] + 1;
            if (dv[l][j] = 9) dv[l][j] = 0;
            sum=sum+ dv[l][j]*10*(j+1);
        }
        cout << "dv[" << l << "]=" << sum << endl;

    }
}



int main()
{
    P1();
    P2();
    P3();
    P4();
    free(p);
    free(p1);

    return 0;

}