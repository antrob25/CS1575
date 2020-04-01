// Programmer: Anthony Robles           Section: cs1575 a

#include "abstractqueue.h"
#include "randomengine.h"
#include "realQueue.h"
#include <iostream>

using namespace std;

int main()
{
    realQueue customerQueue;
    randomEngine rEng;
    Oops oops("Customer cannot be found!");
    string mostName, leastName;
    int custNum, size ,mostEaten = 0, leastEaten;
    int eatenPopplers = 0;

    cin >> custNum;
    string * custName = new string[custNum];
    int * custNeed = new int[custNum];
    int * boxNum = new int[custNum];
    customer * customerArray = new customer[custNum];
    customer returning;

     for (int i = 0; i < custNum; i++)
    {
        cin >> custName[i] >> custNeed[i];
        customerArray[i].m_name = custName[i];
        customerArray[i].m_want = custNeed[i]; 
        customerQueue.enqueue(customerArray[i]);
    }

    delete []custNeed;
    delete []custName;
    delete []customerArray;

    size = customerQueue.size();

    for ( int i = 0; i < size; i++ ) 
    {
        try 
        {
            boxNum[i] = customerQueue.find(0).m_want;
            customerQueue.find(0).eatPopplers(boxNum[i], rEng);
            eatenPopplers += boxNum[i];
            leastEaten = customerQueue.front().m_eaten;
            cout << customerQueue.find(0) << endl; 

            if ( customerQueue.find(0).m_eaten > mostEaten )
            {
                mostEaten = customerQueue.find(0).m_eaten;
                mostName = customerQueue.find(0).m_name;
            }    

            if ( customerQueue.find(0).m_eaten < leastEaten )
            {
                leastEaten = customerQueue.find(0).m_eaten;
                leastName = customerQueue.find(0).m_name;
            }

            if  ( (customerQueue.find(0).m_want) != 0 )
            {
                returning = customerQueue.find(0);
                
                customerQueue.dequeue();
                
                customerQueue.enqueue(returning);
                
            }
            else
            {
                
                customerQueue.dequeue();
                
            }    
        }    
        catch (Oops)
        {
            cout << oops.getMsg() << endl;
        }
    }

    size = customerQueue.size();

    for ( int i = 0; i < size; i++ ) 
    {
        try
        {
            boxNum[i] = customerQueue.find(0).m_want;
            customerQueue.find(0).eatPopplers(boxNum[i], rEng);
            eatenPopplers += boxNum[i];
            cout << customerQueue.find(0) << endl;  

            if ( customerQueue.find(0).m_eaten > mostEaten )
            {
                mostEaten = customerQueue.find(0).m_eaten;
                mostName = customerQueue.find(0).m_name;
            }    

            if ( customerQueue.find(0).m_eaten < leastEaten )
            {
                leastEaten = customerQueue.find(0).m_eaten;
                leastName = customerQueue.find(0).m_name;
            }

            if  ( customerQueue.find(0).m_want != 0 )
            {
                returning = customerQueue.find(0);
                
                customerQueue.dequeue();
                
                customerQueue.enqueue(returning);
            }
            else
            {
                customerQueue.dequeue();
            }    
        }        
        catch (Oops)
        {
            cout << oops.getMsg() << endl;
        }
    }

    delete []boxNum;

    cout << "A total of " << eatenPopplers << " popplers were eaten." << endl;
    cout << mostName << " ate the most popplers: " << mostEaten << endl;
    cout << leastName << " ate the fewest popplers: " << leastEaten << endl << endl;

    return 0;
}
