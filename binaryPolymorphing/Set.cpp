#include <iostream>
#include <vector>
const char Union = 'U';
const char Intresection = '^';
 

class Set {
private:
	std::vector<int> data;
public:
	Set(const std::vector<int>& v) :data(v) {}

	void add(int elem) {
		for (size_t i = 0; i < data.size(); i++)
			if (data[i] == elem)
				return;

		data.push_back(elem);
	}
	int getSize() const {
		return data.size();
	}
	int operator[](int index) const {
		if (index < 0 || index >= data.size()) {
			throw "error";
		}
		return data[index];
	}
	void remove(int index) {
		if (index < 0 || index >= data.size()) {
			throw "error";
		}
		data.erase(data.begin() + index);
	}
};

class SetOperation {
	public:
	virtual SetOperation* clone() const = 0;
public:
	virtual Set evaluate() const = 0;
};

class Idenity : public SetOperation {
protected:
	virtual SetOperation* clone() const override {
		return new Idenity(*this);
	}

	Set myData;
public:

	Idenity(const std::vector<int> v) : myData(v) {}

	Set evaluate() const override {
		return myData;
	}
};

class Expression : SetOperation {
	SetOperation* left;
	char ch;
	SetOperation* right;

	public:
	virtual SetOperation* clone() const override {
		return new Expression(left->clone(), ch, right->clone());
	}

	Set evaluate() const override {
		Set leftSide = left->evaluate();
		Set rightSide = right->evaluate();
		switch (ch)
		{
		case 'U':
			for (size_t i = 0; i < rightSide.getSize(); i++){
				leftSide.add(rightSide[i]);
			}
			return leftSide;
		case '^': 
			for (size_t i = 0; i < rightSide.getSize(); i++){
			bool isInIntersection = false;
				for (size_t j = 0; j < leftSide.getSize(); j++){
					if (leftSide[j] == rightSide[i])
						isInIntersection = true;
				}
				if (!isInIntersection) {
					rightSide.remove(i);
				}
			}
			return rightSide;
		default:
			break;
		}
	}

public:
	Expression(SetOperation* left, char ch, SetOperation* right) : left(left), ch(ch), right(right){}
};

int main() {
	Expression e(new Idenity({ 1, 2, 3 }), '^', new Idenity({2,  3, 4 }));

	Set Union = e.evaluate();
	for (size_t i = 0; i < Union.getSize(); i++){
		std::cout << Union[i];
	}
}
