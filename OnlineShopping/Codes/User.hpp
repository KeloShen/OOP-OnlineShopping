//
//  User.hpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//
#pragma once
#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class User
{
    protected:
    string username;
    string password;
    User();
    User(const string& uname, const string& pwd);
    virtual ~User();
    
    public:
    //检查密码是否正确
    virtual bool checkPassword(const string& pwd)const;
    //修改密码
    virtual void changePassword(const string& newPwd);
    //返回当前对象的用户名
    string getUsername() const;
};


#endif /* User_hpp */
