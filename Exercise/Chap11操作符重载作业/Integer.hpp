#ifndef INTEGER_HPP
#define INTEGER_HPP

#include<iostream>
#include<string>

class Integer{
    public:
    //constructor
    Integer(int v=0);
    Integer(const char*c_str);
    Integer(const std::string& str);

    //Copy 
    Integer(const Integer& rhs); //Copu constructor
    Integer& operator=(const Integer& rhs);//Copy assignment
    Integer& operator=(int rhs);//assignment,Not the'copy' version
    
    //Change 
    std::string toString()const; //int to string
    int intValue()const; //int value of object
    operator double() const; //int to double
    operator char() const;   //int to char

    //Relational operation
    int cmp(const Integer& rhs); //if a<b,return 1
     bool operator<( const Integer& b); //friend？
     bool operator>( const Integer& b);
     bool operator<=( const Integer& b);
     bool operator>=( const Integer& b);
     bool operator==( const Integer& b);
     bool operator!=( const Integer& b);

    //string to int
    static int parse(const char* c_str) {
    int result = 0;
    bool negative = false;
    int i = 0;

    // 处理正负号
    if (c_str[0] == '-') {
        negative = true;
        i++;
    } else if (c_str[0] == '+') {
        i++;
    }

    // 转换数字部分
    while (c_str[i] != '\0') {
        if (c_str[i] >= '0' && c_str[i] <= '9') {
            result = result * 10 + (c_str[i] - '0');
        } else {
            // 遇到非数字字符,认为输入非法
            throw std::invalid_argument("Invalid integer format");
        }
        i++;
    }

    // 处理负数
    if (negative) {
        result = -result;
    }

    return result;
    }

    static int parse(const std::string& str) {
    return parse(str.c_str());
    }

    //Arithmetic operation(一元运算符)
    Integer operator-()const;
    Integer operator+()const;
    Integer& operator++();
    Integer& operator--();

    Integer& operator+=(const Integer& b);
    Integer& operator-=(const Integer& b);
    Integer& operator/=(const Integer& b);
    Integer& operator*=(const Integer& b);

    //non-member function of class
    friend Integer operator+(const Integer&lhs, const Integer& rhs);
    friend Integer operator-(const Integer&lhs, const Integer& rhs);
    friend Integer operator*(const Integer&lhs, const Integer& rhs);
    friend Integer operator/(const Integer&lhs, const Integer& rhs);

    friend std::ostream& operator<<(std::ostream& os,const Integer& i);
    friend std::istream& operator>>(std::istream& is,Integer& i);


    private:
        int value;
};

#endif