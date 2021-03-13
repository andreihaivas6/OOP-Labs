#pragma once
class Number
{
private:
	int val;
public:
	Number(int x) : val(x) {}
	bool operator>(const Number& x) {
		return this->val > x.val;
	}
	bool operator==(const Number& x) {
		return this->val == x.val;
	}
	Number& operator=(const Number& x) {
		this->val = x.val;
		return *this;
	}
};