#include <iostream>
using namespace std;

int binary_Search(int a[], int l, int r, int x) {
   while (l <= r) {
      int m = l + (r - l) / 2;
      if (a[m] == x)

         return m;
      if (a[m] > x)
         r = m - 1;
      else
         l = m + 1;
   }
   return -1;
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = { 2, 4, 6, -8, 10 };
    int n = sizeof(a) / sizeof(a[0]);

    int x;
    cin >> x;

    int result = binary_Search(a, 0, n - 1, x);

    if (result == -1)
        cout << "false" << endl;
    else
        cout << "yes" << result << endl;

    return 0;
}
