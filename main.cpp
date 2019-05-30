#include <iostream>
#include <ctime>  
#include <cstdlib> 
#include <stdint.h>
#include <unistd.h>
#include "Product/StateManager.h"
#include <pthread.h>


bool running = true;

StateManager sm = StateManager();

void* callPolling(void*)
{
	sm.PollButtonState();
}

int main()
{
    
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
        
		pthread_t polling;
		
        switch(var)
        {

            case 1:
            {
				//pthread_create(&polling, NULL, callPolling, NULL);
				sm.pot->GetData();
				
				
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
