//
//  Coupon.hpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/28.
//
#pragma once
#ifndef Coupon_hpp
#define Coupon_hpp
#include<string>
#include<unordered_set>
#include <stdio.h>
using namespace std;

class Coupon{
private:
    string couponCode;
    double discountAmount;//折扣
    
public:
    //存储优惠码的集合
    static unordered_set<string> validCouponCodes;
    
    Coupon();
    Coupon(const string& code, double amount);
    
    // 检查优惠券码是否在有效优惠券码集合中
    static bool isValid(const string& couponCode);
    
    // 检查优惠券是否有效，并返回折扣金额
    double applyDiscont(double total,const string& couponCode);

};



#endif /* Coupon_hpp */
