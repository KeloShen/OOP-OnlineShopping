//
//  Good.cpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16
//

#include "Good.hpp"
using namespace std;

Good::Good(){}

Good::Good(const string& goodname,const double& goodprice,const string & goodes,const int & goodstock):goodname(goodname),goodprice(goodprice),goodes(goodes),goodstock(goodstock){}
Good::~Good(){}

string Good::getGoodName()const{
    return goodname;
}
string Good::getGoodDescription()const{
    return goodes;
}
double Good::getGoodPrice()const{
    return goodprice;
}

void Good:: display()const
{
    cout<<"商品名称："<< goodname <<"\n价格:"<< goodprice << "￥\n描述："<< goodes <<"\n库存："<< goodstock<<"件"<<endl;
}
void Good:: changePrice(const double& newprice)
{
    goodprice=newprice;
}
void Good:: changeDes(const string& newdes)
{
    goodes=newdes;
}
void Good:: changeStock(const int& newstock)
{
    goodstock=newstock;
}

bool Good::checkStock(int quantity)//检查有没有足够的库存供给quantity个
{
    return goodstock>=quantity;
}
void Good:: reduceStock(int quantity)
{
    if(goodstock>=quantity){
        goodstock-=quantity;
    }
    else{
        cerr << "库存不足！" << endl;
    }
}
