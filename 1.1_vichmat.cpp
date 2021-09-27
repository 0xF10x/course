#include <iostream>
#include <cmath>
using namespace std;

double s_z = 0; //сумма точных значений
double s_p = 0; //сумма погрешностей

void pog_sum(double* ar1, double* ar2, int* n) {
    for (int i = 0; i < *n; i++) {
        s_z += abs(ar1[i]);
        s_p += abs(ar1[i] - ar2[i]);
        }
}
double pog_mult(double* ar1, double* ar2, int* n) {
    double mult = 0;
    for (int i = 0; i < *n; i++) {
        if (ar2[i] !=0)
        mult += abs((ar1[i] - ar2[i])/ar2[i]);
    }
    return(mult*100);
}

int main() {
    system("color F0");
    int n;
    double sum, mult;
    double* ar1;
    double* ar2;
    setlocale(LC_ALL, "Russian");
    cout << "Введите кол-во значений: ";
    cin >> n;
    ar1 = new double [n];
    ar2 = new double [n];
   
        for (int i = 0; i < n; i++) {
            cout << "Введите точное значение: ";
            cin >> ar1[i];

            cout << "Введите приближенное значение: ";
            cin >> ar2[i];
        }
        
    
    pog_sum(ar1, ar2, &n);
    cout << "Абсолютная погрешность сложения(вычитания) " << s_p << "\n";
    cout << "Относительная погрешность сложения(вычитания) " << (s_p/s_z)*100 << "%\n";
    cout << "Относительная погрешность произведения " << pog_mult(ar1, ar2, &n) << "%\n";
    cout << "Относительная погрешность частного " << pog_mult(ar1, ar2, &n) << "%\n";
}