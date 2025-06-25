//
//  Administer.hpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//

#pragma once
#ifndef Admin_hpp
#define Admin_hpp
#include"User.hpp"
#include <stdio.h>

class Admin:public User{
public:
    Admin();
    Admin(const string & uname,const string & pwd);
    ~Admin();
};

#endif /* Admin_hpp */
