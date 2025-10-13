#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char mode;
    cin >> mode;

    if (mode != 'h' && mode != 'v') {
        cout << "Neplatný mód vykreslenia" << endl;
        return 1;
    }

  
    int n, m;
    cin >> n >> m;

    
    vector<int> histogram(9, 0);
    int invalid = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= m && x <= m + 8)
            histogram[x - m]++; 
        else
            invalid++;
    }

    
    if (mode == 'h') {
       
        int width = to_string(m + 8).size();

        for (int i = 0; i < 9; i++) {
            cout << setw(width) << (m + i) << ": ";
            for (int j = 0; j < histogram[i]; j++)
                cout << "#";
            cout << "\n";
        }

        
        if (invalid > 0) {
            cout << "invalid : ";
            for (int i = 0; i < invalid; i++)
                cout << "#";
            cout << "\n";
        }
    }


    return 0;
}

