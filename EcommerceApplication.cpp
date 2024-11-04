#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
using namespace std;

class Product {
public:
    string name;
    float price;
    float rating;
    int stockQuantity;
    float discountPercentage;
    time_t dateAdded;
    int numberOfReviews;
    string brand;
    float weight;
    string category;
    int salesVolume;

    Product(string n, float p, float r, int qty, float discount, time_t date, int reviews, string b, float w, string cat, int sales)
        : name(n), price(p), rating(r), stockQuantity(qty), discountPercentage(discount),
          dateAdded(date), numberOfReviews(reviews), brand(b), weight(w), category(cat), salesVolume(sales) {}
};
