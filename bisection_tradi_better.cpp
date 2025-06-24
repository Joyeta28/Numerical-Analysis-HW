#include <iostream>
#include <cmath>
using namespace std;

double TOLERANCE = 0.0001;
double f(double x) {
    return x*x*x - x - 2;
}

void bisectionTraditional(double a, double b) {
    if (f(a) * f(b) >= 0) {
        return;
    }

    int iteration = 0;
    double c;

    while ((b - a) >= TOLERANCE) {
        c = (a + b) / 2;
        iteration++;

        if (f(c) == 0) break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Traditional Method:\n";
    cout << "Root = " << c << " in " <<iteration<< " iterations."<<endl;
}

bool betterRange(double &a, double &b) {
    double step = 0.1;
    for (double x = -100; x < 100; x += step) {
        if (f(x) * f(x + step) < 0) {
            a = x;
            b = x + step;
            return true;
        }
    }
    return false;
}

void bisectionBetter() {
    double a, b;

    if (!betterRange(a, b)) {
        cout << "No sign change found in range [-100, 100]."<<endl;
        return;
    }


    int iteration = 0;
    double c;

    while ((b - a) >= TOLERANCE) {
        c = (a + b) / 2;
        iteration++;

        if (f(c) == 0) break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Better Method:\n";
    cout << "Root = " << c << " in " << iteration << " iterations.\n";
}

int main() {
    bisectionTraditional(1, 2);

    bisectionBetter();

    return 0;
}
