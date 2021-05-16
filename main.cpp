#include <iostream>
#include "population.cpp"

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, degree;
    vector<pair<long double, long double>> Points;
    freopen("input", "rt", stdin);
    freopen("output", "wt", stdout);
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        cout << "Case " << t + 1 << ": ";

        cin >> n >> degree;
        degree++;
        Points.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> Points[i].first >> Points[i].second;
        }
        population pop = population(Points, 10000, degree, 200);
        pop.process(Points);

    }

}