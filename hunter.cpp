#include <iostream> 
#include <vector> 
#include <algorithm> 
 
using namespace std; 
 
bool isValid(int distance, const vector<int>& x, const vector<int>& y, int n, int m) { 
    int j = 0; 
    for (int i = 0; i < n; i++) { 
        while (j < m && y[j] < x[i] - distance) { 
            j++; 
        } 
        if (j >= m || y[j] > x[i] + distance) { 
            return false; 
        } 
        j++; 
    } 
    return true; 
} 
 
int main() { 
   int a;
   double b;
    int n, m; 
    cin >> n >> m; 
 
    vector<int> x(n), y(m); 
 
    for (int i = 0; i < n; i++) { 
        cin >> x[i]; 
    } 
 
    for (int i = 0; i < m; i++) { 
        cin >> y[i]; 
    } 
 
    sort(x.begin(), x.end()); 
    sort(y.begin(), y.end()); 
 
    int left = 0, right = 1000000000, result = -1; 
 
    while (left <= right) { 
        int mid = left + (right - left) / 2; 
        if (isValid(mid, x, y, n, m)) { 
            result = mid; 
            right = mid - 1; 
        } else { 
            left = mid + 1; 
        } 
    } 
 
    cout << result << endl; 
 
    return 0; 
}