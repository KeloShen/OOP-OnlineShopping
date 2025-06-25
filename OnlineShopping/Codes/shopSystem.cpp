//
//  shopSystem.cpp
//  SKX_Shopping
//
//  Created by Kunxiang on 2024/5/16.
//

#include "shopSystem.hpp"
#include<ostream>
#include<istream>
#include<fstream>


//购物系统的构建，包括初始化管理员账号以及商品
shopSystem::shopSystem()
{
    string admin_name,admin_key;
    admin_name="shenkunxiang";
    admin_key="123";
    admins[admin_name]=Admin(admin_name,admin_key);
    goods["AirPods_2"]=Good("AirPods_2",1799.99,"苹果无线耳机（库克的挤牙膏产品）",99);
    goods["iPhone_14"]=Good("iPhone_14",7899,"拥有此产品你可以登岛！",100);
    goods["Anker_Power_Bank"]=Good("Anker_Power_Bank",109,"专业做电子产品的Anker，充电宝质感一流",9);
    goods["Macbook"]=Good("Macbook",12999,"M2芯片，你还在等什么！",2000);
    
}

//登陆
void shopSystem::login()
{
    string username, password, userType,newpassword;
    int todo;
    cout << "输入用户类型(1.管理员 2.顾客): ";
    // 提示用户输入用户类型（管理员/顾客）
    cin >> userType;
    cout << "输入用户名: ";
    // 提示用户输入用户名
    cin >> username;
    cout << "输入密码: ";
    // 提示用户输入密码
    cin >> password;
    
    // 检查用户类型和用户信息，并尝试登录
    //顾客登陆
    if (userType == "2" && customers.find(username) != customers.end() && customers[username].checkPassword(password))
    {
        cout << "***顾客登录成功***\n";
        while(1)
        {

            cout<<"您要进行：\n1.查看商品\n2.查找商品\n3.打开购物车\n4.购买购物车内商品\n5.修改密码\n6.退出\n7.注销账号\n请选择操作（1-7）:";
            cin>>todo;
            string goodsname;
            switch(todo)
            {
            case 1:
                printAllGoods();
                break;
            case 2:
                cout<<"输入商品名称：";
                cin>>goodsname;
                queryGoodsByName(goodsname);
                break;
            case 3:
                shoppingCart(username);
                break;
            case 4:
                my_tobuy(username);
                break;
            case 5:
                cout<<"输入新密码：";
                cin>>newpassword;
                customers[username].changePassword(newpassword);
                cout<<"***密码修改成功***\n";
                break;
            case 6:
                    saveCustomerCartsToFile("carts.txt");
                    cout<<"***当前账号已退出***\n";
                    return;
            case 7:
                    deleteCustomer(customerDataFile,"carts.txt",username);
                    cout<<"***注销成功，退出程序后生效***\n";
                return;
            default:
                cout << "***无效的选择,请重新选择***";
                break;
            }
        }
    }
    
    //管理员登陆
    else if (userType == "1" && admins.find(username) != admins.end() && admins[username].checkPassword(password))
    {
        cout << "***管理员登录成功***\n";
        while(1)
        {
            cout<<"您要进行：\n1.添加商品\n2.删除商品\n3.修改商品价格\n4.修改商品描述\n5.修改商品库存\n6.删除用户\n7.退出\n请选择操作（1-7）:";
            cin>>todo;
            string goodsname,goodsdes,newdes;
            double goodsprice,newprice;
            int goodsinv,newstock;
            switch(todo)
            {
            case 1:
                cout<<"输入商品名称：";
                cin>>goodsname;
                // 检查商品是否已存在
                if (goods.find(goodsname) != goods.end())
                {
                    cout << "***该商品已存在，添加失败***\n";
                    return;
                }
                cout<<"输入商品价格：";
                cin>>goodsprice;
                cout<<"输入商品描述：";
                cin>>goodsdes;
                cout<<"输入商品库存：";
                cin>>goodsinv;
                // 创建新的Goods对象并添加到goods map中
                goods[goodsname] = Good(goodsname, goodsprice, goodsdes, goodsinv);
                // 提示管理员商品添加成功
                cout << "***商品添加成功***\n";
                break;
            case 2:
                cout<<"输入要删除商品名称：";
                cin>>goodsname;
                if (goods.find(goodsname) != goods.end())
                {
                    goods.erase(goodsname); // 如果存在，则删除它
                    cout << goodsname << " 已从系统中删除。" << endl;
                }
                else
                {
                    cout << goodsname << " 在系统中不存在" << endl;
                }
                break;
            case 3:
                cout<<"输入要修改价格商品名称：";
                cin>>goodsname;
                if (goods.find(goodsname) != goods.end())
                {
                    cout<<"输入新价格：";
                    cin>>newprice;
                    goods[goodsname].changePrice(newprice);
                    cout << goodsname << " 的价格已更新为：" << newprice << "￥" << endl;
                }
                else
                {
                    cout << goodsname << " 在系统中不存在" << endl;
                }
                break;
            case 4:
                cout<<"输入要修改描述商品名称：";
                cin>>goodsname;
                if (goods.find(goodsname) != goods.end())
                {
                    cout<<"输入新描述：";
                    cin>>newdes;
                    goods[goodsname].changeDes(newdes);
                    cout << goodsname << " 的描述已更新为：" << newdes << endl;
                }
                else
                {
                    cout << goodsname << " 在系统中不存在" << endl;
                }
                break;
            case 5:
                cout<<"输入要修改库存商品名称：";
                cin>>goodsname;
                if (goods.find(goodsname) != goods.end())
                {
                    cout<<"输入新库存：";
                    cin>>newstock;
                    goods[goodsname].changeStock(newstock);
                    cout << goodsname << " 的库存已更新为：" << newstock << endl;
                }
                else
                {
                    cout << goodsname << " 在系统中不存在" << endl;
                }
                break;
            case 6:
                cout<<"输入要删除顾客用户名：";
                cin>>username;
                deleteCustomer(customerDataFile,"carts.txt",username);
                cout<<"***删除用户成功，退出程序后生效***\n";
                break;
            case 7:
                cout<<"***当前账号已退出***\n";
                return;
            default:
                cout << "***无效的选择,请重新选择***";
                break;
            }
        }
    }
    else
    {
        cout << "***登录失败***\n";
    }
    
    
}

