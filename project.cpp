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
string login = "admin";//����Ա�˺�
string password = "123456";//����Ա����
static int Isint()
{
    int n;
    while (1)
    {
        cin >> n;
        if (cin.get() != '\n')
            cout << "�������ݲ������ͣ�����������:" << endl;
        else
            break;
        string ch;
        cin >> ch;
        //������������

    }
    return n;
}
class visiter {
public:
    string vehicle_owner;   //����
    string vehicle;         //���ƺ�
    int visiting_flat;      //��Ԣ���
    string pass;            //����
    time_t start, finish;   //ͣ�����뿪ʱ��
    float exiting_visiter()
    {
        time(&finish);

        double diff=difftime(finish, start);
        //����ͣ��ʱ��

        cout << "ͣ��ʱ�� = " << diff << "��" << endl;
        cout << "������ÿСʱ10Ԫ" << endl;
        return diff * 10  / 3600;
    }
};
class flat {
private:
    float electricity_balance;   //���
    
public:
    int flat_no;          //��Ԣ���
    string passcode;      //����
    string name_of_owner; //������
    int size_of_family;   //��ͥ�˿�
    int flat_area;        //���
    void install()
    {
        cout << "��������Ĺ�Ԣ����:" << endl;
        flat_no = Isint();

        cout << "�������������:" << endl;
        cin >> name_of_owner;

        cout << "�������ס����:" << endl;
        size_of_family = Isint();

        cout << "��������Ĺ�Ԣ��С��ƽ���ף�:" << endl;
        flat_area = Isint();

        cout << "���������룺" << endl;
        cin >> passcode;

        electricity_balance = 0;
        cout << "��ӭ������������:" << name_of_owner << endl;
    }
    void PayTheBill()
    {
        int AddMoney;
        cout << "�����������ֵ�Ľ��(����):" << endl;
        AddMoney=Isint();

        if (AddMoney > 0)
        {
            if (electricity_balance + AddMoney < 1000000) //���������
                electricity_balance += AddMoney;
            else
                cout << "��ֵ�������ֵ����ֵʧ��" << endl;
        }
        else
        {
            cout << "������һ����Ч�Ľ�" << endl;
        }
        
        cout << "�㵱ǰ�������:" << electricity_balance << "Ԫ" << endl;
    }

    void showYourDetails()
    {
        cout << "���� :" << name_of_owner << endl;
        cout << "��Ԣ��С:" << flat_area <<"ƽ����" << endl;
        cout << "��ס����: " << size_of_family << endl;
        cout << "���: " << electricity_balance << "Ԫ" << endl;
        
    }
    void visiting_charges(float c)
    {
        electricity_balance = electricity_balance - c;
        cout  << "�ӹ�Ԣ���Ϊ��"<< flat_no <<"�˻��п۳��ÿ͵�ͣ����: "<< c << endl;
        cout << "�㵱ǰ�������:" << electricity_balance << "Ԫ" << endl;
    }
    void shop()
    {
        float price[5] = { 20,15,5,25,1 };
        cout << "���� 0 ���� : 20Ԫ" << endl;
        cout << "���� 1 ������� : 15Ԫ" << endl;
        cout << "���� 2 ���� : 5Ԫ" << endl;
        cout << "���� 3 �մ�ˮ 250ml : 25Ԫ" << endl;
        cout << "���� 4 �ǹ� : 1Ԫ" << endl;
        float total_bill = 0.0;
        int a = 1;
        queue<int>shopping_list;
        int choice;
        int quantity;
        for (int i = 0; a == 1; i++)
        {
            cout << "ѡ������Ҫ����Ʒ���빺�ﳵ: " << endl;
            while (1)
            {
                choice = Isint();
                if (choice >= 0 && choice <= 4)
                    break;
                cout << "�����������������0-4֮���ֵ:" << endl;
            }
            cout << "����������: " << endl;
            cin >> quantity;
            float cost = price[choice] * quantity;
            shopping_list.push(cost);
            cout << "���� 1 ��������������������˳���֧���˵�" << endl;
            cin >> a;
        }
        while (!shopping_list.empty())
        {
            total_bill = total_bill + shopping_list.front();
            shopping_list.pop();
            //�������˵�
        }
        cout << "�˵��ܶ�:" << total_bill << endl;
        cout << "�������������" << endl;
        string passc;   //����
        cin >> passc;
        if (passc == passcode && electricity_balance >= total_bill)
        {
            electricity_balance = electricity_balance - total_bill;
            cout << "֧���ɹ�" << endl;
            cout << "|| ����Ѵ�����˻��۳� ||" << endl;

        }
        else
        {
            cout << "����ʧ��:�����������������" << endl;
        }
    }
};

