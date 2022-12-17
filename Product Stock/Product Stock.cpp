#include <iostream>

using namespace std;

class Product {
	//fields: id, name, description, price, discount
	int id;
	char* name;
	char* description;
	double price;
	int discount;
public:
	Product() {
		id = 0;
		SetName(nullptr);
		SetDescription(nullptr);
		price = 0;
		discount = 0;
	}
	Product(const int& id, const char* name, const char* descrription, const int& price, const int& discount) {
		this->id = id;
		SetName(name);
		SetDescription(description);
		this->price = price;
		this->discount = discount;
	}

	void SetId(int id) {
		if (id > 0) {
			this->id = id;
		}
	}

	void SetName(const char* name) {
		delete this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void SetDescription(const char* description) {
		delete this->description;
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	void SetPrice(int price) {
		if (price > 0) {
			this->price = price;
		}
	}
	int GetId() {
		return id;
	}
	char* GetName() {
		return name;
	}
	char* GetDescription() {
		return description;
	}
	double GetPrice() {
		return price;
	}
	int GetDiscount() {
		return discount;
	}
	int GetPriceWithDiscount() {
		double newPrice;
		newPrice = price - ((price) / discount);
		return newPrice;
	}


	////////////////////////

	void ShowProduct() {
		cout << "Id: " << GetId() << "\nName: " << GetName() << "\nDescription: " << GetDescription() << "\nPrice: " << GetPrice() << "\nDiscount: " << GetDiscount();
	}
};

class Stock {
private:
	char* name;
	Product* stock;
	int productCount = 5;
	void SetCount(int count) {
		if (count > 0) {
			this->productCount = count;
		}
	}
public:
	Stock(const char* name, Product* stock, int productCount) {
		SetName(name);
		SetCount(productCount);
		SetStock(stock);
	}
	Product* GetStock() {
		return stock;
	}
	char* GetName() {
		return name;
	}
	int GetCount() {
		return productCount;
	}

	void SetName(const char* name) {
		if (name != nullptr) {
			int index = strlen(name);
			this->name = new char[index + 1]{};
			strcpy_s(this->name, index + 1, name);
		}
	}

	void SetStock(Product* newStock) {
		this->stock = new Product[productCount]{};
		for (int i = 0; i < productCount; i++) {
			stock[i].SetId(newStock[i].GetId());
			stock[i].SetName(newStock[i].GetName());
			stock[i].SetDescription(newStock[i].GetDescription());
			stock[i].SetPrice(newStock[i].GetPrice());
			//stock[i].GetDiscount(newStock[i].GetDiscount());
		}
	}

	void ShowProduct() {
		for (int i = 0; i < productCount; i++) {
			stock[i].ShowProduct();
		}
	}
	~Stock() {
		delete[] name;
		delete[] stock;
	}

};

void main() {
	Product stock[3] {
		Product(1, "Efes", "Drink", 3, 5),
		Product(2,"apple", "Fruit", 5, 3),
		Product(3, "Alpen Gold", "Chocolate", 2, 4)
	};
	Stock stoc("Anbar", stock, 2);
	stoc.ShowProduct();
}