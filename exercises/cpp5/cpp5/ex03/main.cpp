#include "Intern.hpp"
#include "AForm.hpp"

int main(){
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	AForm* wrf;
	wrf = someRandomIntern.makeForm("wrong request", "Bender");
	delete wrf;
	return 0;
}