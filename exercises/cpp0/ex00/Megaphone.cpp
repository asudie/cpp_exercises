#include <iostream>
#include <cctype>

class Megaphone {
public:
		Megaphone(){};
		~Megaphone(){};

		void ChangeReg(int argc, char **argv){
			for(int i = 0; i < argc; i++)
			{
				for(int j = 0; argv[i][j]; j++)
				{
					argv[i][j] = std::toupper(argv[i][j]);
				}
			}
		}
		void Display(int argc, char **argv){
			if(argc == 1)
				std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			for(int i = 1; i < argc; i++)
				std::cout << argv[i];
			std::cout << std::endl;
		}
};

int main(int argc, char **argv)
{
	Megaphone m1;
	m1.ChangeReg(argc, argv);
	m1.Display(argc, argv);
	return 0;

}
