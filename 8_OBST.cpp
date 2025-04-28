#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void optimalBST(const vector<double>& p, int n) {
    vector<vector<double>> e(n+2, vector<double>(n+1, 0)); 
    vector<vector<double>> w(n+2, vector<double>(n+1, 0)); 
    vector<vector<int>> root(n+2, vector<int>(n+1, 0));    

    for (int i = 1; i <= n+1; ++i) {
        e[i][i-1] = 0;
        w[i][i-1] = 0;
    }

    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n-l+1; ++i) {
            int j = i + l - 1;
            e[i][j] = numeric_limits<double>::infinity();
            w[i][j] = w[i][j-1] + p[j-1];

            for (int r = i; r <= j; ++r) {
                double cost = e[i][r-1] + e[r+1][j] + w[i][j];
                if (cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    cout << "Minimum cost of the Optimal BST: " << e[1][n] << endl;
}

int main() {
    int n;
    cout << "Enter number of keys: ";
    cin >> n;

    vector<double> p(n);
    cout << "Enter search probabilities for the keys (space separated): ";
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    optimalBST(p, n);

    return 0;
}
