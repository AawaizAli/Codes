#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int id;
    double price;
    int quantity;

public:
    Product() {}

    Product(string name, int id, double price, int quantity) {
        this->name = name;
        this->id = id;
        this->price = price;
        this->quantity = quantity;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getId() {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    double getPrice() {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    int getQuantity() {
        return quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
};

class Inventory {
public:
    Product *products;
    int numberOfProducts;

    Inventory() {
        numberOfProducts = 3;
        products = new Product[3];
        products[0] = Product("Product 1", 1, 10.0, 5);
        products[1] = Product("Product 2", 2, 20.0, 10);
        products[2] = Product("Product 3", 3, 30.0, 15);
    }

    double getValue() {
        double total;
        for (int i = 0; i < numberOfProducts; i++) {
            total += products[i].getPrice();
        }
        return total;
    }

    void printProducts() {
        for (int i = 0; i < numberOfProducts; i++) {
            cout << "Name: " << products[i].getName() << endl;
            cout << "ID: " << products[i].getId() << endl;
            cout << "Price: $" << products[i].getPrice() << endl;
            cout << "Quantity: " << products[i].getQuantity() << endl;
            cout << endl;
        }
    }

    void writeToFile(string filename, Product list[], int size) {
        ofstream outfile;
        outfile.open(filename, ios::binary);

        for (int i = 0; i < size/sizeof(Product); i++) {
            outfile.write((char*)&list[i], sizeof(Product));
        }

        outfile.close();
    }

    void addProduct(string name, int id, double price, int quantity) {
        Product newProduct(name, id, price, quantity);
        Product *newProducts = new Product[numberOfProducts+1];
        newProducts[numberOfProducts] = newProduct;

        for (int i = 0 ; i < numberOfProducts ; i++) {
            newProducts[i] = products[i];
        }

        delete []products;
        products = newProducts;
        newProducts = NULL;

        writeToFile("products.bin", products, ++numberOfProducts);
    }

    template <typename T>
    void deleteProduct(T id) {
        int index = -1;
        for (int i = 0; i < numberOfProducts; i++) {
            if (products[i].getId() == id) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            numberOfProducts--;
            for (int i = index; i < numberOfProducts; i++) {
                // cout << "yoo" << endl;
                products[i] = products[i+1];
            }

            products[numberOfProducts] = Product("", 0, 0.0, 0);

            writeToFile("products.bin", products, numberOfProducts);
        }
    }

    void editProduct(int id, string name, double price, int quantity) {
        int index = -1;
        for (int i = 0; i < numberOfProducts; i++) {
            if (products[i].getId() == id) {
                index = i;
                break;
            }
        }
        

        if (index != -1) {
            products[index].setName(name);
            products[index].setPrice(price);
            products[index].setQuantity(quantity);
            products[index].setId(id);  
        }
    }

    void searchById(int key) {

        int index = -1;
        
        for (int i = 0; i < numberOfProducts; i++) {
            if (products[i].getId() == key) {
                index = i;
                break;
            }
        }

        cout << "Displaying Product Details..." << endl;
        cout << "ID: " << products[index].getId() << endl;
        cout << "Name: " << products[index].getName() << endl;
        cout << "Quantity: " << products[index].getQuantity() << endl;
        cout << "Price: " << products[index].getPrice() << endl;
    }

    void searchByName(string name) {

        int index = -1;
        for (int i = 0; i < numberOfProducts; i++) {
            if (products[i].getName() == name) {
                index = i;
                break;
            }
        }

        cout << "Displaying Product Details..." << endl;
        cout << "ID: " << products[index].getId() << endl;
        cout << "Name: " << products[index].getName() << endl;
        cout << "Quantity: " << products[index].getQuantity() << endl;
        cout << "Price: " << products[index].getPrice() << endl;

    }
};

void decorativeLines() {
    cout << endl;
    cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl << endl;
}

int main() {
    Inventory inventory;

    while (true) {

        decorativeLines();

        cout << "-------------------------" << endl;
        cout << "Inventory Management Menu" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Display Products" << endl;
        cout << "2. Add Product" << endl;
        cout << "3. Delete Product" << endl;
        cout << "4. Edit Product" << endl;
        cout << "5. Search Product" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        decorativeLines();

        switch (choice) {
            case 1: {
                inventory.printProducts();
                break;
            }
            case 2: {
                string name;
                int id, quantity;
                double price;

                cout << "Enter Product Name: ";
                cin >> name;
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Product Price: ";
                cin >> price;
                cout << "Enter Product Quantity: ";
                cin >> quantity;

                inventory.addProduct(name, id, price, quantity);
                cout << "Product added successfully!" << endl;
                break;
            }
            case 3: {
                int id;
                cout << "Enter Product ID to delete: ";
                cin >> id;
                inventory.deleteProduct<int>(id);
                cout << "Product deleted successfully!" << endl;
                break;
            }
            case 4: {
                int id, quantity;
                double price;
                string name;

                cout << "Enter Product ID to edit: ";
                cin >> id;
                cout << "Enter new Product Name: ";
                cin >> name;
                cout << "Enter new Product Price: ";
                cin >> price;
                cout << "Enter new Product Quantity: ";
                cin >> quantity;

                inventory.editProduct(id, name, price, quantity);
                cout << "Product edited successfully!" << endl;
                break;
            }
            case 5: {
                int id;
                string name;

                cout << "Search by: " << endl << "1. Product ID." << endl << "2. Name.";
                cin >> choice;

                switch (choice) {
                    case 1:
                    {
                        cin >> id;
                        inventory.searchById(id);
                        break;
                    }
                    case 2:
                    {
                        cin >> name;
                        inventory.searchByName(name);
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice." << endl;
                    }
                }

                // inventory.searchProduct(name);
                break;
            }
            case 6: {
                cout << "Exiting program..." << endl;
                exit(0);
            }
            default: {
                cout << "Invalid choice! Please enter a valid choice." << endl;
                break;
            }
        }
    }

    return 0;
}
