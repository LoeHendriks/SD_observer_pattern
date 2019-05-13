#include <iostream>
#include "Product/Stock.h"
#include "Product/MatrixBoardObserver.h"
#include "Product/NewsPaperObserver.h"
#include "Product/AppObserver.h"

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

bool running = true;

int main()
{
    Stock* stockMarket = new Stock();
    while(running)
    {
        uint32_t var = 0;

        std::cout << "|-------------------------------------|" << std::endl;
        std::cout << "|Stock observers                      |" << std::endl;
        std::cout << "|SD6 Loe Hendriks & Stefan Vogelaar   |" << std::endl;
        std::cout << "|Menu                                 |" << std::endl;
        std::cout << "|(1) Update observers                 |" << std::endl;
        std::cout << "|(2) Add observer                     |" << std::endl;
        std::cout << "|(3) Remove observers                 |" << std::endl;        
        std::cout << "|(4) End program                      |" << std::endl;
        std::cout << "|-------------------------------------|" << std::endl;

        


        std::cin >> var;
        
        std::vector<IObserver*> observers;

        switch(var)
        {

            case 1:
            {

                std::cout << "Update observers" << std::endl;
                srand(time(0));  
                int32_t r = (rand() % 10) + 1;
                stockMarket->Update(r);
                break;
            } 
            case 2:
            {
                std::cout << "Adding observer" << std::endl;
                std::cout << "Enter: " << std::endl;
                std::cout << "1 for matrixboard: " << std::endl;
                std::cout << "2 for newspaper: " << std::endl;
                std::cout << "3 for app: " << std::endl;
                int32_t choice;
                std::cin >> choice;
                switch(choice)
                {
                    case 1:
                    {
                        observers.push_back(new MatrixBoardObserver(stockMarket)); 
                        break;
                    }
                    case 2:
                    {
                        observers.push_back(new NewsPaperObserver(stockMarket)); 
                        break;
                    }
                    case 3:
                    {
                        observers.push_back(new AppObserver(stockMarket)); 
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 3:
            {
                std::cout << "Removing observers" << std::endl;
                uint32_t size = stockMarket->GetList().size();
                for(int32_t i = 0; i < size ;i++)
                {
                    stockMarket->Detach(stockMarket->GetList()[i]);
                }
                observers.clear();
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