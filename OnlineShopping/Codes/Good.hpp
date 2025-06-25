//
//  Good.hpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//
#pragma  once
#ifndef Good_hpp
#define Good_hpp
#include <string>
#include <stdio.h>
#include<iostream>

using namespace std;
class Good{
private:
     string goodname;
     double goodprice;
     string goodes;
    
public:
    int goodstock;
    Good();
    Good(const string& goodname,const double& goodprice,const string & goodes,const int & goodstock);
    ~Good();
    string getGoodName()const;
    string getGoodDescription()const;
    double getGoodPrice()const;
    
    void display()const;
    void changePrice(const double& newprice);
    void changeDes(const string& newdes);
    void changeStock(const int& newstock);
    
    bool checkStock(int quantity);//检查有没有足够的库存供给quantity个
    void reduceStock(int quantity);
    
    
};

#endif /* Good_hpp */
