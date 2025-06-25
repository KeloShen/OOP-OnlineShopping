# OOP-OnlineShopping 在线购物系统

## 项目简介

这是一个基于C++面向对象程序设计开发的在线购物系统，实现了完整的电商购物功能。

## 系统功能

- **用户管理**：顾客注册、登录、管理员权限控制
- **商品管理**：商品展示、搜索、库存管理
- **购物车**：添加商品、修改数量、查看总价
- **订单结算**：优惠券系统、满额折扣、购买记录
- **数据持久化**：用户数据和购物车信息保存到文件

## 学习价值

### 面向对象程序设计
- 类的封装、继承、多态
- 虚函数和动态绑定
- 构造函数和析构函数

### C++编程技巧
- STL容器使用（map、unordered_map、vector）
- 文件输入输出操作
- 字符串处理和异常处理
- 时间库（chrono）应用

### 系统设计思维
- 模块化设计
- 数据持久化
- 用户交互设计
- 业务逻辑实现

## 如何学习

1. **阅读代码结构**：从main.cpp开始，理解程序入口和整体流程
2. **学习类设计**：研究User、Customer、Admin的继承关系
3. **理解数据管理**：学习如何使用STL容器管理数据
4. **掌握文件操作**：了解如何保存和读取用户数据
5. **实践功能扩展**：尝试添加新功能，如商品分类、支付系统等

## 项目结构

### OnlineShopping/ - 主要项目目录
```
OnlineShopping/
├── Codes/               # 源代码目录
│   ├── main.cpp         # 程序入口
│   ├── shopSystem.hpp   # 购物系统类头文件
│   ├── shopSystem.cpp   # 购物系统类实现
│   ├── User.hpp         # 用户基类头文件
│   ├── User.cpp         # 用户基类实现
│   ├── Customer.hpp     # 顾客类头文件
│   ├── Customer.cpp     # 顾客类实现
│   ├── Admin.hpp        # 管理员类头文件
│   ├── Admin.cpp        # 管理员类实现
│   ├── Good.hpp         # 商品类头文件
│   ├── Good.cpp         # 商品类实现
│   ├── Coupon.hpp       # 优惠券类头文件
│   └── Coupon.cpp       # 优惠券类实现
└── Report/              # 项目报告目录
    └── OOP-OnlineShopping-Report_Redacted.pdf
```

### Reference/ - 参考资料目录
```
Reference/
└── Data Center Reservation System/  # 数据中心预约系统
    ├── Lecture Notes/   # 课程笔记
    ├── Finished Product/ # 完成的产品
    ├── Pictures/        # 相关图片
    └── Codes/           # 参考代码
```

### Exercise/ - 练习作业目录
```
Exercise/
└── Chap11操作符重载作业/
    ├── Integer.hpp      # Integer类头文件
    ├── Integer.cpp      # Integer类实现
    └── test_Integer.cpp # 测试文件
```

## 各目录学习内容

### OnlineShopping - 主要学习项目
- **完整的电商系统实现**：从用户管理到订单结算的完整流程
- **面向对象设计实践**：User基类，Customer和Admin继承
- **数据持久化技术**：文件操作和数据恢复
- **STL容器应用**：map、unordered_map管理复杂数据
- **业务逻辑实现**：购物车、优惠券、库存管理等

### Reference - 扩展学习资料
- **数据中心预约系统**：另一个完整的系统设计案例
- **课程笔记**：理论学习资料
- **完成产品**：可运行的参考实现
- **相关图片**：系统界面和流程图
- **参考代码**：其他实现方式的代码示例

### Exercise - 专项技能练习
- **操作符重载**：Integer类的完整实现
- **构造函数重载**：多种构造方式
- **拷贝控制**：拷贝构造函数和赋值操作符
- **关系操作符**：比较操作符重载
- **算术操作符**：四则运算操作符重载
- **输入输出流**：流操作符重载
- **类型转换**：隐式和显式类型转换

## 编译运行

### 在线购物系统
```bash
cd OnlineShopping/Codes
g++ -std=c++11 -o shopping *.cpp
./shopping
```

### 操作符重载练习
```bash
cd Exercise/Chap11操作符重载作业
g++ -std=c++11 -o test_integer Integer.cpp test_Integer.cpp
./test_integer
```

## 学习建议

1. **从OnlineShopping开始**：先理解完整的系统架构
2. **参考Reference资料**：学习其他系统设计思路
3. **练习Exercise作业**：巩固操作符重载等专项技能
4. **对比学习**：比较不同实现方式的优缺点
5. **实践扩展**：基于现有代码添加新功能

---

*这是一个完整的C++面向对象编程学习项目集合，包含主项目、参考资料和专项练习，适合系统性的学习。*
