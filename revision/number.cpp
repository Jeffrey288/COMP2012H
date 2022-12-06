#include <iostream>
using namespace std;

class Number {
private:
	double value = 0;
public:
	Number() = default;

	// Number(int val) { value = val; }
	// Number(float val) { value = val; }
	template <typename T>
	Number(T val) : value(val) {}

	Number(Number& num) : value(num.value) {}

	Number(Number&& num) : value(num.value) {}

	Number& operator=(Number& other) {
		if (this != &other) {
			this->value = other.value;
		}
		return *this;
	}
	
	friend ostream& operator<<(ostream& os, const Number& num) {
		return (os << num.value);
	}

	// const Number& operator++() {
	// 	cout << "num++" << endl;
	// 	double temp = value;
	// 	value += 1;
	// 	return Number(temp);
	// }

	Number& operator++() {
		cout << "++num" << endl;
		value += 1;
		return (*this);
	}

	Number operator++(int) {
		cout << "num++" << endl;
		double temp = value;
		value += 1;
		return temp;
	}
	


};

int main() {
	Number num(3);
	Number num2(3.1);
	Number num3(num2);
	cout << num << " " << num2 << " " << num3 << endl;
	cout << num++ << " " << ++num2 << " " << num3 << endl;
	cout << num << " " << num2 << " " << num3 << endl;
	return 0; 
}