//顾客注册
void shopSystem::registerCustomer()
{
    string username, password, phone;
    // 提示用户输入用户名
    cout << "输入用户名: ";
    cin >> username;
    // 检查用户名是否已存在
    if (customers.find(username) != customers.end())
    {
        cout << "***该用户名已存在，注册失败***\n";
        return;
    }

    // 提示用户输入密码、邮箱和电话号码
    cout << "输入密码: ";
    cin >> password;
    cout << "输入电话号码: ";
    cin >> phone;
    // 创建新的Customer对象并添加到customers map中
    customers[username] = Customer(username, password, phone);
    // 提示用户注册成功
    cout << "***注册成功***\n";
    saveCustomers();
}

// 保存顾客数据
void shopSystem::saveCustomers()
{
    ofstream outfile;
    outfile.open(customerDataFile);
    if (outfile.is_open())
    {
        for (const auto& pair : customers)
        {
            const Customer& customer = pair.second;
            outfile << customer.getuname() << ","
                    << customer.getpwd() << ","
            << customer.getphone() << endl;
        }
        outfile.close();
    }
}

//输出商品信息
void shopSystem::printAllGoods(){
    for(auto& pair:goods)
    {
        pair.second.display();
    }
}

//根据名字检索商品
void shopSystem::queryGoodsByName(const string & goodsName)
{
    if (goods.find(goodsName) != goods.end())
    {
        goods.at(goodsName).display(); // 使用at函数来访问Goods对象并调用其display函数
    }
    else
    {
        cout << "未找到商品：" << goodsName << endl;
        recommendGoods(goodsName); // 如果没有找到，尝试推荐
    }
}

