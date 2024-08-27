#include <iostream>
using namespace std;
class GST;
class Product 
{
    private:
        string product_name;
        double product_price;
    public:
        Product(string n= "hello", double p=0): product_name(n), product_price(p){};
        void setprice(double p) 
        {
            product_price = p;
        }
        void setn(string n) 
        {
            product_name = n;
        }
        string getn() 
        {
            return product_name;
        }
        double getp() 
        {
            return product_price;
        }
        friend void finalPrice(Product, GST);
};
class GST 
{
    private:
        double gst_rate;

    public:
        
        GST(double a=0):gst_rate(a){};
        void setg(double a) 
        {
            gst_rate = a;
        }
        double getg() {
            return gst_rate;
        }
        friend void finalPrice(Product, GST);
};
void finalPrice(Product p, GST g) 
{
    double tp = p.getp() + (p.getp() * g.getg() / 100);
    cout << "Product Name Is: " << p.getn() << endl;
    cout << "Total Price Is : " << tp << endl;
}
int main() 
{
    string product_name;
    double product_price, gst_rate;
    cout << "Enter product name: ";
    cin >> product_name;
    cout << "Enter product price: ";
    cin >> product_price;
    cout << "Enter GST rate: ";
    cin >> gst_rate;
    Product p(product_name, product_price);
    GST g(gst_rate);
    finalPrice(p, g);
    return 0;
}