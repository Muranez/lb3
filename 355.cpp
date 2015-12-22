#include "sdt.h"
double convert(double temperature, char from, char to,double& resul)
{
if (from=='C') {
   switch(to){
   case 'K':{if (temperature>-273) { resul=temperature+273;      break;}                 else{ throw invalid_argument("Temperature <0!"); break;}}
   case 'F':{if (temperature>-273) { resul=temperature*1.8+32;   break;}                 else{ throw invalid_argument("Temperature <0!"); break;}}
   case 'C':{if (temperature>-273) { resul=temperature;          break;}                 else{ throw invalid_argument("Temperature <0!"); break;}}
   }
 }
else {if (from=='K') {
   switch(to){
   case 'K':{if (temperature-273>-273) {resul=temperature;               break;}         else{ throw invalid_argument("Temperature <0!"); break;}}
   case 'F':{if (temperature-273>-273) {resul=(temperature-273)*1.8+32;  break;}         else{ throw invalid_argument("Temperature <0!"); break;}}
   case 'C':{if (temperature-273>-273) {resul=temperature-273;           break;}         else{ throw invalid_argument("Temperature <0!"); break;}}
   }
}
else {if (from=='F') {
   switch(to){
   case 'K':{if ((temperature-32)/1.8>-273) {resul=((temperature-32)/1.8)+273;   break;} else{ throw invalid_argument("Temperature <0!"); break;}}
   case 'F':{if ((temperature-32)/1.8>-273) {resul=temperature;                  break;} else{ throw invalid_argument("Temperature <0!"); break;}}
   case 'C':{if ((temperature-32)/1.8>-273) {resul=(temperature-32)/1.8;         break;} else{ throw invalid_argument("Temperature <0!"); break;}}
   }
}
else {throw logic_error("Wrong scale!");}
}
}
}

main()
{
vector<double> kel;
double num,lim,l;
char sim;
while (cout << "Enter scale=",cin >> num >> sim) {
 try {convert(num,sim,'C',l);
      kel.push_back(l);
      convert(num,sim,'K',l);
      kel.push_back(l);
      convert(num,sim,'F',l);
      kel.push_back(l);
     }
    catch (const invalid_argument& e) {cerr  << e.what()  << endl;}
    catch (const logic_error& el)     {cerr  << el.what() << endl;}
}
for (int i=0; i<kel.size(); i=i+3) {
cout << "Celsius=" << kel[i] << "\t" << " Kelvin=" << kel[i+1] << "\t" << " Farehgeit=" << kel[i+2] << "\t" << "\n";
}
}
