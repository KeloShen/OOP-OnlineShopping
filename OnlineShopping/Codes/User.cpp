//
//  User.cpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//

#include "User.hpp"

User::User(){}
User::User(const string& uname, const string& pwd):username(uname),password(pwd){}

//检查密码是否正确
bool User::checkPassword(const string& pwd)const{
    return pwd==password;
}

//修改密码
void User::changePassword(const string& newPwd){
    password=newPwd;
}

User:: ~User(){}

//返回当前对象的用户名
string User::getUsername() const{
    return username;
}
