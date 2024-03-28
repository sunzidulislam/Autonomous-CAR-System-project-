int rms=10;
int rmf=12;
int rmb=13;

int lms=9;
int lmf=8;
int lmb=11;

#define spl 20
#define spr 19
double target_angle=0;
double error=0;
void setup() {
 pinMode(rmf,OUTPUT);
 pinMode(rmb,OUTPUT);
 pinMode(lmf,OUTPUT);
 pinMode(lmb,OUTPUT);
 pinMode(rms,OUTPUT);
 pinMode(lms,OUTPUT);
}

void loop() {
  double current_angle= 12;
  
  int pos=angle (target_angle,current_angle);
 // pos=1 clock-wise   pos=0 anti-clockwise

 
  if (error == 0.00) {motor(10 * spl, 10 * spr);}


  //if (error>=0.0 && error<=5.0) {motor(10 * spl, 10 * spr);}
  else{
    
    if(pos==0){
        if (error>0.0 && error<=36.0 ) motor(9 * spl, 10 * spr);
        else if (error>36.0 && error<=72.0  ) motor(6 * spl, 10 * spr);
        else if (error>72.0 && error<=108.0) motor(3 * spl, 10 * spr);
        else if (error>108.0 && error<=144.0 ) motor(0 * spl, 10 * spr);
        else if    (error>144.0 && error<=180.0 ) motor(-3 * spl, 10 * spr);
    }

    else{
        
        if (error>0.0 && error<=36.0) motor(10 * spl, 9 * spr);
        else if (error>36.0 && error<=72.0  ) motor(10 * spl, 6 * spr);
        else if (error>72.0 && error<=108.0) motor(10 * spl, 3 * spr);
        else if (error>108.0 && error<=144.0) motor(10 * spl, 0 * spr);
        else if (error>144.0 && error<=180.0) motor(10 * spl, -3 * spr);
        
    }   
  }     
}

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

  
