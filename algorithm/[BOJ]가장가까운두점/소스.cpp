//baekjoon 2261
#include <iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define inf 100000000

int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	vector<vector<int>> v;
	vector<int> location;
	int count = 0;
	int x = 0, y = 0;
	int ans = inf;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> x >> y;
		location.push_back(x);
		location.push_back(y);
		v.push_back(location);
		location.clear();
	}

	for (long unsigned int i = 0; i < v.size(); i++)
	{
		for (long unsigned int j = 0; j < v.size(); j++)
		{
			if (i >= j) continue;
			ans = min(dist(v[i][0],v[i][1], v[j][0], v[j][1]), ans);
		}
	}
	cout << ans;
}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//struct Point {
//    int x, y;
//};
//
//int dist(Point& p, Point& q) {
//    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
//}
//
//struct Comp {
//    bool comp_in_x;
//    Comp(bool b) : comp_in_x(b) {}
//    bool operator()(Point& p, Point& q) {
//        return (this->comp_in_x ? p.x < q.x : p.y < q.y);
//    }
//};
//
//
//int closest_pair(vector<Point>::iterator it, int n) {
//    if (n == 2)
//        return dist(it[0], it[1]);
//    if (n == 3)
//        return min({ dist(it[0], it[1]), dist(it[1], it[2]), dist(it[2], it[0]) });
//
//    int line = (it[n / 2 - 1].x + it[n / 2].x) / 2;
//    int d = min(closest_pair(it, n / 2), closest_pair(it + n / 2, n - n / 2));
//
//    vector<Point> mid;
//    mid.reserve(n);
//
//    for (int i = 0; i < n; i++) {
//        int t = line - it[i].x;
//        if (t * t < d)
//            mid.push_back(it[i]);
//    }
//
//    sort(mid.begin(), mid.end(), Comp(false));
//
//    int mid_sz = mid.size();
//    for (int i = 0; i < mid_sz - 1; i++)
//        for (int j = i + 1; j < mid_sz && (mid[j].y - mid[i].y) * (mid[j].y - mid[i].y) < d; j++)
//            d = min(d, dist(mid[i], mid[j]));
//
//    return d;
//}
//
//
//int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    vector<Point> points(n);
//    for (auto it = points.begin(); it != points.end(); it++)
//        cin >> it->x >> it->y;
//
//    sort(points.begin(), points.end(), Comp(true));
//
//    cout << closest_pair(points.begin(), n);
//
//    return 0;
//}