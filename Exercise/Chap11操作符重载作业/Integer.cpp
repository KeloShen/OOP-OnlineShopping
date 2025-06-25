#include "Integer.hpp"
#include<cstdlib>

    //constructor
    Integer::Integer(int value):value(value){}
    Integer::Integer(const char*c_str){
        value=parse(c_str);
    }
    Integer::Integer(const std::string& str){
        value=parse(str);
    }

    //Copy 
    Integer::Integer(const Integer& rhs){//Copy constructor
        value=rhs.value;
    } 
    Integer& Integer::operator=(const Integer& rhs)//Copy assignment
    {
        value=rhs.value;
        return *this;
    }
    
    Integer& Integer::operator=(int rhs)//assignment,Not the'copy' version
    {
        value=rhs;
        return *this;
    }
    
    //Change 
    std::string Integer::toString()const //int to string
    {
        return std::to_string(value);
    }
    int Integer::intValue()const //int value of object
    {
        return value;
    }
    Integer::operator double() const //int to double
    {
        return static_cast<double>(value);//这是什么
    }
    Integer::operator char() const   //int to char
    {
        return static_cast<char>(value);
    }

    //Relational operation
    int Integer::cmp(const Integer& rhs)//if a<b,return -1
    {
        if(value<rhs.value)return -1;
        else if(value>rhs.value)return 1;
        else return 0;
    }
     bool Integer::operator<( const Integer& b) //friend？
     {
        return this->cmp(b)==-1;

     }
     bool Integer::operator>( const Integer& b)
     {
        return this->cmp(b)==1;
     }
     bool Integer::operator<=( const Integer& b)
     {
        return this->cmp(b)<=0; 
     }
     bool Integer::operator>=( const Integer& b)
    {
        return this->cmp(b)>=0; 
    }
     bool Integer::operator==( const Integer& b)
    {
        return this->cmp(b)==0;
    }
     bool Integer::operator!=( const Integer& b)
     {
        return this->cmp(b)!=0; 
     }


    //string to int
    // static int parse(const char* c_str) //为什么要是静态成员函数
    // {
    //     return std::atoi(c_str);
    // }
    // static int parse(const std::string& str)
    // {
    //     return std::stoi(str);
    // }


    //Arithmetic operation(一元运算符)
    Integer Integer::operator-()const
    {
        return Integer(-value);
    }
    Integer Integer::operator+()const
    {
        return Integer(abs(value));
    }
    Integer& Integer::operator++()
    {
        ++value;
        return *this;
    }
    Integer& Integer::operator--()
    {
        --value;
        return *this;
    }

    Integer& Integer::operator+=(const Integer& b)
    {
        value+=b.value;
        return *this;
    }
    Integer& Integer::operator-=(const Integer& b)
    {
        value-=b.value;
        return *this;
    }
    Integer& Integer::operator/=(const Integer& b)
    {
        value/=b.value;
        return *this;
    }
    Integer& Integer::operator*=(const Integer& b)
    {
        value*=b.value;
        return *this;
    }

    //non-member function of class
     Integer operator+(const Integer&lhs, const Integer& rhs)
     {
        Integer result;
        result.value=lhs.value+rhs.value;
        return result;
     }
     Integer operator-(const Integer&lhs, const Integer& rhs)
    {
        Integer result;
        result.value=lhs.value-rhs.value;
        return result;
    }
     Integer operator*(const Integer&lhs, const Integer& rhs)
    {
        Integer result;
        result.value=lhs.value*rhs.value;
        return result;
    }
     Integer operator/(const Integer&lhs, const Integer& rhs)
     {
        Integer result;
        result.value=lhs.value/rhs.value;
        return result;
     }

     std::ostream& operator<<(std::ostream& os,const Integer& i)
     {
        os<<"value is "<<i.value;
        return os;
     }
     std::istream& operator>>(std::istream& is,Integer& i)
     {
        int value;
        is>>value;
        i.value=value;
        return is;

     }
