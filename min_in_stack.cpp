/*Вам требуется реализовать структуру данных, выполняющую следующие операции:
1. Добавить элемент x в конец структуры.
2. Удалить последний элемент из структуры.
3. Выдать минимальный элемент в структуре.*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define PB push_back
#define PoB pop_back
#define sort(a) sort(a.begin(), a.end())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, op, x;
    stack<ll>s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x;

            if (s.empty()) {
                s.push(x);
            }
            else {
                if (s.top() > x) {
                    s.push(x);
                }
                else {
                    s.push(s.top());
                }

            }
        }
        else if (op == 2) {
            s.pop();
        }
        else if (op == 3) {
            cout << s.top() << "\n";
        }
    }


    return 0;
}
