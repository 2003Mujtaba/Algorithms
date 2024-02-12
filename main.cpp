#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> // Include for std::remove_if
#include <chrono>

struct Product {
    int id;
    std::string name;
    double price;
    std::string category;
    
    Product() = default; // Default constructor
    Product(int id, std::string name, double price, std::string category) : 
        id(id), name(name), price(price), category(category) {}
};

void preloadProducts(std::vector<Product>& products) {
    products.push_back(Product(57353, "Camera SBBHC", 546.88, "Electronics"));
    products.push_back(Product(40374, "Smartphone ILGCU", 947.54, "Electronics"));
    products.push_back(Product(34863, "Biography XPESK", 287.31, "Books"));
    products.push_back(Product(18086, "Shirt ZQLTI", 439.07, "Clothing"));
    products.push_back(Product(16041, "Jacket OTBKQ", 986.73, "Clothing"));
    products.push_back(Product(43566, "Mystery COKPK", 836.57, "Books"));
    products.push_back(Product(69260, "Toaster FODKJ", 867.6, "Home & Kitchen"));
    products.push_back(Product(30895, "Knife Set KGFUF", 385.77, "Home & Kitchen"));
    products.push_back(Product(19897, "Blender DPKLR", 488.62, "Home & Kitchen"));
    products.push_back(Product(87296, "Skirt IRTZX", 261.08, "Clothing"));
    products.push_back(Product(68215, "Laptop QLBQC", 404.21, "Electronics"));
    products.push_back(Product(68097, "Camera SGSRZ", 36.39, "Electronics"));
    products.push_back(Product(26556, "Novel METLI", 376.45, "Books"));
    products.push_back(Product(30483, "Knife Set WRSZZ", 55.97, "Home & Kitchen"));
    products.push_back(Product(62422, "Camera VFQWS", 382.69, "Electronics"));
    products.push_back(Product(22806, "Smartwatch VVFNT", 203.55, "Electronics"));
    products.push_back(Product(24976, "Pants YZMAK", 449.56, "Clothing"));
    products.push_back(Product(30631, "Headphones JFGYQ", 115.08, "Electronics"));
    products.push_back(Product(27939, "Textbook TWQKZ", 108.5, "Books"));
    products.push_back(Product(41355, "Headphones JOUXM", 211.57, "Electronics"));
    products.push_back(Product(94162, "Laptop WRJOZ", 956.53, "Electronics"));
    products.push_back(Product(28710, "Dress FRSMO", 879.09, "Clothing"));
    products.push_back(Product(90291, "Pants TIPUD", 853.38, "Clothing"));
    products.push_back(Product(20368, "Shirt FQFPK", 83.19, "Clothing"));
    products.push_back(Product(68960, "Blender OMDPS", 720.06, "Home & Kitchen"));
    products.push_back(Product(40852, "Novel IRROY", 603.68, "Books"));
    products.push_back(Product(97895, "Blender KSJHL", 123.25, "Home & Kitchen"));
    products.push_back(Product(96314, "Cutting Board LUICX", 628.29, "Home & Kitchen"));
    products.push_back(Product(85719, "Laptop GZORF", 641.33, "Electronics"));
    products.push_back(Product(98625, "Mystery BOPTP", 160.68, "Books"));
    products.push_back(Product(66208, "Blender GCZSK", 161.83, "Home & Kitchen"));
    products.push_back(Product(86128, "Biography ASTVE", 90.44, "Books"));
    products.push_back(Product(10889, "Shirt DNRZU", 316.48, "Clothing"));
    products.push_back(Product(82777, "Shirt OZWXU", 790.46, "Clothing"));
    products.push_back(Product(43451, "Mixer CKVJQ", 379.5, "Home & Kitchen"));
    products.push_back(Product(12848, "Toaster VZXUE", 867.97, "Home & Kitchen"));
    products.push_back(Product(17646, "Biography BPWXR", 424.83, "Books"));
    products.push_back(Product(85197, "Cutting Board IJVPP", 986.89, "Home & Kitchen"));
    products.push_back(Product(13471, "Knife Set TPCMO", 831.9, "Home & Kitchen"));
    products.push_back(Product(66237, "Headphones LTPLK", 995.13, "Electronics"));
    products.push_back(Product(30251, "Pants HCBKI", 450.68, "Clothing"));
    products.push_back(Product(46944, "Smartwatch QNALX", 647.08, "Electronics"));
    products.push_back(Product(93533, "Novel WOHSN", 516.39, "Books"));
    products.push_back(Product(95090, "Cutting Board RBACL", 568.63, "Home & Kitchen"));
    products.push_back(Product(98827, "Shirt RSQGL", 231.54, "Clothing"));
    products.push_back(Product(64489, "Novel EFPYC", 502.61, "Books"));
    products.push_back(Product(39148, "Cutting Board OYHCV", 220.15, "Home & Kitchen"));
    products.push_back(Product(25425, "Mystery MGSPG", 783.17, "Books"));
    products.push_back(Product(69525, "Camera XROCD", 76.05, "Electronics"));
    products.push_back(Product(44574, "Knife Set ASRHX", 64.62, "Home & Kitchen"));
}


