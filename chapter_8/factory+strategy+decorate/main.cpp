#include <iostream>
#include <string>
#include <memory>
#include <cmath>

using namespace std;
class Sale
{
public:
    virtual double acceptCash(double price, int num) = 0;
    virtual ~Sale() = default;
};

class CashSuper: public Sale
{
public:
    void decorate(Sale *c) { component.reset(c); }
    double acceptCash(double price, int num) override
    {
        double result = 0;
        if (this->component != nullptr)
            result = this->component->acceptCash(price, num);
        return result;
    }
protected:
    shared_ptr<Sale> component;
};  

class CashNormal: public Sale
{
public:
    double acceptCash(double price, int num) override { return price * num;}
};

class CashRebate: public CashSuper
{
public: 
    CashRebate(double moneyRebate): moneyRebate(moneyRebate) {}
    double acceptCash(double price, int num) override
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
    double acceptCash(double price, int num) override
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

class Factory
{
public:
    virtual shared_ptr<Sale> createSalesMode() = 0;
    virtual ~Factory() = default;

protected:
    shared_ptr<Sale> cn;
    CashSuper* cr1 = nullptr;
    CashSuper* cr2 = nullptr;
};

class CashRebateReturnFactory: public Factory
{
public:
    CashRebateReturnFactory(double moneyRebate, double moneyCondition, double moneyReturn): 
        moneyRebate(moneyRebate), moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
    shared_ptr<Sale> createSalesMode() override
    {
        cr1 = new CashReturn(moneyCondition, moneyReturn);
        cr2 = new CashRebate(moneyRebate);

        cr1->decorate(new CashNormal);
        cr2->decorate(cr1);
        cn.reset(cr2);
        return cn;
    }

private:
    double moneyRebate = 1;
    double moneyCondition = 0;
    double moneyReturn = 0;
};

class CashReturnRebateFactory: public Factory
{
public:
    CashReturnRebateFactory(double moneyRebate, double moneyCondition, double moneyReturn):
        moneyCondition(moneyCondition), moneyReturn(moneyReturn), moneyRebate(moneyRebate) {}
    
    shared_ptr<Sale> createSalesMode() override
    {
        cr1 = new CashRebate(moneyRebate);
        cr2 = new CashReturn(moneyCondition, moneyReturn);
        
        cr1->decorate(new CashNormal);
        cr2->decorate(cr1);
        cn.reset(cr2);
        return cn;
    }

private:
    double moneyRebate = 1;
    double moneyCondition = 0;
    double moneyReturn = 0;
};

class CashContext
{
public:
    CashContext(int CashType)
    {
        switch(CashType)
        {
            case 1:
            fs = make_shared<CashRebateReturnFactory>(1, 1, 0); break;
            case 2:
            fs = make_shared<CashReturnRebateFactory>(0.8, 1, 0); break;
            case 3:
            fs = make_shared<CashRebateReturnFactory>(0.7, 1, 0); break;
            case 4:
            fs = make_shared<CashReturnRebateFactory>(1, 300, 100); break;
            case 5:
            fs = make_shared<CashReturnRebateFactory>(0.8, 300, 100); break;
            case 6:
            fs = make_shared<CashRebateReturnFactory>(0.7, 200, 50); break;
        }
        cs = fs->createSalesMode();
    }

    double getResult(double price, int num) { return cs->acceptCash(price, num); }

private:
    shared_ptr<Sale> cs;
    shared_ptr<Factory> fs;
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