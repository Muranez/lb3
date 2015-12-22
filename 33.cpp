#include "sdt.h"
enum error{ok,wr_sc,wr_tm};
error convert(double temperature, char from, char to,double& resul)
{
if (from=='C') {
   switch(to){
   case 'K':{if (temperature>-273) { resul=temperature+273;     return ok; break;}  else{ return wr_tm; break;}}
   case 'F':{if (temperature>-273) { resul=temperature*1.8+32;  return ok; break;}  else{ return wr_tm; break;}}
   case 'C':{if (temperature>-273) { resul=temperature;         return ok; break;}  else{ return wr_tm; break;}}
   }
 }
else {if (from=='K') {
   switch(to){
   case 'K':{if (temperature-273>-273) {resul=temperature;               return ok; break;} else{ return wr_tm; break;}}
   case 'F':{if (temperature-273>-273) {resul=(temperature-273)*1.8+32;  return ok; break;} else{ return wr_tm; break;}}
   case 'C':{if (temperature-273>-273) {resul=temperature-273;           return ok; break;} else{ return wr_tm; break;}}
   }
}
else {if (from=='F') {
   switch(to){
   case 'K':{if ((temperature-32)/1.8>-273) {resul=((temperature-32)/1.8)+273;  return ok; break;} else{ return wr_tm; break;}}
   case 'F':{if ((temperature-32)/1.8>-273) {resul=temperature;                 return ok; break;} else{ return wr_tm; break;}}
   case 'C':{if ((temperature-32)/1.8>-273) {resul=(temperature-32)/1.8;        return ok; break;} else{ return wr_tm; break;}}
   }
}
else {return wr_sc;}
}
}
}
main()
{
vector<double> kel;
double num,lim,l;
char sim;
while (cout << "Enter scale=",cin >> num >> sim) {
switch(convert(num,sim,'C',l)){
case ok:{kel.push_back(l);
         convert(num,sim,'K',l);
         kel.push_back(l);
         convert(num,sim,'F',l);
         kel.push_back(l);
         break;}
case wr_tm:{cerr << "Wrong Temperature!\n"; break;}
case wr_sc:{cerr << "Wrong Scale!\n";       break;}
default:   {cerr << "Other wrong\n";        break;}
}
}
for (int i=0; i<kel.size(); i=i+3) {
cout << "Celsius=" << kel[i] << "\t" << " Kelvin=" << kel[i+1] << "\t" << " Farehgeit=" << kel[i+2] << "\t" << "\n";
}
}
