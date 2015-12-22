#include "sdt.h"
#include "convert.h"

int main()
{
vector<Temperature> kel;
double l;
Temperature data{0,C};
Temperature maximum {0,C};
Temperature minimum {0,C};
Temperature average {0,C};
while (cout << "Enter scale=",cin >> data) {
 try {kel.push_back(Temperature(convert(data.num,data.sim,C),C));
     }
    catch (const invalid_argument& e) {cerr  << e.what()  << endl;}
    catch (const logic_error& el)     {cerr  << el.what() << endl;}
}
ofstream output ("file.txt");
for (Temperature y:kel) {
cout << "Celsius=" << y.num <<"\t" << " Kelvin=" << y.num+273 << "\t" << " Farehgeit=" << y.num*1.8+32 << "\t" << "\n";
}
cout << endl;
minimax(kel,minimum,maximum,average);
cout << "Minimum=" << minimum << "  Maximum=" << maximum << "  Average=" << average << "\n";
}
