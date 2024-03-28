int angle(int target,int current){
  
     int circle; // clock-wise=1  anti-clock-wise=0 
     
     error = abs(target-current);
     if(target>current){
       circle=1;
      }
     else{
       circle=0; 
      }

      
     if(error >(360-error)){
       error= 360-error;
       circle=!circle;
     }
    
  }
