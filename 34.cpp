#include "sdt.h"
int last_error;
int get_last_error(){
return last_error;
}
double convert(double temperature, char from, char to,double& resul)
{
if (from=='C') {
   switch(to){
   case 'K':{if (temperature>-273) { resul=temperature+273;      break;}  else{ last_error=1; break;}}
   case 'F':{if (temperature>-273) { resul=temperature*1.8+32;   break;}  else{ last_error=1; break;}}
   case 'C':{if (temperature>-273) { resul=temperature;          break;}  else{ last_error=1; break;}}
   }
 }
else {if (from=='K') {
   switch(to){
   case 'K':{if (temperature-273>-273) {resul=temperature;               break;} else{ last_error=1; break;}}
   case 'F':{if (temperature-273>-273) {resul=(temperature-273)*1.8+32;  break;} else{ last_error=1; break;}}
   case 'C':{if (temperature-273>-273) {resul=temperature-273;           break;} else{ last_error=1; break;}}
   }
}
else {if (from=='F') {
   switch(to){
   case 'K':{if ((temperature-32)/1.8>-273) {resul=((temperature-32)/1.8)+273;   break;} else{ last_error=1; break;}}
   case 'F':{if ((temperature-32)/1.8>-273) {resul=temperature;                  break;} else{ last_error=1; break;}}
   case 'C':{if ((temperature-32)/1.8>-273) {resul=(temperature-32)/1.8;         break;} else{ last_error=1; break;}}
   }
}
else {last_error=1;}
}
}
}
main()
{
vector<double> kel;
double num,lim,l;
char sim;
last_error=0;
while (cout << "Enter scale=",cin >> num >> sim) {
convert(num,sim,'C',l);
switch(get_last_error()){
case 0:{kel.push_back(l);
         convert(num,sim,'K',l);
         kel.push_back(l);
         convert(num,sim,'F',l);
         kel.push_back(l);
         break;}
case 1: { cerr << "Wrong Temperature! or Wrong Scale!\n";  break;}
default:{ cerr << "Other wrong\n";                         break;}
}
last_error=0;
}
for (int i=0; i<kel.size(); i=i+3) {
cout << "Celsius=" << kel[i] << "\t" << " Kelvin=" << kel[i+1] << "\t" << " Farehgeit=" << kel[i+2] << "\t" << "\n";
}
}