//名字不匹配--推荐商品
void shopSystem::recommendGoods(const string& keyword)
{
    vector<pair<string, Good>> recommended;
    //定义了一个 vector 容器，其中存储的元素是 pair 对象。这些pair 对象包含两个成员:
    //一个 string 类型的键（key）和一个 Good 类型的值（value）
    for (const auto& pair : goods)
    {
        //检查 pair 的 second 成员（即 Goods 对象）的商品名称是否包含 keyword 这个子串
        if (pair.second.getGoodName().find(keyword) != string::npos)
        {
            //将一个 pair 对象添加到 recommended 这个vector 容器的末尾
            recommended.push_back(pair);
        }
    }
    if (!recommended.empty())
    {
        cout << "推荐商品：" << endl;
        for (const auto& rec : recommended)
        {
            rec.second.display();
            cout << endl;
        }
    }
    else
    {
        cout << "没有找到与关键字 " << keyword << " 相关的商品。" << endl;
    }
}

//创建顾客购物车
void shopSystem::shoppingCart(const string & username)
{
    int todo;
    initializeCustomerCart(username);
    //初始化购物车
    while(1)
    {
        cout<<"您已打开购物车，您需要:\n1.添加商品\n2.查看购物车\n3.删除商品\n4.修改商品数量\n5.查看指定时间内商品购买金额\n6.退出购物车\n请选择（1-6）：";
        cin>>todo;
        if(todo==1)
        {
            string goodsname;
            int quantity;
            cout<<"查询后输入正确要添加商品名称：";
            cin>>goodsname;
            cout<<"所需数量为：";
            cin>>quantity;
            if(quantity<=goods[goodsname].goodstock)
            {
                addToCart(username,goodsname,quantity);
                cout<<"***"<<quantity<<"件"<<goodsname<<"添加成功***\n";
            }
            else{
                cout<<"库存不足"<<endl;
            }

        }
        else if(todo==2)
        {
            showCart(username);
        }
        else if(todo==3)
        {
            string goodsname;
            cout<<"查询后输入正确要删除商品名称：";
            cin>>goodsname;
            removeFromCart(username,goodsname);
            cout<<"***"<<goodsname<<"删除成功***\n";
        }
        else if(todo==4)
        {
            string goodsname;
            int quantity;
            cout<<"查询后输入正确要修改数量商品名称：";
            cin>>goodsname;
            cout<<"数量更改为：";
            cin>>quantity;
            changeQuantityInCart(username, goodsname, quantity);
            cout<<"***"<<goodsname<<"数量已更改***\n";
        }
        else if(todo==5)
        {
            auto dateRange = getDateRangeFromUser();
            printPurchaseRecords(username, dateRange);
            
        }
        else if(todo==6)
        {
            cout<<"***已退出购物车***\n";
            return;
        }
        else
        {
            cout<<"***无效选择，请重新选择***\n";
        }
    }
}

//初始化购物车
void shopSystem::initializeCustomerCart(const string & customerName)
{
    // 如果顾客还没有购物车，则为其创建一个空的购物车
    if (customersCarts.find(customerName) == customersCarts.end())
    {
        customersCarts[customerName] = unordered_map<string, int>();
    }
    //如果顾客已有购物车则什么也不做
    // 尝试从文件恢复购物车信息
    restoreCustomerCartsFromFile("carts.txt");
}

//在购物车加入商品
void shopSystem::addToCart(const string & customername,const string & goodsname,const int & quantity)
{
    // 确保商品存在
    if (goods.find(goodsname) != goods.end())
    {
        customersCarts[customername][goodsname] += quantity; // 增加数量
    }
    else
    {
        cout << "商品不存在于系统中！" << endl;
    }
}

//展示购物车中的商品
void shopSystem::showCart(const string &customerName)const{
    double totalPrice = 0.0; // 用于计算总价的变量
    for (const auto& item : customersCarts.at(customerName))
    {
        const Good& good = goods.at(item.first); // 获取商品信息
        cout << " 商品名称：" << item.first << ", 数量：" << item.second << endl;
        cout << "单价：" << good.getGoodPrice() << "￥, 描述：" << good.getGoodDescription() << endl;
        totalPrice += good.getGoodPrice() * item.second;
    }
    cout << "总价：" << totalPrice << "￥" << endl;
}

