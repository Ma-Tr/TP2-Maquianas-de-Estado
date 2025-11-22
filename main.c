#include "config.h"





int main(void) {

init_mcu();

while(1){



switch(Estado){

   case 1:// Espera
      S1=0;
      S2=0;
      Nivel= medir_distancia_cm();
      
      if(Nivel> Set_N + Delta_N){
	 Estado = 2;
	 }
      else if(Nivel< Set_N - Delta_N){
	 Estado = 3;
	 }
      else {
	 Estado =1;
	 }
	 
      break;
   
   case 2: //llenar
      S1=1;
      S2=0;
      Nivel= medir_distancia_cm();
      
      if(Nivel > Set_N+Delta_N){
      Estado = 2;
      }
   else if(Nivel< Set_N){
      Estado = 1;
      }
   else { 
      Estado =2;
      }
   break;
   
   case 3:// vaciar
      S1=0;
      S2=1;
      Nivel= medir_distancia_cm();
      
      if(Nivel < Set_N-Delta_N){
      Estado = 3;
      }
   else if(Nivel> Set_N){
      Estado = 1;
      }
   else { 
      Estado =3;
      }
   break;
   
   
}
}


return 0;
}
