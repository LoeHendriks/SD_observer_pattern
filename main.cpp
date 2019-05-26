#include <iostream>
#include <ctime>  
#include <cstdlib> 
#include <stdint.h>
#include <unistd.h>
#include "Product/StateManager.h"


bool running = true;

int main()
{
    StateManager sm = StateManager();
    while(running)
    {

        uint32_t var = 0;

        std::cout << "|-------------------------------------------------------------|" << std::endl;
        std::cout << "|Microwave                                                    |" << std::endl;
        std::cout << "|ES6 Loe Hendriks, Arthur van den Driest, Stefan Vogelaar     |" << std::endl;
        std::cout << "|Menu                                                         |" << std::endl;
        std::cout << "|(1) test														|" << std::endl;
        std::cout << "|(4) End program                                              |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;

        std::cin >> var;
        

        switch(var)
        {

            case 1:
            {
				//while(1)
				//{
					//usleep(200000);
					sm.bc->GetPressedButtons();
				//}
                break;
            } 
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                std::cout << "Ending program" << std::endl;
                running = false;
                break;
            }
            default:
                std::cout << "Error: Unknown Option" << std::endl;
                break;
        };
    }
    
}