//删除购物车的指定商品
void shopSystem::removeFromCart(const string & customername,const string & goodsname)
{
    if (customersCarts[customername].find(goodsname) != customersCarts[customername].end())
    {
        customersCarts[customername].erase(goodsname);
        cout << "顾客 " << customername << " 的购物车中已删除商品 " << goodsname << endl;
    }
    else
    {
        cout << "商品不存在于系统中！" << endl;
    }
}

//改变购物车中需要买的商品的数量
void  shopSystem::changeQuantityInCart(const string &customername,const string & goodsname,  int &quantity)
{
    if (customersCarts[customername].find(goodsname) != customersCarts[customername].end())
    {
        if (quantity >= 0)   // 确保数量非负
        {
            customersCarts[customername][goodsname] = quantity;
            cout << "顾客 " << customername << " 的购物车中商品 " << goodsname << " 的数量已修改为 " << quantity << endl;
        }
        else
        {
            cout << "数量不能是负数！" << endl;
        }
    }
    else
    {
        cout << "商品不存在于系统中！" << endl;
    }
}

//购买购物车的里的商品
void shopSystem::my_tobuy(const string &customerName) {
    int todo;
    while (1) {
        // 修改提示信息，增加新的选项
        cout << "您已进入购买界面，请选择（1.从购物车中选择商品进行结算 2.结算所有商品 3.退出）：";
        cin >> todo;
        if (todo == 1) {
            checkoutAllItemsOfKind(customerName);
        } else if (todo == 3) {
            return;
        } else if (todo == 2) {
            checkoutAllItems(customerName);
        } else {
            cout << "***无效输入***\n";
        }
    }
}

//顾客选择购物车中的商品进行结算
void shopSystem::checkoutAllItemsOfKind(const string& customerName) {
    auto it = customersCarts.find(customerName);
    if (it == customersCarts.end() || it->second.empty()) {
        cout << "购物车为空或不存在" << endl;
        return;
    }

    showCart(customerName);

    vector<string> chosenItems;
    bool keepChoosing = true;

    while (keepChoosing) {
        cout << "请输入要购买的商品名称: ";
        string selectedItem;
        cin >> selectedItem;

        auto itemIt = it->second.find(selectedItem);
        if (itemIt == it->second.end()) {
            cout << "购物车中没有 " << selectedItem << " 这个商品" << endl;
        } else {
            chosenItems.push_back(selectedItem);
            cout << selectedItem << " 已添加到结算列表." << endl;
        }

        int continueChoosing;
        cout << "是否继续选择其他商品？（1.是 2.否）：";
        cin >> continueChoosing;
        if (continueChoosing != 1) {
            keepChoosing = false;
        }
    }

    double totalCost = 0.0;

    for (const string& selectedItem : chosenItems) {
        auto itemIt = it->second.find(selectedItem);
        int quantity = itemIt->second;

        auto goodsIt = goods.find(selectedItem);
        if (goodsIt == goods.end()) {
            cout << "找不到商品 " << selectedItem << " 的价格信息" << endl;
            continue;
        }

        Good& theGoods = goodsIt->second;
        if (!theGoods.checkStock(quantity)) {
            cout << "库存不足，无法结算 " << quantity << " 个 " << selectedItem << endl;
            continue;
        }

        double total = theGoods.getGoodPrice() * quantity;

        totalCost += total;

        // Update stock
        theGoods.reduceStock(quantity);

        // Remove item from cart
        removeFromCart(customerName, selectedItem);

        // 获取当前时间作为购买时间
        auto currentTime = chrono::system_clock::now();
        
        // 添加购物历史记录
        PurchaseRecord purchaseRecord = {total, {theGoods, {quantity, currentTime}}};
        customerHistory[customerName].push_back(purchaseRecord);
    }

    cout << "结算前，总价为: " << totalCost << " ￥" << endl;

    if (rand() % 2 == 0) {
        sendRandomCoupon(customerName,totalCost);
    }

    int useCoupon;
    string theCoupon;
    cout << "请选择是否使用优惠券（1.是 2.否）：";
    cin >> useCoupon;

    if (useCoupon == 1) {
        cout << "请输入优惠券码：";
        cin >> theCoupon;
        totalCost = checkout(customerName, totalCost, theCoupon);
    } else if (useCoupon == 2) {
    } else {
        cout << "***无效输入，已视为放弃优惠券***\n";
    }

    if (totalCost > 500) {
        cout << "***开业大酬宾！！！有活动啦～～消费总额大于500元有优惠，已为您自动打9折！！！***\n";
        totalCost *= 0.9;
    }

    cout << "最终结算金额为: " << totalCost << " ￥" << endl;
}

