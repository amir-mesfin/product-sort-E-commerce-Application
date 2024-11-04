selectionSortByRating#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    string name;
    float rating;

    Product(string n, float r) : name(n), rating(r) {}
};

void selectionSortByRating(vector<Product>& products) {
    for (size_t i = 0; i < products.size() - 1; i++) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < products.size(); j++) {
            if (products[j].rating > products[maxIndex].rating) {
                maxIndex = j;
            }
        }
        swap(products[i], products[maxIndex]);
    }
}

void displayProducts(const vector<Product>& products) {
    for (const auto& product : products) {
        cout << "Name: " << product.name << ", Rating: " << product.rating << " stars" << endl;
    }
}

int main() {
    vector<Product> products = {
        Product("Laptop", 4.7),
        Product("Phone", 4.5),
        Product("Headphones", 4.6),
        Product("Camera", 4.4)
    };

    selectionSortByRating(products);
    cout << "Products sorted by Rating:\n";
    displayProducts(products);

    return 0;
}