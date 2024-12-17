
# product-sort-E-commerce-Application

#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
string name;
float price;

    Product(string n, float p) : name(n), price(p) {}

};

void bubbleSortByPrice(vector<Product>& products) {
for (size_t i = 0; i < products.size() - 1; i++) {
for (size_t j = 0; j < products.size() - i - 1; j++) {
if (products[j].price > products[j + 1].price) {
swap(products[j], products[j + 1]);
}
}
}
}

void displayProducts(const vector<Product>& products) {
for (const auto& product : products) {
cout << "Name: " << product.name << ", Price: $" << product.price << endl;
}
}

int main() {
vector<Product> products = {
Product("Laptop", 1200.99),
Product("Phone", 799.49),
Product("Headphones", 199.99),
Product("Camera", 500.50)
};

    bubbleSortByPrice(products);
    cout << "Products sorted by Price:\n";
    displayProducts(products);

    return 0;

}

