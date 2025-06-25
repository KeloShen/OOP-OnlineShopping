//
//  Coupon.cpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/28.
//

#include "Coupon.hpp"

Coupon::Coupon(){}

Coupon::Coupon(const string& code, double amount): couponCode(code),discountAmount(amount)
{
    
}

//静态成员变量初始化
unordered_set<string> Coupon::validCouponCodes;

// 检查优惠券码是否在有效优惠券码集合中
bool Coupon::isValid(const string& couponCode)
{
    return validCouponCodes.find(couponCode)!=validCouponCodes.end();
}

// 检查优惠券是否有效，并返回折扣金额
double Coupon::applyDiscont(double total,const string& couponCode)
{
    if (!isValid(couponCode))
    {
        throw runtime_error("***错误优惠码***\n");
    }
    return discountAmount;
}
