#include<iostream>
#include<cstring>
#include<string>
#include <stdlib.h>
#include<iomanip>
#include<dos.h>
#include <ctime>
#include<queue>
#include<vector>
using namespace std;
string login = "admin";//管理员账号
string password = "123456";//管理员密码
static int Isint()
{
    int n;
    while (1)
    {
        cin >> n;
        if (cin.get() != '\n')
            cout << "输入数据不是整型，请重新输入:" << endl;
        else
            break;
        string ch;
        cin >> ch;
        //清除多余的数据

    }
    return n;
}
class visiter {
public:
    string vehicle_owner;   //车主
    string vehicle;         //车牌号
    int visiting_flat;      //公寓编号
    string pass;            //密码
    time_t start, finish;   //停车与离开时间
    float exiting_visiter()
    {
        time(&finish);

        double diff=difftime(finish, start);
        //计算停车时间

        cout << "停车时间 = " << diff << "秒" << endl;
        cout << "费用是每小时10元" << endl;
        return diff * 10  / 3600;
    }
};
class flat {
private:
    float electricity_balance;   //电费
    
public:
    int flat_no;          //公寓编号
    string passcode;      //密码
    string name_of_owner; //所有者
    int size_of_family;   //家庭人口
    int flat_area;        //面积
    void install()
    {
        cout << "请输入你的公寓编码:" << endl;
        flat_no = Isint();

        cout << "请输入你的姓名:" << endl;
        cin >> name_of_owner;

        cout << "请输入居住人数:" << endl;
        size_of_family = Isint();

        cout << "请输入你的公寓大小（平方米）:" << endl;
        flat_area = Isint();

        cout << "请输入密码：" << endl;
        cin >> passcode;

        electricity_balance = 0;
        cout << "欢迎来到生活社区:" << name_of_owner << endl;
    }
    void PayTheBill()
    {
        int AddMoney;
        cout << "请输入你想充值的金额(整数):" << endl;
        AddMoney=Isint();

        if (AddMoney > 0)
        {
            if (electricity_balance + AddMoney < 1000000) //限制最大金额
                electricity_balance += AddMoney;
            else
                cout << "充值金额超过最大值，充值失败" << endl;
        }
        else
        {
            cout << "请输入一个有效的金额：" << endl;
        }
        
        cout << "你当前的余额是:" << electricity_balance << "元" << endl;
    }

    void showYourDetails()
    {
        cout << "姓名 :" << name_of_owner << endl;
        cout << "公寓大小:" << flat_area <<"平方米" << endl;
        cout << "居住人数: " << size_of_family << endl;
        cout << "余额: " << electricity_balance << "元" << endl;
        
    }
    void visiting_charges(float c)
    {
        electricity_balance = electricity_balance - c;
        cout  << "从公寓编号为的"<< flat_no <<"账户中扣除访客的停车费: "<< c << endl;
        cout << "你当前的余额是:" << electricity_balance << "元" << endl;
    }
    void shop()
    {
        float price[5] = { 20,15,5,25,1 };
        cout << "输入 0 面条 : 20元" << endl;
        cout << "输入 1 意大利面 : 15元" << endl;
        cout << "输入 2 鸡蛋 : 5元" << endl;
        cout << "输入 3 苏打水 250ml : 25元" << endl;
        cout << "输入 4 糖果 : 1元" << endl;
        float total_bill = 0.0;
        int a = 1;
        queue<int>shopping_list;
        int choice;
        int quantity;
        for (int i = 0; a == 1; i++)
        {
            cout << "选择你想要的商品加入购物车: " << endl;
            while (1)
            {
                choice = Isint();
                if (choice >= 0 && choice <= 4)
                    break;
                cout << "输入错误，请重新输入0-4之间的值:" << endl;
            }
            cout << "请输入数量: " << endl;
            cin >> quantity;
            float cost = price[choice] * quantity;
            shopping_list.push(cost);
            cout << "输入 1 继续购物，输入任意整数退出并支付账单" << endl;
            cin >> a;
        }
        while (!shopping_list.empty())
        {
            total_bill = total_bill + shopping_list.front();
            shopping_list.pop();
            //计算总账单
        }
        cout << "账单总额:" << total_bill << endl;
        cout << "请输入你的密码" << endl;
        string passc;   //密码
        cin >> passc;
        if (passc == passcode && electricity_balance >= total_bill)
        {
            electricity_balance = electricity_balance - total_bill;
            cout << "支付成功" << endl;
            cout << "|| 金额已从你的账户扣除 ||" << endl;

        }
        else
        {
            cout << "购物失败:你的余额不足或者密码错误" << endl;
        }
    }
};