void insertProduct(std::vector<Product>& products, int id, const std::string& name, double price, const std::string& category);
void updateProduct(std::vector<Product>& products, int id, const std::string& newName);
void deleteProduct(std::vector<Product>& products, int id);
int searchById(const std::vector<Product>& products, int id);
int searchByName(const std::vector<Product>& products, const std::string& name);
void insertionSortByPrice(std::vector<Product>& products);
void measureSortTime(std::vector<Product>& products);

int main() {
    std::vector<Product> products;
    
    preloadProducts(products);
    
    std::cout << "Measuring sort time for unsorted data..." << std::endl;
    measureSortTime(products); // This will sort and measure time
    
    std::cout << "Measuring sort time for already sorted data..." << std::endl;
    measureSortTime(products);
    
    std::reverse(products.begin(), products.end());
    std::cout << "Measuring sort time for reverse ordered data..." << std::endl;
    measureSortTime(products);
    
    std::cout << "Initial product data:" << std::endl;
    for (const auto& product : products) {
        std::cout << "ID: " << product.id << ", Name: " << product.name
                  << ", Price: $" << product.price << ", Category: " << product.category << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    // Insert a new product
    insertProduct(products, 100001, "New Product XYZ", 299.99, "Electronics");
    std::cout << "After inserting a new product:" << std::endl;
    for (const auto& product : products) {
        std::cout << "ID: " << product.id << ", Name: " << product.name
                  << ", Price: $" << product.price << ", Category: " << product.category << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    // Update a product's name
    updateProduct(products, 57353, "Updated Camera SBBHC");
    std::cout << "After updating product ID 57353:" << std::endl;
    for (const auto& product : products) {
        std::cout << "ID: " << product.id << ", Name: " << product.name
                  << ", Price: $" << product.price << ", Category: " << product.category << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    // Delete a product
    deleteProduct(products, 40374);
    std::cout << "After deleting product ID 40374:" << std::endl;
    for (const auto& product : products) {
        std::cout << "ID: " << product.id << ", Name: " << product.name
                  << ", Price: $" << product.price << ", Category: " << product.category << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    // Search for a product by ID
    int indexById = searchById(products, 34863);
    if (indexById != -1) {
        std::cout << "Found by ID (34863): " << products[indexById].name << std::endl;
    } else {
        std::cout << "Product not found by ID (34863)." << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    // Search for a product by Name
    int indexByName = searchByName(products, "Novel METLI");
    if (indexByName != -1) {
        std::cout << "Found by Name (Novel METLI): " << products[indexByName].name << std::endl;
    } else {
        std::cout << "Product not found by Name (Novel METLI)." << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    // Now, sort the products by price using Insertion Sort
    insertionSortByPrice(products);

    // Print the sorted product list
    std::cout << "Products sorted by price:" << std::endl;
    for (const auto& product : products) {
        std::cout << "ID: " << product.id << ", Name: " << product.name
                  << ", Price: $" << product.price << ", Category: " << product.category << std::endl;
    }

    return 0;
}



void insertProduct(std::vector<Product>& products, int id, const std::string& name, double price, const std::string& category) {
    products.push_back(Product(id, name, price, category));
}

void updateProduct(std::vector<Product>& products, int id, const std::string& newName) {
    for (auto& product : products) {
        if (product.id == id) {
            product.name = newName;
            break; // Exit the loop once the product is found and updated
        }
    }
}

void deleteProduct(std::vector<Product>& products, int id) {
    auto it = std::remove_if(products.begin(), products.end(), [id](const Product& product) {
        return product.id == id;
    });
    products.erase(it, products.end());
}

int searchById(const std::vector<Product>& products, int id) {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].id == id) {
            return i; // Return the index of the found product
        }
    }
    return -1; // Product not found
}

int searchByName(const std::vector<Product>& products, const std::string& name) {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].name == name) {
            return i; // Return the index of the found product
        }
    }
    return -1; // Product not found
}

void insertionSortByPrice(std::vector<Product>& products) {
    int i, j;
    Product key;
    for (i = 1; i < products.size(); i++) {
        key = products[i];
        j = i - 1;

        /* Move elements of products[0..i-1], that are
        greater than key (price), to one position ahead
        of their current position */
        while (j >= 0 && products[j].price > key.price) {
            products[j + 1] = products[j];
            j = j - 1;
        }
        products[j + 1] = key;
    }
}


void measureSortTime(std::vector<Product>& products) {
    auto start = std::chrono::high_resolution_clock::now();

    // Call your sorting function here
    insertionSortByPrice(products);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Sorting took " << duration.count() << " milliseconds." << std::endl;
}