int main()
{
    
    system("Color A9");
    cout << setw(75) << "*******************************************" << endl;
    cout << setw(60) << "��������" << endl;
    cout << setw(75) << "*******************************************" << endl;
    int choose;
    flat arr[100];      //��Ԣ
    visiter vis[20];    //ͣ��λ
    int p = 0;
    int a = 0;
    int v = 0;
    while (a == 0)
    {
        cout << "���� 1 :��ס����" << endl;
        cout << "���� 2 :��ֵ���" << endl;
        cout << "���� 3 :�鿴��ס����" << endl;
        cout << "���� 4 :��������" << endl;
        cout << "���� 5 :�뿪����" << endl;
        cout << "���� 6 :�̵깺��" << endl;
        cout << "���� 7 :�˳�ϵͳ" << endl;
        cout << "���������ѡ��:" << endl;
        choose = Isint();
        switch (choose)
        {
        case 1:
            arr[p].install();
            //����һ����Ԣ��Ϣ
            arr[p].showYourDetails();
            //����������Ĺ�Ԣ��Ϣ
            p++;
            break;

        case 2:
            
            int id;
            cout << "��������Ĺ�Ԣ���:" << endl;
            id = Isint();
            for (int g = 0; g <= p - 1; g++)
            {
                if (arr[g].flat_no == id)
                {
                    arr[g].PayTheBill();
                    //��ѳ�ֵ
                    arr[g].showYourDetails();
                    //�����ֵ��Ĺ�Ԣ��Ϣ
                }
                else
                {
                    cout << "��ֵʧ�ܣ�δ�ҵ��ù�Ԣ" << endl;
                }
            }
            break;
        case 3:
        {
            cout << "�Թ���Ա��ݵ�¼:" << endl;
            cout << "�˺�: " << endl;
            string log;
            cin >> log;
            cout << "����: " << endl;
            string pa;
            cin >> pa;
            if (login == log && password ==pa )
            {
                //������й�Ԣ����Ϣ
                for (int i = 0; i < p; i++)
                {
                    arr[i].showYourDetails();
                    cout << "<--------------------------->" << endl;
                }
                
            }
            else {
                cout<<"�˺Ż��������" << endl;
            }

            break;
        }
        case 4:
        {
            //vis[v].entering_visiter();
            
            cout << "�������:" << endl;
            cin >> vis[v].vehicle_owner;
            cout << "��ĳ��ƺ�:" << endl;
            cin >> vis[v].vehicle;
            cout << "��������Ĺ�Ԣ���:" << endl;
            vis[v].visiting_flat = Isint();
            cout << "����������:" << endl;
            cin >> vis[v].pass;
            int i;
            for (i = 0; i <= p - 1; i++)
            {
                //��֤��Ԣ��ź�����
                if (arr[i].flat_no == vis[v].visiting_flat)
                    if(arr[i].passcode == vis[v].pass)
                    break;
            }
            if (i >= p)
            {
                cout << "δ�ҵ��ù�Ԣ���������" << endl;
            }
            else
            {
                time(&vis[v].start);
                //��ʼ��ʱ
                cout << setw(20) << "|||||��ӭ������������|||||" << endl;
                v++;
            }
            break;
        }
        case 5:
        {
            int f;        //��Ԣ���
            string pa;    //����
            int w;
            string vehi;  //���ƺ�
            cout << "����������ʵĹ�Ԣ:" << endl;
            f = Isint();
            cout << "����������:" << endl;
            cin >> pa;
            //��֤��Ԣ��ź�����
            for (w = 0; w < p; w++)
            {
                if (f == arr[w].flat_no)
                {
                    //�޷���Ӧֱ���˳�
                    if (pa != arr[w].passcode)
                    {
                        w = v;
                        break;
                    }
                    int n;
                    float cost=0;   //����
                    cout << "������Ҫ�뿪�ĳ��ƺ�:" << endl;
                    cin >> vehi;
                    for (n = 0; n < v; n++)
                    {
                        //��֤�����빫Ԣ��Ϣ�Ƿ�ƥ��
                        if (vehi == vis[n].vehicle)
                            if (arr[w].flat_no == vis[n].visiting_flat)
                                if (arr[w].passcode == vis[n].pass)
                                    break;
                    }
                    if (n < v)
                    {
                        cost = vis[n].exiting_visiter();
                        //����ͣ������
                        arr[w].visiting_charges(cost);
                        //�۳�ͣ����

                        //���ͣ����¼
                        while (n < v )
                        {
                            vis[n] = vis[n + 1];
                            n++;
                        }
                    }
                    else
                    {
                        cout << "δ�ҵ��ó�" << endl;
                    }
                    
                    
                     
                    
                    
                }
                
            }
            if (w > v - 1)
            {   
                cout << "�ù�Ԣδͣ�����������" << endl;
            }   
            for (; w < v; w++)
            {
                vis[w] = vis[w + 1];
            }
            
            break;
        }
        case 6:
            cout << "�ӻ���" << endl;
            cout << "��������Ĺ�Ԣ���:" << endl;
            int f_number;   //��Ԣ���
           
            f_number = Isint();
            
            for (int k = 0; k <= p - 1; k++)
            {
                if (f_number == arr[k].flat_no)
                {
                    cout << "��ӭ" << arr[k].name_of_owner << endl;
                    arr[k].shop();
                    //��ʼ����
                }
            }
            break;
        case 7:
            a = 1;
            //�˳�ϵͳ
            break;
        default:
            cout << "�밴Ҫ������" << endl;
            break;
        }
        
    }
    cout << "ϵͳ���˳����ټ�!!" << endl;
    system("pause");
    return 0;
}