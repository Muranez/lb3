#include "sdt.h"
#include "convert.h"

double convert(double temperature, Scale from, Scale to)
{
if (from==C) {
   switch(to){
   case K:{if (temperature>-273) {return temperature=temperature+273;      break;}                 else{ throw invalid_argument("Temperature <0!"); break;}}
   case F:{if (temperature>-273) {return temperature=temperature*1.8+32;   break;}                 else{ throw invalid_argument("Temperature <0!"); break;}}
   case C:{if (temperature>-273) {return temperature=temperature;          break;}                 else{ throw invalid_argument("Temperature <0!"); break;}}
   }
 }
else {if (from==K) {
   switch(to){
   case K:{if (temperature-273>-273) {return temperature=temperature;               break;}         else{ throw invalid_argument("Temperature <0!"); break;}}
   case F:{if (temperature-273>-273) {return temperature=(temperature-273)*1.8+32;  break;}         else{ throw invalid_argument("Temperature <0!"); break;}}
   case C:{if (temperature-273>-273) {return temperature=temperature-273;           break;}         else{ throw invalid_argument("Temperature <0!"); break;}}
   }
}
else {if (from==F) {
   switch(to){
   case K:{if ((temperature-32)/1.8>-273) {return temperature=((temperature-32)/1.8)+273;   break;} else{ throw invalid_argument("Temperature <0!"); break;}}
   case F:{if ((temperature-32)/1.8>-273) {return temperature=temperature;                  break;} else{ throw invalid_argument("Temperature <0!"); break;}}
   case C:{if ((temperature-32)/1.8>-273) {return temperature=(temperature-32)/1.8;         break;} else{ throw invalid_argument("Temperature <0!"); break;}}
   }
}
else {throw logic_error("Wrong scale!");}
}
}
}
