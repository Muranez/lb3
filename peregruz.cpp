#include "convert.h"
#include "sdt.h"

bool operator <(const Temperature& first,const Temperature& second)
{
    return convert(first.num,first.sim,C) < convert(second.num,second.sim,C);
}

bool operator >(const Temperature& first,const Temperature& second)
{
    return convert(first.num,first.sim,C) > convert(second.num,second.sim,C);
}



Temperature operator + (const Temperature& first,const Temperature& second)
{
    return{first.num+convert(second.num,second.sim,first.sim),first.sim};
}


Temperature& operator += (Temperature& first,const Temperature& second)
{
    first.num=first.num+convert(second.num,second.sim,first.sim);
    return first;
}


Temperature operator / (const Temperature& first,double number)
{
    double val_del;
    val_del=first.num;
    return{val_del/number,first.sim};
}

Temperature& operator /= (Temperature& first,double number)
{
    double val_del;
    val_del=first.num;
    first.num=val_del/number;
    return first;
}



 ostream& operator << (ostream& output, const Scale& temp)
    {
        char name;
        //output << name;
        switch(temp)
        {
        case C:
            output << 'C';
            break;
        case K:
            output << 'K';
            break;
        case F:
            output << 'F';
            break;
        }
        return output;
}



    istream& operator>>(istream& input,Scale& temp)
    {
        char name;
        input >> name;
        switch(name)
        {
        case 'C':
            temp=C;
            break;
        case 'K':
            temp=K;
            break;
        case 'F':
            temp=F;
            break;
        default:
            temp=(Scale&) name;
            break;
        }
        return input;
    }


    istream& operator >>
    (istream& input, Temperature& data)
    {
        input >> data.num >> data.sim;
        return input;
    }

    ostream& operator <<
    (ostream& output, const Temperature& data)
    {
        output << data.num << data.sim;
        return output;
    }