//购买购物车里的所有物品
void shopSystem::checkoutAllItems(const string &customerName) {
    if (customersCarts.find(customerName) == customersCarts.end()) {
        cout << "购物车不存在" << endl;
        return;
    }

    double totalCost = 0.0;
    vector<string> itemsToRemove;
    
    for (const auto &item : customersCarts[customerName]) {
        const string &goodsname = item.first;
        int quantity = item.second;
        if (goods.find(goodsname) != goods.end()) {
            Good& currentGood = goods[goodsname];
            if (currentGood.checkStock(quantity)) {
                double goodprice = currentGood.getGoodPrice();
                totalCost += quantity * goodprice;
                currentGood.reduceStock(quantity); // 更新库存
                itemsToRemove.push_back(goodsname); // 记录要移除的商品

                // 获取当前时间作为购买时间
                auto currentTime = chrono::system_clock::now();
                // 添加购物历史记录
                PurchaseRecord purchaseRecord = {quantity * goodprice, {currentGood, {quantity, currentTime}}};
                customerHistory[customerName].push_back(purchaseRecord);
            } else {
                cout << "商品 " << goodsname << " 库存不足，跳过结算该商品" << endl;
            }
        } else {
            cout << "商品 " << goodsname << " 不存在，跳过结算该商品" << endl;
        }
    }

    cout << "结算前，总价为: " << totalCost << " ￥" << endl;

    // 随机派送优惠券（50% 概率）
    if (rand() % 2 == 0) {
        sendRandomCoupon(customerName,totalCost);
    }

    // 用户选择是否使用优惠券
    int useCoupon;
    string theCoupon;
    cout << "请选择是否使用优惠券（1.是 2.否）：";
    cin >> useCoupon;

    if (useCoupon == 1) {
        cout << "请输入优惠券码：";
        cin >> theCoupon;
        totalCost = checkout(customerName, totalCost, theCoupon); // 处理优惠券
    } else if (useCoupon == 2) {
        // 不使用优惠券
    } else {
        cout << "***无效输入，已视为放弃优惠券***\n";
    }

    // 满额自动折扣
    if (totalCost > 500) {
        cout << "***开业大酬宾！！！有活动啦～～消费总额大于500元有优惠，已为您自动打9折！！！***\n";
        totalCost *= 0.9;
    }

    // 从购物车中移除已经购买的商品
    for (const string& itemToRemove : itemsToRemove) {
        customersCarts[customerName].erase(itemToRemove);
    }
    
    cout << "最终结算金额为: " << totalCost << " ￥。购买成功，已从购物车中移除购买的商品。" << endl;
}
// 派送随机优惠券给顾客
void shopSystem::sendRandomCoupon(const string& customerName,const double& total)
{
    // 生成随机的优惠券码和面值
    string couponCode = "COUPON" + to_string(rand() % 1000000); // 简单生成随机码
    double discountAmount = (rand() % 10) + total/20; //1到10的随机折扣金额

    int discount;
    discount=discountAmount*100/100;
    // 创建优惠券对象并存储
    coupons[couponCode] = Coupon(couponCode, discount);
    Coupon::validCouponCodes.insert(couponCode); // 将新生成的码添加到有效集合中
    // 告知顾客优惠券码
    cout << " 恭喜您已获得优惠券码：" << couponCode << "，面值为：" << discount << "元" << endl;
}

// 结算商品，并应用优惠券
double shopSystem::checkout(const string& customerName,  double& total, const string& couponCode)
{

    // 检查优惠券是否有效并应用折扣
    if (coupons.find(couponCode) != coupons.end())
    {
        Coupon coupon = coupons[couponCode];
        total -= coupon.applyDiscont(total,couponCode); // 假设applyDiscount返回的是折扣金额
        cout<<"优惠券码有效！已为您进行优惠"<<endl;
    }
    else{
        cout<<"抱歉，优惠券码无效，无法为您进行优惠"<<endl;
    }
    return total;
}




