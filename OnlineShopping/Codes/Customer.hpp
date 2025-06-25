//
//  Customer.hpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//
#pragma once
#ifndef Customer_hpp
#define Customer_hpp
#include"User.hpp"
#include <stdio.h>

class Customer: public User
{
private:
    string phone;
public:
    Customer();
    Customer(const string& uname,const string & pwd,const string & phone);
    ~Customer();
    
    void updatePhone(const string& newPhone);
    void displayInfo();
    string getuname()const;
    string getpwd() const;
    string getphone() const;
};

#endif /* Customer_hpp */
