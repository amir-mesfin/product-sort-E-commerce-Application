Yene Class, [04/11/2024 19:45]
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::swap
#include <ctime>     // for time()
using namespace std;

class Product {
public:
    string name;
    float price;
    float rating;
    int stock;
    float discount;
    time_t timestamp; // Assuming this is used for something
    int reviews;
    string brand;
    float weight;
    string category;
    int sales;

    Product(string n, float p, float r, int s, float d, time_t t, int rev, string b, float w, string c, int sa)
        : name(n), price(p), rating(r), stock(s), discount(d), timestamp(t), reviews(rev), brand(b), weight(w), category(c), sales(sa) {}
};

// Function to display products
void displayProducts(const vector<Product>& products) {
    for (const auto& product : products) {
        cout<<endl<<"Name:.........." << product.name <<endl;
        cout<<"   - Price:.........$" << product.price<<endl;
        cout<<"   - Rating:........" << product.rating <<endl;
        cout<<"   - Stock:........." << product.stock<<endl;
        cout<<"   - Discount:......" << product.discount<<"%"<<endl;
        cout<<"   - Reviews:......." << product.reviews<<endl;
        cout<<"   - Brand:........." << product.brand <<endl;
        cout<<"   - Weight:........" << product.weight<<"g"<<endl;
        cout<<"   - Category:......" << product.category <<endl;
        cout<<"   - Sales:........." << product.sales<< endl;
    }
}

// Heapify function for heap sort
void heapify(vector<Product>& products, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && products[left].discount > products[largest].discount)
        largest = left;

    // If right child is larger than largest so far
    if (right < n && products[right].discount > products[largest].discount)
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(products[i], products[largest]); // Swap root with largest
        heapify(products, n, largest); // Recursively heapify the affected sub-tree
    }
}

void heapSortByDiscountPercentage(vector<Product>& products) {
    int n = products.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(products, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(products[0], products[i]); // Move current root to end
        heapify(products, i, 0); // call max heapify on the reduced heap
    }
}

// Function to get products from user
vector<Product> getProductsFromUser() {
    vector<Product> products;
    int numProducts;

    cout << "Enter the number of products: ";
    cin >> numProducts;

    for (int i = 0; i < numProducts; i++) {
        string name, brand, category;
        float price, rating, discount, weight;
        int stock, reviews, sales;

        cout << "nEnter details for product " << i + 1 << ":n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Price: ";
        cin >> price;
        cout << "Rating: ";
        cin >> rating;
        cout << "Stock Quantity: ";
        cin >> stock;
        cout << "Discount Percentage: ";
        cin >> discount;
        cout << "Number of Reviews: ";
        cin >> reviews;
        cout << "Brand: ";
        cin.ignore();
        getline(cin, brand);
        cout << "Weight: ";
        cin >> weight;
        cout << "Category: ";
        cin.ignore();
        getline(cin, category);
        cout << "Sales Volume: ";
        cin >> sales;
        products.emplace_back(name, price, rating, stock, discount, time(0), reviews, brand, weight, category, sales);
    }

    return products;
}


// Menu to sort and display products by different criteria
void sortAndDisplayMenu(vector<Product>& products) {
    int choice;

Yene Class, [04/11/2024 19:45]
cout << "nChoose a sorting criterion:n"<<endl;
    cout << "1. Price (Bubble Sort)n"<<endl;
    cout << "2. Rating (Selection Sort)n"<<endl;
    cout << "3. Name (Quick Sort)n"<<endl;
    cout << "4. Stock Quantity (Merge Sort)n"<<endl;
    cout << "5. Discount Percentage (Heap Sort)n"<<endl;
    cout << "Enter your choice: "<<endl;

    cin >> choice;

    switch (choice) {
        case 1:
            // bubbleSortByPrice(products); // Implement this function
            cout << "nProducts sorted by Price:n";
            break;
        case 2:
            // selectionSortByRating(products); // Implement this function
            cout << "nProducts sorted by Rating:n";
            break;
        case 3:
            // quickSortByName(products, 0, products.size() - 1); // Implement this function
            cout << "nProducts sorted by Name:n";
            break;
        case 4:
            // mergeSortByStockQuantity(products, 0, products.size() - 1); // Implement this function
            cout << "nProducts sorted by Stock Quantity:n";
            break;
        case 5:
            heapSortByDiscountPercentage(products);
            cout << "nProducts sorted by Discount Percentage:n";
            break;
        default:
            cout << "Invalid choice.n";
            return;
    }

    displayProducts(products);
}

int main() {
    vector<Product> products = getProductsFromUser();
    sortAndDisplayMenu(products);

    return 0;
}