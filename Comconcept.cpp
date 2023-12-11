#include <iostream>
#include <string>

using namespace std;

template <typename T> concept ComplexConcept = !has_virtual_destructor<T>::value &&
	requires(T v)
{
	{v.hash()}->convertible_to<long>;
	{v.toString()}->same_as<string>;
};

class htos
{
public:
	htos(int _a, string _str): a(_a), str(_str)
	{}
	int hash() const
	{
		return a;
	}
	string toString()
	{
		return str;
	}
	~htos()
	{}
private:
	int a;
	string str;
};

void static prv(ComplexConcept auto& v)
{
	cout << v.hash() << endl;
}

int main()
{
	htos h(5, "s");
	prv(h);
	return 0;
}