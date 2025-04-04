#include "Span.hpp"

int	main(void)
{
	try
	{
		Span span = Span(100000);
		span.addNumber(1);
		span.addNumber(15);
		span.addNumber(50);
		span.addNumber(4);
		std::cout << span[0] << std::endl;
		std::cout << span[1] << std::endl;
		std::cout << span[2] << std::endl;
		std::cout << span[3] << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		span.fillNum(10000);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		span.fillNum(80000);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}