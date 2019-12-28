#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Дано число N. Определите, сколькими способами можно расставить на доске N×N N ферзей, не бьющих друг друга.

bool check(vector<int> &x, vector<int> &y, int n){
    int flag = 0;
    for (int i = 0; i < x.size(); i++){
        for (int j = i+1 ; j < x.size(); j++) {
            if ( (x[i] == x[j]) || (y[i] == y [j]) || (abs(x[i]-x[j]) == abs(y[i] - y[j])) ){
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0) return true;
    else return false;
}

void ferz (int **arr, vector<int> &x, vector<int> &y, int coll, int n, long long int *numb){ // coll - номер столбца, n - размер массива, numb - количество способов
    if (n == 0 || n == 1) *numb = 1;
    else {
        for (int i = 0; i < n; i++){ // идем сверху вниз по НЕ ПОСЛЕДНЕМУ столбцу
            if (arr[i][coll] == 0) {
                x.push_back(i);
                y.push_back(coll);
                if (coll == 0) {
                    ferz(arr, x, y, coll+1, n, numb);
                }
                else if (coll != n-1) {
                    if (check(x, y, n)) {
                        ferz(arr, x, y, coll+1, n, numb);
                    }
                }
                else if (coll == n-1) {
                    if (check(x, y, n)) {
                        *numb = *numb + 1;
                    }
                }
                x.pop_back();
                y.pop_back();
            }
        }
    }
}
    
int main(int argc, const char * argv[]) {
    int n;
    long long int numb = 0;
    cin >> n;
    int **arr;
    vector<int> x;
    vector<int> y;
    arr = new int *[n];
    for(int i = 0; i <n; i++){
        arr[i] = new int[n];
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }
    ferz(arr, x, y, 0, n, &numb);
    cout << numb;
}

//oeis.org/A000170/list
