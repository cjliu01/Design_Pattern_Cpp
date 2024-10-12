#include <iostream>
#include <cmath>
#include <memory>

using namespace std;

class CashSuper
{
public:
    virtual double acceptCash(double price, int num) = 0;
    virtual ~CashSuper() = default;
};

class CashNormal: public CashSuper
{
public:
    double acceptCash(double price, int num) override { return price * num; }
};

class CashRebate: public CashSuper
{
public:
    CashRebate(double MoneyRebate): moneyRebate(MoneyRebate) {}
    double acceptCash(double price, int num) override { return price * num * moneyRebate; }

private:
    double moneyRebate;
};

class CashReturn: public CashSuper
{
public:
    CashReturn(double moneyCondition, double moneyReturn): moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
    double acceptCash(double price, int num) override
    {
        double result = price * num;
        if (moneyCondition > 0 && result >= moneyCondition) 
            result -= floor(result / moneyCondition) * moneyReturn;
        return result; 
    }

private:
    double moneyCondition;
    double moneyReturn;
};

class CashFactory
{
public:
    static shared_ptr<CashSuper> createCashAccept(int cashType)
    {
        CashSuper* cs = nullptr;
        switch(cashType)
        {
            case 1: cs = new CashNormal(); break;
            case 2: cs = new CashRebate(0.8); break;
            case 3: cs = new CashRebate(0.7); break;
            case 4: cs = new CashReturn(300, 100); break;
        }
        return shared_ptr<CashSuper>(cs);
    }
};

int main()
{
    double price = 0;
    int discount = 0;
    int num = 0;
    double totalPrice = 0;
    double total = 0;
    do
    {
        cout << "请输入商品销售模式 1.原价 2.八折 3.七折 4.满300返100:";
        cin >> discount;
        cout << "请输入商品单价: ";
        cin >> price;
        cout << "请输入商品数量: ";
        cin >> num;
        if (price > 0 && num > 0)
        {
            shared_ptr<CashSuper> cs = CashFactory::createCashAccept(discount);
            totalPrice = cs->acceptCash(price, num);
            total += totalPrice;

            cout << "单价: " << price << "元 数量: " << num 
                << " 合计: " << totalPrice << "元" << endl;
            cout << "总计: " << total << "元" << endl;
        }
    } while (price > 0 && num > 0);
    return  0;
}