#include <string>

using namespace std;

class Stock {
private:
    int code = 0;
    string name = " ";
    int quantity = 0;
    float price = 0;

public:

    int getCode() const {
        return code;
    }

    void setCode(int code) {
        Stock::code = code;
    }

    const string getName() const {
        return name;
    }

    void setName(const string name) {
        Stock::name = name;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        Stock::quantity = quantity;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        Stock::price = price;
    }

};