int main()
{
    
    system("Color A9");
    cout << setw(75) << "*******************************************" << endl;
    cout << setw(60) << "生活社区" << endl;
    cout << setw(75) << "*******************************************" << endl;
    int choose;
    flat arr[100];      //公寓
    visiter vis[20];    //停车位
    int p = 0;
    int a = 0;
    int v = 0;
    while (a == 0)
    {
        cout << "输入 1 :入住社区" << endl;
        cout << "输入 2 :充值余额" << endl;
        cout << "输入 3 :查看居住详情" << endl;
        cout << "输入 4 :进入社区" << endl;
        cout << "输入 5 :离开社区" << endl;
        cout << "输入 6 :商店购物" << endl;
        cout << "输入 7 :退出系统" << endl;
        cout << "请输入你的选择:" << endl;
        choose = Isint();
        switch (choose)
        {
        case 1:
            arr[p].install();
            //创建一个公寓信息
            arr[p].showYourDetails();
            //输出所创建的公寓信息
            p++;
            break;

        case 2:
            
            int id;
            cout << "请输入你的公寓编号:" << endl;
            id = Isint();
            for (int g = 0; g <= p - 1; g++)
            {
                if (arr[g].flat_no == id)
                {
                    arr[g].PayTheBill();
                    //电费充值
                    arr[g].showYourDetails();
                    //输出充值后的公寓信息
                }
                else
                {
                    cout << "充值失败，未找到该公寓" << endl;
                }
            }
            break;
        case 3:
        {
            cout << "以管理员身份登录:" << endl;
            cout << "账号: " << endl;
            string log;
            cin >> log;
            cout << "密码: " << endl;
            string pa;
            cin >> pa;
            if (login == log && password ==pa )
            {
                //输出所有公寓的信息
                for (int i = 0; i < p; i++)
                {
                    arr[i].showYourDetails();
                    cout << "<--------------------------->" << endl;
                }
                
            }
            else {
                cout<<"账号或密码错误" << endl;
            }

            break;
        }
        case 4:
        {
            //vis[v].entering_visiter();
            
            cout << "你的姓名:" << endl;
            cin >> vis[v].vehicle_owner;
            cout << "你的车牌号:" << endl;
            cin >> vis[v].vehicle;
            cout << "请输入你的公寓编号:" << endl;
            vis[v].visiting_flat = Isint();
            cout << "请输入密码:" << endl;
            cin >> vis[v].pass;
            int i;
            for (i = 0; i <= p - 1; i++)
            {
                //验证公寓编号和密码
                if (arr[i].flat_no == vis[v].visiting_flat)
                    if(arr[i].passcode == vis[v].pass)
                    break;
            }
            if (i >= p)
            {
                cout << "未找到该公寓或密码错误" << endl;
            }
            else
            {
                time(&vis[v].start);
                //开始计时
                cout << setw(20) << "|||||欢迎来到生活社区|||||" << endl;
                v++;
            }
            break;
        }
        case 5:
        {
            int f;        //公寓编号
            string pa;    //密码
            int w;
            string vehi;  //车牌号
            cout << "请输入你访问的公寓:" << endl;
            f = Isint();
            cout << "请输入密码:" << endl;
            cin >> pa;
            //验证公寓编号和密码
            for (w = 0; w < p; w++)
            {
                if (f == arr[w].flat_no)
                {
                    //无法对应直接退出
                    if (pa != arr[w].passcode)
                    {
                        w = v;
                        break;
                    }
                    int n;
                    float cost=0;   //费用
                    cout << "请输入要离开的车牌号:" << endl;
                    cin >> vehi;
                    for (n = 0; n < v; n++)
                    {
                        //验证车牌与公寓信息是否匹配
                        if (vehi == vis[n].vehicle)
                            if (arr[w].flat_no == vis[n].visiting_flat)
                                if (arr[w].passcode == vis[n].pass)
                                    break;
                    }
                    if (n < v)
                    {
                        cost = vis[n].exiting_visiter();
                        //计算停车费用
                        arr[w].visiting_charges(cost);
                        //扣除停车费

                        //清除停车记录
                        while (n < v )
                        {
                            vis[n] = vis[n + 1];
                            n++;
                        }
                    }
                    else
                    {
                        cout << "未找到该车" << endl;
                    }
                    
                    
                     
                    
                    
                }
                
            }
            if (w > v - 1)
            {   
                cout << "该公寓未停车或密码错误" << endl;
            }   
            for (; w < v; w++)
            {
                vis[w] = vis[w + 1];
            }
            
            break;
        }
        case 6:
            cout << "杂货店" << endl;
            cout << "请输入你的公寓编号:" << endl;
            int f_number;   //公寓编号
           
            f_number = Isint();
            
            for (int k = 0; k <= p - 1; k++)
            {
                if (f_number == arr[k].flat_no)
                {
                    cout << "欢迎" << arr[k].name_of_owner << endl;
                    arr[k].shop();
                    //开始购物
                }
            }
            break;
        case 7:
            a = 1;
            //退出系统
            break;
        default:
            cout << "请按要求输入" << endl;
            break;
        }
        
    }
    cout << "系统已退出，再见!!" << endl;
    system("pause");
    return 0;
}