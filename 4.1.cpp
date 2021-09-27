#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Complex         // класс "Комплексное число"
{
private:
    double re, im;      // действительная и мнимая части

public:
    // конструкторы 
    Complex() {};
    Complex(double r) {
        re = r;
        im = 0;
    }
    Complex(double r, double i) {
        re = r;
        im = i;
    }
    Complex(const Complex& c) {   // конструктор копирования
        re = c.re;
        im = c.im;
    }
    // деструктор
    ~Complex() {}
    // оператор присваивания
    Complex& operator = (Complex& c) {
        re = c.re;
        im = c.im;
        return (*this);
    }
    // оператор +=
    Complex& operator += (Complex& c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }
    // оператор сложения
    Complex operator + (const Complex& c) {
        return Complex(re + c.re, im + c.im);
    }
    // оператор вычитания
    Complex operator - (const Complex& c) {
        return Complex(re - c.re, im - c.im);
    }
    // оператор умножения
    Complex operator * (const Complex& c) {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }
    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend ostream& operator<< (ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);

};

// перегрузка оператора <<
ostream& operator<< (ostream& out, const Complex& c)
{
    if (c.im >= 0) { out << c.re << '+' << c.im << 'i'; }
    else out << c.re << c.im << 'i';
    return out;
}

// перегрузка оператора >>
istream& operator>> (istream& in, Complex& c)
{
    char q, z;
    in >> c.re >> z >> c.im >> q;
    if (z == '-' && c.im != 0)c.im *= -1;
    return in;
}
ifstream s("matr.txt");
void summ();
void vich();
void um_chislo();
void um_matr();
Complex t;
int main() {
    setlocale(LC_ALL, "Russian");
    if (!s) { cout << "Нет файла"; return 0; }
    int p;
    cout << "Выберете вариант:1-сложение;2-вычитание;3-умножение на число;4-умножение\n";
    cin >> p;
    switch (p) {
    case 1: summ(); break;
    case 2: vich(); break;
    case 3: um_chislo(); break;
    case 4: um_matr(); break;
    default: cout << "Не верно введен вариант";
    }
}
void summ() {
    int m1, n1, m2, n2;
    s >> m1 >> n1;
    s >> m2 >> n2;
    if (!m1 == m2 && !n1 == n2) {
        cout << "Невозможно суммировать матрицы из-за несовпадения размерностей";
        return;
    }

    Complex** matr1;
    matr1 = new Complex * [m1];
    for (int i = 0; i < m1; i++) {
        matr1[i] = new Complex[n2];
    }
    Complex** matr2;
    matr2 = new Complex * [m2];
    for (int i = 0; i < m2; i++) {
        matr2[i] = new Complex[n2];
    }
    Complex** matr_ans;
    matr_ans = new Complex * [m1];
    for (int i = 0; i < m1; i++) {
        matr_ans[i] = new Complex[n2];
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            s >> t;
            matr1[i][j] = t;
        }
    }
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            s >> t;
            matr2[i][j] = t;
        }
    }

    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            Complex t = (matr1[i][j] + matr2[i][j]);
            matr_ans[i][j] = t;
        }
    }
    cout << endl;
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            cout << matr_ans[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < m1; i++) {
        delete[] matr1[i];
    }
    delete[]matr1;
    for (int i = 0; i < m2; i++) {
        delete[] matr2[i];
    }
    delete[]matr2;
    for (int i = 0; i < m1; i++) {
        delete[] matr_ans[i];
    }
    delete[]matr_ans;
}
void vich() {
    int m1, n1, m2, n2;
    s >> m1 >> n1;
    s >> m2 >> n2;
    if (!m1 == m2 && !n1 == n2) {
        cout << "Невозможно вычесть матрицы из-за несовпадения размерностей";
        return;
    }
    Complex** matr1;
    matr1 = new Complex * [m1];
    for (int i = 0; i < m1; i++) {
        matr1[i] = new Complex[n2];
    }
    Complex** matr2;
    matr2 = new Complex * [m2];
    for (int i = 0; i < m2; i++) {
        matr2[i] = new Complex[n2];
    }
    Complex** matr_ans;
    matr_ans = new Complex * [m1];
    for (int i = 0; i < m1; i++) {
        matr_ans[i] = new Complex[n2];
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            s >> t;
            matr1[i][j] = t;
        }
    }
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            s >> t;
            matr2[i][j] = t;
        }
    }

    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            Complex t = (matr1[i][j] - matr2[i][j]);
            matr_ans[i][j] = t;
        }
    }
    cout << endl;
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            cout << matr_ans[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < m1; i++) {
        delete[] matr1[i];
    }
    delete[]matr1;
    for (int i = 0; i < m2; i++) {
        delete[] matr2[i];
    }
    delete[]matr2;
    for (int i = 0; i < m1; i++) {
        delete[] matr_ans[i];
    }
    delete[]matr_ans;

}
void um_chislo() {
    int m1, n1;
    Complex chislo = Complex(0, 0);
    s >> chislo;
    s >> m1 >> n1;
    Complex** matr1;
    matr1 = new Complex * [m1];
    for (int i = 0; i < m1; i++) {
        matr1[i] = new Complex[n1];
    }
    Complex** matr_ans;
    matr_ans = new Complex * [m1];
    for (int i = 0; i < m1; i++) {
        matr_ans[i] = new Complex[n1];
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            s >> t;
            matr1[i][j] = t;
        }
    }
    Complex t = Complex(0, 0);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            Complex t = ((matr1[i][j]) * chislo);
            (matr_ans[i][j]) = t;
        }
    }
    cout << endl;
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            cout << matr_ans[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < m1; i++) {
        delete[] matr1[i];
    }
    delete[]matr1;
    for (int i = 0; i < m1; i++) {
        delete[] matr_ans[i];
    }
    delete[]matr_ans;
}

void um_matr() {
    int m1, n1, m2, n2;
    s >> m1 >> n1;
    s >> m2 >> n2;
    if (!(n1 == m2)) {
        cout << "Невозможно умножить матрицы, т.к. число столбцов 1 матрицы не равно числу столбцов 2 матрицы";
        return;
    }
    Complex** matr1;
    matr1 = new Complex * [m1];
    for (int i = 0; i < m1; i++) {
        matr1[i] = new Complex[n1];
    }
    Complex** matr2;
    matr2 = new Complex * [m2];
    for (int i = 0; i < m2; i++) {
        matr2[i] = new Complex[n2];
    }
    Complex** matr_ans;
    matr_ans = new Complex * [m1];
    for (int i = 0; i < m1; i++) {
        matr_ans[i] = new Complex[n2];
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            s >> t;
            matr1[i][j] = t;
        }
    }
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            s >> t;
            matr2[i][j] = t;
        }
    }
    Complex t1 = Complex(0, 0);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            Complex t1 = Complex(0, 0);
            for (int k = 0; k < n1; k++) {
                Complex t = matr1[i][k] * matr2[k][j];
                t1 += t;
            }
            (matr_ans[i][j]) = t1;
        }
    }
    cout << endl;
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << matr_ans[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < m1; i++) {
        delete[] matr1[i];
    }
    delete[]matr1;
    for (int i = 0; i < m2; i++) {
        delete[] matr2[i];
    }
    delete[]matr2;
    for (int i = 0; i < m1; i++) {
        delete[] matr_ans[i];
    }
    delete[]matr_ans;
}