// 注销顾客的数据
void shopSystem::deleteCustomer(const string& customerDataFile, const string& shoppingCartsFile, const string& username) {
    // 从内存中删除顾客的购物车
    customersCarts.erase(username);
    
    // 更新顾客信息文件
    ifstream customerInFile(customerDataFile);
    ofstream customerOutFile("temp_customer.dat");
    string line;
    if (customerInFile.is_open() && customerOutFile.is_open()) {
        while (getline(customerInFile, line)) {
            // 检查当前行是否包含要删除的顾客信息
            if (line.find(username) == string::npos) {
                // 如果当前行不包含要删除的顾客信息,则写入临时文件
                customerOutFile << line << endl;
            }
        }
        customerInFile.close();
        customerOutFile.close();
        
        // 删除原始文件并将临时文件重命名为原始文件名
        remove(customerDataFile.c_str());
        rename("temp_customer.dat", customerDataFile.c_str());
    } else {
        cerr << "***无法打开顾客信息文件进行读取或写入***" << endl;
    }
    
    // 更新购物车信息文件
    ifstream cartInFile(shoppingCartsFile);
    ofstream cartOutFile("temp_cart.dat");
    bool isInsideCustomerCart = false;
    string currentCustomerName;
    if (cartInFile.is_open() && cartOutFile.is_open()) {
        while (getline(cartInFile, line)) {
            if (line.empty()) {
                // 空的行表示一个顾客的购物车结束
                isInsideCustomerCart = false;
                currentCustomerName.clear();
                continue;
            }
            
            // 检查是否进入了一个顾客的购物车部分
            if (!isInsideCustomerCart) {
                size_t pos = line.find(':');
                if (pos != string::npos) {
                    currentCustomerName = line.substr(0, pos);
                    
                    // 如果不是我们要删除的顾客,则写入新的临时文件
                    if (currentCustomerName != username) {
                        cartOutFile << line << endl;
                    }
                    
                    isInsideCustomerCart = true;
                }
            } else {
                // 如果我们已经在顾客的购物车内,但顾客不是我们要删除的,则写入新的临时文件
                if (currentCustomerName != username) {
                    cartOutFile << line << endl;
                }
            }
        }
        cartInFile.close();
        cartOutFile.close();
        
        // 删除原始文件并将临时文件重命名为原始文件名
        remove(shoppingCartsFile.c_str());
        rename("temp_cart.dat", shoppingCartsFile.c_str());
    } else {
        cerr << "***无法打开购物车信息文件进行读取或写入***" << endl;
    }
    
    cout << "***顾客的信息和购物车已从内存和文件中删除***" << endl;
}

// 函数:将所有顾客的购物车内容保存到指定文件
// @param filename: 要保存到的文件名
void shopSystem::saveCustomerCartsToFile(const string& filename)
{
    // 打开指定文件进行写入
    ofstream outfile(filename);
    if (!outfile.is_open())
    {
        // 如果无法打开文件,输出错误信息并返回
        cerr << "无法打开文件 " << filename << endl;
        return;
    }

    // 遍历所有顾客的购物车
    for (const auto& entry : customersCarts)
    {
        // 获取当前顾客的名称和购物车内容
        const string& customerName = entry.first;
        const auto& cart = entry.second;

        // 在文件中写入当前顾客的名称
        outfile << customerName << ":\n";

        // 遍历当前顾客的购物车,写入每个商品信息
        for (const auto& item : cart)
        {
            outfile << "  " << item.first << " " << item.second << endl;
        }

        // 在顾客购物车信息之间添加一个空行
        outfile << endl;
    }

    // 关闭文件
    outfile.close();
}

