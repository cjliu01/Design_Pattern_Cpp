#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Scale
{
public:
    virtual double acceptCash(double price, int num) = 0;
};

class CashSuper: public Scale
{
public:
    void decorate(Scale *component) { this->component = component; }
    double acceptCash(double price, int num) 
    {
        double result = 0;
        if (this->component != 0)
            result = this->component->acceptCash(price, num);
        return result;
    }
protected:
    Scale *component = 0;
};  

class CashNormal: public Scale
{
public:
    double acceptCash(double price, int num) { return price * num;}
};

class CashRebate: public CashSuper
{
public: 
    CashRebate(double moneyRebate): moneyRebate(moneyRebate) {}
    double acceptCash(double price, int num)
    {
        double result = price * num * moneyRebate;
        return CashSuper::acceptCash(result, 1);
    }
private:
    double moneyRebate = 1;
};

class CashReturn: public CashSuper
{
public:
    CashReturn(double moneyCondition, double moneyReturn): moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
    double acceptCash(double price, int num)
    {
        double result = price * num;
        if (moneyCondition > 0 && result >= moneyCondition)
            result -= floor(result / moneyCondition) * moneyReturn;
        return CashSuper::acceptCash(result, 1);
    }
private:
    double moneyCondition = 0;
    double moneyReturn = 0;
};

class CashContext
{
private:
    Scale *cs = 0;
    Scale *cn = 0;
    CashSuper *cr1 = 0;
    CashSuper *cr2 = 0;
public:
    CashContext(int cashType)
    {
        switch(cashType)
        {
            case 1: cs = new CashNormal; break;
            case 2: cn = new CashNormal; cr2 = new CashRebate(0.8); cr2->decorate(cn); cs = cr2; break;
            case 3: cn = new CashNormal; cr2 = new CashRebate(0.7); cr2->decorate(cn); cs = cr2; break; 
            case 4: cn = new CashNormal; cr2 = new CashReturn(300, 100); cr2->decorate(cn); cs = cr2; break;  
            case 5: 
                {
                    cn = new CashNormal;
                    cr1 = new CashRebate(0.8);
                    cr2 = new CashReturn(300, 100);

                    cr1->decorate(cn);
                    cr2->decorate(cr1);
                    this->cs = cr2;
                    break;
                }
            case 6:
                {
                    cn = new CashNormal;
                    cr1 = new CashReturn(200, 50);
                    cr2 = new CashRebate(0.7);

                    cr1->decorate(cn);
                    cr2->decorate(cr1);
                    this->cs = cr2;
                    break;
                }
        }
    }
    ~CashContext() 
    { 
        delete cn;
        delete cr1;
        delete cr2;
        if (cs != cn && cs != cr1 && cs != cr2) 
            delete cs;  //防止重复删除
    }
    double getResult(double price, int num) { return cs->acceptCash(price, num); }
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
        cout << "请输入商品销售模式 1.原价 2.八折 3.七折 4.满300返100 5.满300返100后八折 6.七折后满200返50: ";
        cin >> discount;
        cout << "请输入商品单价: ";
        cin >> price;
        cout << "请输入商品数量: ";
        cin >> num;
        if (price > 0 && num > 0)
        {
            CashContext cc(discount);
            totalPrice = cc.getResult(price, num);
            total += totalPrice;

            cout << "单价: " << price << "元 数量: " << num 
                << "合计: " << totalPrice << "元" << endl;
            cout << "总计: " << total << "元" << endl;
        }
    } while (price > 0 && num > 0);
    return  0;
}