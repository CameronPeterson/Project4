#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Product {
private:
    string name;
    int id {-1};
    double price {-1};
    int num_sold {-1};
public:
    Product (string, int, double, int);
    void printAll();
    int numSold();
    double sales();
};

void sortBySales(Product product[], int);
int totalSold(Product *product, int NUM_PRODUCTS);
double totalSales(Product *product, int NUM_PRODUCTS);

// Used with setw()
const int NAME_WIDTH {12};
const int ID_WIDTH {8};
const int PRICE_WIDTH {8};
const int NUM_SOLD_WIDTH {8};
const int SALES_WIDTH {12};

Product::Product(string new_name, int new_id,
                 double new_price, int new_num_sold) {
    name = new_name;
    id = new_id;
    price = new_price;
    num_sold = new_num_sold;
};

int main() {

    const int NUM_PRODUCTS = 15;

    Product product[NUM_PRODUCTS] {{"Apple", 4129, 2.52, 1492},
                                   {"Orange", 4381, 3.12, 831},
                                   {"Banana", 4011, 2.99, 1538},
                                   {"Watermelon", 3308, 4.15, 172},
                                   {"Parsnip", 4672, 1.99, 342},
                                   {"Peach", 4400, 3.50, 649},
                                   {"Mango", 3365, 4.20, 210},
                                   {"Onion", 4093, 1.57, 794},
                                   {"Pear", 4553, 2.40, 402},
                                   {"Plum", 4437, 3.90, 393},
                                   {"Blueberry", 3210, 5.50, 2102},
                                   {"Potato", 4102, 1.20, 1403},
                                   {"Rhubarb", 1031, 2.30, 1021},
                                   {"Melon", 2210, 2.22, 399},
                                   {"Stardew", 7777, 6.80, 5}};

    sortBySales(product, NUM_PRODUCTS);

    cout << setw(NAME_WIDTH) << "Name" << setw(ID_WIDTH) << "ID"
    << setw(PRICE_WIDTH) << "Price" << setw(NUM_SOLD_WIDTH) << "# Sold"
    << setw(SALES_WIDTH) << "Sales" << endl
         << "___________________________________________________________" << endl;

    for (int i {0}; i < NUM_PRODUCTS; i++) {
        product[i].printAll();
        cout << endl;
    }

    cout << endl;
    cout << "The total number sold is " << totalSold(product, NUM_PRODUCTS) << endl;
    cout << "The total sales is " << totalSales(product, NUM_PRODUCTS);

    return 0;
}

void Product::printAll() {
    cout << setprecision(2) << fixed;
    cout << setw(NAME_WIDTH) << name;
    cout << setw(ID_WIDTH) << id;
    cout << setw(PRICE_WIDTH) << price;
    cout << setw(NUM_SOLD_WIDTH) << num_sold;
    cout << setw(SALES_WIDTH) << num_sold * price;
}

double Product::sales() {
    return price * num_sold;
}

int Product::numSold() {
    return num_sold;
}

void sortBySales(Product *product, const int NUM_PRODUCTS) {
    bool swap;
    Product temp{"", 0, 0, 0};

    do {
        swap = false;
        for (int i = 0; i < NUM_PRODUCTS - 1; i++) {
            if (product[i].sales() > product[i + 1].sales()) {
                temp = product[i];
                product[i] = product[i + 1];
                product[i + 1] = temp;
                swap = {true};
            }
        }
    } while (swap);
}

int totalSold(Product *product, const int NUM_PRODUCTS) {
    int total {-1};
    for (int i {0}; i < NUM_PRODUCTS; i++) {
        total += product[i].numSold();
    }
    return total;
}

double totalSales(Product *product, const int NUM_PRODUCTS) {
    int total {-1};
    for (int i {0}; i < NUM_PRODUCTS; i++) {
        total += product[i].sales();
    }
    return total;
}