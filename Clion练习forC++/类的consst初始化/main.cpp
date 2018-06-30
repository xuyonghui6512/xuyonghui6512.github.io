#include <iostream>
using namespace std;
class CBook {
public:
    double m_price;

    CBook(double price) : m_price(8.8) { }
   CBook() {
        CBook(8.8);
    }
};
class A {
public:
    A();
    ~A(){}
   virtual void funa();
  virtual void funb();
    void func();
    static void fund();
  //  static int si;
private:

   int i;
    double b;
    char c;
};
int main() {
    CBook c;
    //A a;
    cout << c.m_price <<"  "<<sizeof(A)<< endl; // 此时并不会输出理想中的8.8
}