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
std::cout << "Range tests!!!!!" << std::endl;
std::vector<int> v1;
v1.push_back(1);
v1.push_back(2);
v1.push_back(3);
Span big = Span(14);
big.addRange(v1.begin(), v1.end());
big.addRange(v1.begin(), v1.end());
big.printArray();
//std::cout << "10 000!!!!!" << std::endl;
//Span big2 = Span(10000);
//big2.fillFull(v1.begin(), v1.end());
//big2.printBig();
return 0;
}