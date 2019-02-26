#include <iostream>
#include <iomanip>
using namespace std;

class Complex {
private:
	double real;
	double imag;

public:
	Complex(double real = 0.0, double imag = 0.0);
	double getReal() const;
	void setReal(double real);
	double getImag() const;
	void setImag(double imag);
	void setValue(double real, double imag);
	void print() const;
	bool isReal() const;
	bool isImaginary() const;

	Complex & addInto(const Complex &another);
    Complex & addInto(double real, double imag);
	Complex addReturnNew(const Complex &another) const;
    Complex addReturnNew(double real, double imag) const;
};

Complex::Complex(double real, double imag) : real(real), imag(imag) {}
double Complex::getReal() const {
	return real;
}
void Complex::setReal(double real) {
	this->real = real;
}
double Complex::getImag() const {
	return imag;
}
void Complex::setImag(double imag) {
	this->imag = imag;
}
void Complex::setValue(double real, double imag) {
	this->real = real;
	this->imag = imag;
}
void Complex::print() const {
	cout << '(' << real << ',' << imag << ')' << endl;
}
bool Complex::isReal() const {
	return (imag == 0);
}
bool Complex::isImaginary() const {
	return (imag != 0);
}
Complex &Complex::addInto(const Complex &another) {
	real += another.real;
	imag += another.imag;
	return *this;
}
Complex &Complex::addInto(double real, double imag) {
	this->real += real;
	this->imag += imag;
	return *this;
}
Complex Complex::addReturnNew(const Complex &another) const {
	return Complex(real + another.real, imag + another.imag);
}
Complex Complex::addReturnNew(double real, double imag) const {
	return Complex(this->real + real, this->imag + imag);
}

int main() {
	Complex c1, c2(4, 5);
	c1.print();
	c2.print();

	c1.setValue(6, 7);
	c1.print();

	c1.setReal(0);
	c1.setImag(8);
	c1.print();

	cout << boolalpha; // print true/false instead of 0/1
	cout << "Is real? " << c1.isReal() << endl;
	cout << "Is Imaginary? " << c1.isImaginary() << endl;

	c1.addInto(c2).addInto(1, 1).print();
	c1.print();

	c1.addReturnNew(c2).print();
	c1.print();
	c1.addReturnNew(1, 1).print();
	c1.print();

	return 0;
}
