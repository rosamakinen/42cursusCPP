#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <random>


Base * generate(void)
{
    srand(time(0));
    int random = rand() % 3;
    switch (random)
    {
    case 0 :
        std::cout << "A randomly generated" << std::endl;
        return reinterpret_cast<Base*>(new A);
        break;
    case 1:
        std::cout << "B randomly generated" << std::endl;
        return reinterpret_cast<Base*>(new B);
        break;   
    case 2:
        std::cout << "C randomly generated" << std::endl;
        return reinterpret_cast<Base*>(new C);
        break;   
    default:
        return nullptr;
        break;
    }
}

void identify(Base& p)
{
	A a;
	B b;
	C c;
    try
    {
        a = dynamic_cast<A&>(p);
        std::cout << 'A' << std::endl;
    }
    catch(const std::exception& e)
	{

		std::cout << "is not a" << std::endl;
	}
	try
	{
		b = dynamic_cast<B&>(p);
		std::cout << 'B' << std::endl;
	}
	catch(const std::exception& e)
	{

		std::cout << "is not b" << std::endl;
	}
		
	try
	{
		c = dynamic_cast<C&>(p);
		std::cout << 'C' << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "is not c" << std::endl;
	}
}

void identify(Base* p)
{
    A* a;
    B* b;
    C* c;

    a = dynamic_cast<A*>(p);
    if(a)
    {
        std::cout << 'A' << std::endl;
        return;
    }
    b = dynamic_cast<B*>(p);
    if(b)
    {
        std::cout << 'B' << std::endl;
        return;
    }
    c = dynamic_cast<C*>(p);
    if(c)
    {
        std::cout << 'C' << std::endl;
        return;
    }
    std::cout << "Undefined" << std::endl;
}

int main()
{
	Base *a_base = generate();
	std::cout << std::endl;
	
	identify(a_base);
	std::cout << std::endl;

	identify(*a_base);
	
	delete a_base;
	return (0);
}