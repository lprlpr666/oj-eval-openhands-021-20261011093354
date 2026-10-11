#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Point {
    int x, y;
    
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    // Sort by x-coordinate
    sort(points.begin(), points.end());
    
    long long result = 0;
    
    // Optimized O(n^2) approach with early termination
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if points[i] can be bottom-left and points[j] can be top-right
            if (points[i].y < points[j].y) {
                // Check if rectangle is empty - no points inside or on boundary
                bool is_empty = true;
                for (int k = i + 1; k < j; k++) {
                    if (points[k].y > points[i].y && points[k].y < points[j].y) {
                        is_empty = false;
                        break;
                    }
                }
                if (is_empty) {
                    result++;
                }
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}