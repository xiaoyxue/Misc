#include "Interface.h"
#include "IProduct.h"
#include <iostream>



class Product1_1 : public IProduct1
{
public:
	void Process() override
	{
		std::cout << "Product1_1" << std::endl;
	}
};

class Product1_2 : public IProduct1
{
public:
	void Process() override
	{
		std::cout << "Product1_2" << std::endl;
	}
};

class Product2 : public IProduct2
{
public:
	void Process() override
	{
		std::cout << "Product2" << std::endl;
	}
};

class Product3 : public IProduct3
{
public:
	void Process() override
	{
		std::cout << "Product3" << std::endl;
	}
};

IMPLEMENTATION(IProduct1, Product1_1, "product1_1");
IMPLEMENTATION(IProduct1, Product1_2, "product1_2");
IMPLEMENTATION(IProduct2, Product2, "product2");
IMPLEMENTATION(IProduct3, Product3, "product3");
