//
//  shopSystem.hpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//
#pragma once
#ifndef shopSystem_hpp
#define shopSystem_hpp
#include"User.hpp"
#include"Customer.hpp"
#include"Admin.hpp"
#include <stdio.h>
#include "Good.hpp"
#include"Coupon.hpp"
#include<map>
#include<chrono>
#include<sstream>


class shopSystem{
private:
    // 存储所有Customer对象的map，使用用户名作为键
    map<string, Customer> customers;
    // 存储所有Admin对象的map，使用用户名作为键
    map<string, Admin> admins;
    map<string, Good> goods;
    // 使用map来存储顾客和他们的购物车的关联
    map<string, unordered_map<string, int>> customersCarts;
    
    //优惠券
    map<string, Coupon> coupons;
    // 存储有效优惠券码的集合
    static unordered_set<string> validCouponCodes;
    
    string customerDataFile = "customers.txt";
    string cartsDataFile="carts.txt";
    
    // 购物历史记录条目，包含商品、单价、购买数量和购买时间
    typedef pair<double, pair<Good, pair<int, chrono::system_clock::time_point>>> PurchaseRecord;
    // 顾客购物历史记录，存储所有购买记录
    map<string, vector<PurchaseRecord>> customerHistory;
    
public:
    //购物系统的构建，包括初始化管理员账号以及商品
    shopSystem();
    
    //登陆
    void login();
    
    //顾客注册
    void registerCustomer();
    
    // 保存顾客数据
    void saveCustomers();
    
    //输出商品信息
    void printAllGoods();
    
    //根据名字检索商品
    void queryGoodsByName(const string & goodsName);
    
    //名字不匹配--推荐商品
    void recommendGoods(const string& keyword);
    
    //创建顾客购物车
    void shoppingCart(const string & username);
    
    //初始化购物车
    void initializeCustomerCart(const string & username);
    
    //在购物车加入商品
    void addToCart(const string & username,const string & goodsname,const int & quantity);
    
    //展示购物车中的商品
    void showCart(const string &username)const;
    
    //删除购物车的指定商品
    void removeFromCart(const string & username,const string & goodsname);
    
    //改变购物车中需要买的商品的数量
    void  changeQuantityInCart(const string &username,const string & goodsname,  int &quantity);
    
    //从文件中恢复购物车的数据（在第4次任务中实现，放入购物车初始化中）
    void restoreCustomerCartsFromFile(const string& filename);
    
    //保存顾客的购物车数据到文件中(也在第4次任务中实现）
    void saveCustomerCartsToFile(const string & shoppingCartsFilename);
    
    // 用于从用户获取日期范围的函数（在第5次任务中实现）


    
    //第3次任务中实现：购物车结算以及优惠券实现
    //购买商品(在第3次任务中实现）
    void my_tobuy(const string & username);
    
    //顾客选择购物车中的商品进行结算
    void checkoutAllItemsOfKind(const string& customerName);
    
    //顾客选择购物车中所有的商品进行结算
    void checkoutAllItems(const string& customerName);
    
    //购物券
    // 派送随机优惠券给顾客
    void sendRandomCoupon(const string& customerName,const double& total);
    // 结算商品，并应用优惠券
    double checkout(const string& customerName,  double& total, const string& couponCode);
    
    
    //注销顾客的数据
    void deleteCustomer(const string& customerFilename,const string & shoppingCartsFilename,const string& username);
    
    // 加载顾客数据
    void loadCustomers();
    
    string trim(const string& str, const string& whitespace = " \t\n\r\f\v")
    {
        const auto strBegin = str.find_first_not_of(whitespace);
        if (strBegin == string::npos)
            return ""; // no content

        const auto strEnd = str.find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }
    
    //任务五：
    // 用于从用户获取日期范围;
    pair<chrono::system_clock::time_point, chrono::system_clock::time_point> getDateRangeFromUser();
    
    // 函数，用于打印时间段内的购买记录
    void printPurchaseRecords(const string& customerName, const pair<chrono::system_clock::time_point, chrono::system_clock::time_point>& dateRange);

};

#endif /* shopSystem_hpp */
