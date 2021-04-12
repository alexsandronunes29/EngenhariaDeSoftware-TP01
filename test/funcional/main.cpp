#include "functionaltests.hpp"
#include  <iostream>


using namespace std;

int main(){

    cout<<"Teste functional em andamento..."<<endl;

     functionalTest_exponential();
    
     functionalTest_Logistic();
  
     functionalTest_complete();

    cout<<"Teste functional finalizado..."<<endl;

    return 0;
}