#include "unit_Model.hpp"
#include "unit_Flow.hpp"
#include "unit_System.hpp"

int main(){
    cout<<"Executando teste unitario"<<endl;
  
    
    run_unit_test_Model();
    
    run_unit_test_Flow();
    
    run_unit_test_System();
    

    cout<<"Teste unitario finalizado!"<<endl;
    
    return 0;
}