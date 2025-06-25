//
//  Customer.cpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//

#include "Customer.hpp"
#include <iostream>
using namespace std;

Customer::Customer(){}

Customer::Customer(const string& uname, const string& pwd,  const string& phone):User(uname,pwd),phone(phone){
    
}

Customer::~Customer(){}

void Customer::updatePhone(const string& newPhone){
    phone=newPhone;
}
void Customer::displayInfo(){
    cout << "用户名: " << username  << "\n电话: " << phone << endl;
}
string Customer::getuname()const
{
    return username;
}
string Customer::getpwd() const{
    return password;
}
string Customer::getphone() const
{
    return phone;
}
