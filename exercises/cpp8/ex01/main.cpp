#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
sp.printArray();
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
std::cout << "HERE!!!!!" << std::endl;
Span copy_c = Span(sp);
Span copy_o = Span(1);
copy_o.addNumber(123);
try{
    std::cout << copy_o.shortestSpan() << std::endl;
} catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
}
try{
    std::cout << copy_o.longestSpan() << std::endl;
} catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
}
copy_o = sp;

return 0;
}