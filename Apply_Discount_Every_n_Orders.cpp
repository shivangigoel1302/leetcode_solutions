class Cashier {
public:
    map<int,int>m;
    int customer = 1;
    int dis;
    int off;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i = 0; i <products.size(); i++){
            m[products[i]] = prices[i];
            dis = n;
            off = discount;
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
       double amt = 0;
        for(int i = 0 ; i < product.size() ;i++){
            amt += m[product[i]]*amount[i];
        }
        if(customer == dis){
            amt = amt - (off*amt)/100;
            customer = 1;
            return amt;
        }
        customer++;
        return amt;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
