#include <iostream>
#include <cmath>                // Тимофеев Алексей М8О-207Б-19
#include <cstring>
class Fraction {
private:
  const long int numerator;
  const long int denominator;
  friend std::istream &operator>>(std::istream &in, const Fraction &fraction);
 public:
  Fraction() : numerator(0), denominator(1) {}
  Fraction(const long int &number) : numerator(number), denominator(1) {}
  Fraction(const long int &numerator, const long int &denominator)
    : numerator(numerator), denominator(denominator) {}
  const long int &getNumerator() const { return numerator; }
  const long int &getDenominator() const { return denominator; }
  Fraction getReduced() const {
    long int gcd = getGCD(getNumerator(), getDenominator());
    long int numerator = getNumerator() / gcd;
    long int denominator = getDenominator() / gcd;
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
    return Fraction(numerator, denominator);
  }
  static long int getGCD(const long int &a, const long int &b) {
    long int x = std::abs(a);
    long int y = std::abs(b);
    while(1) {
      x = x % y;
      if (x == 0) {
        return y;
      }
      y = y % x;
      if (y == 0) {
        return x;
      }
    }
  }
 
};
 
Fraction operator+(const Fraction &a, const Fraction &b) {
  return Fraction(a.getNumerator() * b.getDenominator() +
    b.getNumerator() * a.getDenominator(),
    a.getDenominator() * b.getDenominator());
}
 
Fraction operator-(const Fraction &a, const Fraction &b) {
  return Fraction(a.getNumerator() * b.getDenominator() -
    b.getNumerator() * a.getDenominator(),
    a.getDenominator() * b.getDenominator());
}
 
Fraction operator-(const Fraction &f) {
  return Fraction(-f.getNumerator(), f.getDenominator());
}
 
Fraction operator*(const Fraction &a, const Fraction &b) {
  return Fraction(a.getNumerator() * b.getNumerator(),
    a.getDenominator() * b.getDenominator());
}
 
Fraction operator/(const Fraction &a, const Fraction &b) {
  return Fraction(a.getNumerator() * b.getDenominator(),
    a.getDenominator() * b.getNumerator());
}
 
std::ostream &operator<<(std::ostream &stream, const Fraction &fraction) {
  Fraction reduced = fraction.getReduced();
  return stream << reduced.getNumerator() << "/" << reduced.getDenominator();
}
 
long compare(const Fraction &a, const Fraction &b) {
  return a.getNumerator() * b.getDenominator() -
    b.getNumerator() * a.getDenominator();
}
 
bool operator==(const Fraction &a, const Fraction &b) {
  return compare(a, b) == 0;
}
 
bool operator!=(const Fraction &a, const Fraction &b) {
  return compare(a, b) != 0;
}
 
bool operator>(const Fraction &a, const Fraction &b) {
  return compare(a, b) > 0;
}
 
bool operator<(const Fraction &a, const Fraction &b) {
  return compare(a, b) < 0;
}
 
bool operator>=(const Fraction &a, const Fraction &b) {
  return compare(a, b) >= 0;
}
 
bool operator<=(const Fraction &a, const Fraction &b) {
  return compare(a, b) <= 0;
}
std::istream &operator>>(std::istream &in, const Fraction &fraction) {
  long int a,b;
  in >> a >> b;
  Fraction(a,b);
  return in;
}

int main() {
  long int num1, num2, den1, den2; 
  std::cout << "Введите первое рациональное число : \n";
	std::cin >> num1;
  std::cout << "--\n";
  std::cin >> den1;
	std::cout << "Введите второе рациональное число : \n";
  std::cin >> num2;
  std::cout << "--\n";
  std::cin >> den2;
  std::cout << "сложение \t" << (Fraction(num1,den1) + Fraction(num2,den2)) << std::endl;
  std::cout << "разность \t" << (Fraction(num1,den1) - Fraction(num2,den2)) << std::endl;
  std::cout << "умножение \t" << (Fraction(num1,den1) * Fraction(num2,den2)) << std::endl;
  std::cout << "деление \t" << (Fraction(num1,den1) / Fraction(num2,den2)) << std::endl;
  std::cout << "больше \t" << (Fraction(num1,den1) > Fraction(num2,den2)) << std::endl;
  std::cout << "меньше \t" << (Fraction(num1,den1) < Fraction(num2,den2)) << std::endl;
  std::cout << "равно \t" << (Fraction(num1,den1) == Fraction(num2,den2)) << std::endl;
  return 0;
}