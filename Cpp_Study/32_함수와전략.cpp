#include<iostream>
using namespace std;

void Sort(int* x, int n) 
{ 
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(x[i] > x[j])
                swap(x[i], x[j]);
        }
    }

}

int main() {
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 }
}