// 从文件中恢复购物车
void shopSystem::restoreCustomerCartsFromFile(const string& filename)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cerr << "无法打开文件 " << filename <<endl;
        return;
    }

    string line;
    string customerName;
    string goodsName;
    int quantity;

    while (getline(infile, line))
    {
        if (line.empty())
        {
            // 空行表示当前顾客的购物车结束
            if (!customerName.empty())
            {
                customersCarts[customerName]; // 创建一个空的购物车
                customerName.clear();
            }
            continue;
        }

        if (customerName.empty())
        {
            // 读取顾客名称
            size_t pos = line.find(':');
            if (pos != string::npos)
            {
                customerName = line.substr(0, pos);
                continue;
            }
        }
        else
        {
            // 读取商品名称和数量
            istringstream iss(line);
            iss >> goodsName >> quantity;
            if (!iss.fail())
            {
                customersCarts[customerName][goodsName] = quantity;
            }
        }
    }
    infile.close();
}


// 加载顾客数据
void shopSystem::loadCustomers()
{

    ifstream infile(customerDataFile);
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            stringstream ss(line);
            string username, password, phone;
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, phone); // 最后一个字段后面没有逗号，所以不需要指定分隔符

            // 去除可能的空白字符
            username = trim(username);
            password = trim(password);
            phone = trim(phone);

            // 创建Customer对象并添加到customers map中
            customers[username] = Customer(username, password,  phone);
        }
        infile.close();
    }
    else
    {
        cerr << "无法打开顾客数据文件: " << customerDataFile << endl;
    }
}

// 函数:去除字符串两端的空白字符
// @param str: 需要处理的字符串
// @param whitespace: 定义为空白字符的字符集,默认包括空格、制表符、换行符等
// @return: 去除两端空白字符后的字符串
string trim(const string& str, const string& whitespace = " \t\n\r\f\v")
{
    // 找到第一个非空白字符的位置
    const auto strBegin = str.find_first_not_of(whitespace);
    
    // 如果整个字符串都是空白字符,返回空字符串
    if (strBegin == string::npos)
        return "";

    // 找到最后一个非空白字符的位置
    const auto strEnd = str.find_last_not_of(whitespace);
    
    // 计算非空白字符串的长度
    const auto strRange = strEnd - strBegin + 1;
    
    // 返回去除两端空白字符后的子字符串
    return str.substr(strBegin, strRange);
}


// 用于从用户获取日期范围
    pair<chrono::system_clock::time_point, chrono::system_clock::time_point> shopSystem::getDateRangeFromUser()
    {
        // 假设用户输入格式为 YYYY-MM-DD
        string startDateStr, endDateStr;
        cout << "请输入起始日期 (YYYY-MM-DD): ";
        cin >> startDateStr;
        cout << "请输入结束日期 (YYYY-MM-DD): ";
        cin >> endDateStr;

        // 将字符串转换为time_t（需要错误处理）
        tm startDateTM = {}, endDateTM = {};
        istringstream startDateISS(startDateStr), endDateISS(endDateStr);
        startDateISS >> get_time(&startDateTM, "%Y-%m-%d");
        endDateISS >> get_time(&endDateTM, "%Y-%m-%d");

        // 将time_t转换为system_clock::time_point
        auto startDate = chrono::system_clock::from_time_t(mktime(&startDateTM));
        auto endDate = chrono::system_clock::from_time_t(mktime(&endDateTM));

        // 确保起始日期在结束日期之前或相等
        if (startDate > endDate)
        {
            swap(startDate, endDate);
        }

        return {startDate, endDate};
    }


    // 函数，用于打印时间段内的购买记录
    void shopSystem::printPurchaseRecords(const string& customerName, const pair<chrono::system_clock::time_point, chrono::system_clock::time_point>& dateRange)
    {
        auto iter = customerHistory.find(customerName);
        if (iter != customerHistory.end())
        {
            for (const auto& record : iter->second)
            {
                if (record.second.second.second >= dateRange.first && record.second.second.second <= dateRange.second)
                {
                    time_t time_t_value = std::chrono::system_clock::to_time_t(record.second.second.second);
                    cout << "商品名称: " << record.second.first.getGoodName()
                         << ", 购买数量: " << record.second.second.first
                         << ", 购买金额: " << record.first
                         << ", 购买时间: " << put_time(localtime(&time_t_value), "%Y-%m-%d %H:%M:%S")
                         << endl;
                }
            }
        }
        else
        {
            cout << "没有找到顾客 " << customerName << " 的购买记录。" << endl;
        }
    }
