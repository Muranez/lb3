#include "sdt.h"
double convert(double temperature, char from, char to)
{
if (from=='C') {
   switch(to){
   case 'K':{if (temperature>-273) {return temperature+273;     break;} else{cout << "Wrong temperature!\n";  break;}}
   case 'F':{if (temperature>-273) {return temperature*1.8+32;  break;} else{cout << "Wrong temperature!\n";  break;}}
   case 'C':{if (temperature>-273) {return temperature;         break;} else{cout << "Wrong temperature!\n";  break;}}
   }
 }
else {if (from=='K') {
   switch(to){
   case 'K':{if (temperature-273>-273) {return temperature;              break;} else{cout << "Wrong temperature!\n";  break;}}
   case 'F':{if (temperature-273>-273) {return (temperature-273)*1.8+32; break;} else{cout << "Wrong temperature!\n";  break;}}
   case 'C':{if (temperature-273>-273) {return temperature-273;          break;} else{cout << "Wrong temperature!\n";  break;}}
   }
}
else {if (from=='F') {
   switch(to){
   case 'K':{if ((temperature-32)/1.8>-273) {return ((temperature-32)/1.8)+273;  break;} else{cout << "Wrong temperature!\n";  break;}}
   case 'F':{if ((temperature-32)/1.8>-273) {return temperature;                 break;} else{cout << "Wrong temperature!\n";  break;}}
   case 'C':{if ((temperature-32)/1.8>-273) {return (temperature-32)/1.8;        break;} else{cout << "Wrong temperature!\n";  break;}}
   }
}
else {cout << "Wrong Scale!\n"; }
}
}
}
main()
{
vector<double> kel;
double num,lim,l;
char sim;
while (cout << "Enter scale=",cin >> num >> sim) {
l=convert(num,sim,'C');
kel.push_back(l);
l=convert(num,sim,'K');
kel.push_back(l);
l=convert(num,sim,'F');
kel.push_back(l);
}
for (int i=0; i<kel.size(); i=i+3) {
cout << "Celsius=" << kel[i] << "\t" << "Kelvin=" << kel[i+1] << "\t" << "Farehgeit=" << kel[i+2] << "\t" << "\n";
}
}



