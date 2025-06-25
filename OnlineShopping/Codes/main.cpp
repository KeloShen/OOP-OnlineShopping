//
//  main.cpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//

#include"User.hpp"
#include"Customer.hpp"
#include"Admin.hpp"
#include"shopSystem.hpp"


int main(int argc, const char * argv[]) {
    
    srand(static_cast<unsigned int>(time(0)));

    shopSystem system;
    int action;
    // 定义一个整型变量，用于存储用户选择的动作
    // 使用无限循环来持续接受用户输入
    system.loadCustomers();
    while(true){
        
        cout << "======================  欢迎来到Kunxiang的购物车预约系统  ====================="
                 << endl;
            cout << endl << "请输入您希望进行的操作" << endl;
            cout << "\t\t -------------------------------\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t|     1.登陆 （管理员 or 顾客）     |\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t|          2.顾客注册             |\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t|          3.预览商品             |\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t|          4.退    出            |\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t -------------------------------\n";
            cout << "请通过输入前缀的数字以提供您的选择: "<<endl;
        
        cin >> action;
        // 从标准输入读取用户选择的动作
        
        if (cin.fail()) {
                cout << "***无效的选择，请重新选择***" << endl;
                cin.clear(); // 清除错误状态
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丢弃错误输入
                continue; // 重新提示用户输入
            }
        
        switch (action)
        {
        case 1://登陆
                system.login();
                // 调用System对象的login方法，处理用户登录
                break;
        case 2://顾客注册
                system.registerCustomer();
                system.saveCustomers();
                break;
        case 3://预览商品
                system.printAllGoods();
                break;
        case 4://退出
            cout<<"退出程序"<<endl;
                return 0;
        default://选择错误，重新输入
            cout << "***无效的选择，请重新选择***\n";
        }
    }

    return 0;
}
