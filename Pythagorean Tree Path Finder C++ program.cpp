#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int isL(long long &x, long long &y, std::string &p) {
    long long a = x - y;
    long long b = 3 * x - 4 * y;

    if (a < b && a > (b / 2) && a > 0 && b > 0) {
        y = a;
        x = b;
        p += " L";
        return 1;
    }
    return 0;
}

int isM(long long &x, long long &y, std::string &p) {
    long long a = x - y;
    long long b = 2 * y - x;

    if (a < b && a > (b / 2) && a > 0 && b > 0) {
        y = a;
        x = b;
        p += " M";
        return 1;
    }
    return 0;
}

int isR(long long &x, long long &y, std::string &p) {
    long long a = 3 * y - 2 * x;
    long long b = 2 * y - x;

    if (a < b && a > (b / 2) && a > 0 && b > 0) {
        y = a;
        x = b;
        p += " R";
        return 1;
    }
    return 0;
}

int main() {
    long long x, y, a, b, c;
    string p = "";
    cout << "Enter the odd leg, even leg, and hypotenuse values: ";
    cin >> a >> b >> c;
    x = gcd(a + c, b);
    y = gcd(a, b + c);
    while (x != 4 || y != 3) {
        if (isL(x, y, p)) {
            continue;
        } else if (isM(x, y, p)) {
            continue;
        } else if (isR(x, y, p)) {
            continue;
        }

        break;
    }

    reverse(p.begin(), p.end());

    cout << "The path from 3-4-5 triple to the Pythagorean triple specified is " << p << endl;

    return 0;
}
