#include <iostream>

class Point {
private:
	int x;
	int y;

public:
	Point()
	{
		x = 0;
		y = 0;
		std::cout << "Construction!" << this << std::endl;
	}


	Point(int valueX, int valueY)
	{
		int x = valueX;
		int y = valueY;

		std::cout << "Construction!" << this << std::endl;
	}


	bool operator == (const Point& other) {

		return this->x == other.x && this->y == other.y;






	}


	bool operator != (const Point& other) {

		return this->x != other.x && this->y != other.y;






	}


};



class MyClass {
public:
	int* data;


	MyClass(int size)
	{
		this->Size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}


		std::cout << "This is construction!" << this << std::endl;
	}

	MyClass(const MyClass& other)
	{
		this->Size = other.Size;
		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
		std::cout << "This is copy construction!" << std::endl;
	}

	MyClass & operator = (const MyClass& other)
	{



		std::cout << "This is operation = " << this << std::endl;
		if (this->data != nullptr)
		{
			delete[] this->data;
		}

		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}

		return *this;
	}

	~MyClass()
	{
		std::cout << "This is distruction!" << this << std::endl;
		delete[] data;
	}
private:
	int Size;
};

void Foo(MyClass value)
{
	std::cout << "This is function FOO!" << std::endl;

}

MyClass Foo2()
{
	std::cout << "This is function FOO2!" << std::endl;

	MyClass temp(1);

	return temp;

}

int main()
{
	Point a(1, 4);
	Point b(1, 5);

	bool result = a == b;
	bool result1 = a != b;

	return 0;
}