#include "IProduct.h"
#include <iostream>


class ProductA1 : public IProductA
{
public:
	void Process() override
	{
		std::cout << "ProductA1" << std::endl;
	}
};

GY_IMPLEMENTATION_DEF(IProductA, ProductA1, "ProductA1");


class ProductA2 : public IProductA
{
public:
	void Process() override
	{
		std::cout << "ProductA2" << std::endl;
	}
};

GY_IMPLEMENTATION_DEF(IProductA, ProductA2, "ProductA2");

class ProductB1 : public IProductB
{
public:
	void Process() override
	{
		std::cout << "ProductB1" << std::endl;
	}
};

GY_IMPLEMENTATION_DEF(IProductB, ProductB1, "Product1");


class ProductC : public IProductC
{
public:
	void Process() override
	{
		std::cout << "ProductC" << std::endl;
	}
};

GY_IMPLEMENTATION_DEF(IProductC, ProductC, "ProductC");