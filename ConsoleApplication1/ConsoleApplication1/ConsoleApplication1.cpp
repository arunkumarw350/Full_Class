#include<iostream>
using namespace std;


class Sample
{
	int _id;
	char* _name;
public:
	Sample():_id(0)
	{
		cout << "default constructor called" << endl;
		_name = new char;
		*_name = '\0';
	}

	Sample(int id, const char* name):_id(id)
	{
		cout << "argument constructor called" << endl;
		_name = new char[strlen(name) + 1];
		strcpy_s(_name, -1, name);		
	}

	Sample(const Sample& robj) :_id(robj._id)
	{
		cout << "copy called" << endl;
		_name = new char[strlen(robj._name) + 1];
		strcpy_s(_name, -1, robj._name);
	}

	Sample& operator =(const Sample& obj)
	{
		if (this != &obj)
		{
			cout << "copy assignment called" << endl;
			_id = obj._id;
			if (_name != nullptr)
			{
				delete[]_name;
				_name = nullptr;
			}
			_name = new char[strlen(obj._name) + 1];
			strcpy_s(_name, -1, obj._name);
		}
		return *this;
	}

	Sample(Sample&& robj) noexcept
	{
		cout << "move called" << endl;
		_id = robj._id;
		_name = robj._name;

		robj._id = 0;
		robj._name = nullptr;
	}

	Sample &operator=(Sample&& obj)noexcept
	{
		if (this != nullptr)
		{
			cout << "move assignment called" << endl;
			if (_name != nullptr)
			{
				delete[]_name;
				_name = nullptr;
			}
			_id = obj._id;
			_name = obj._name;

			obj._id = 0;
			obj._name = nullptr;
		}
		return*this;
	}

	void Display()
	{
		cout << "ID:" << _id<<" ";
		cout << "NAME:" << _name << endl;
	}

	~Sample()
	{
		if (_name != nullptr)
		{
			delete[]_name;
			_name = nullptr;
		}
	}
};

int main()
{
	Sample S1;
	S1.Display();

	Sample S2(100, "arun");
	S2.Display();

	Sample S3 = S2;
	S3.Display();

	S1 = S3;
	S1.Display();

	Sample S4(101, "kumar");
	Sample S5(move(S4));
	S5.Display();

	S3 = move(S5);
	S3.Display();

}