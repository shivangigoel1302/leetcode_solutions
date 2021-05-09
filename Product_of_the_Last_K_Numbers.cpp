class ProductOfNumbers {
public:
    map<int,int>m;
    int cnt;
    ProductOfNumbers() {
        m[0] = 1;
        cnt = 0;
    }

    void add(int num) {
        if(num == 0){
            cnt = 0;
            m.erase(m.begin(),m.end());
            m[0] = 1;
            return;
        }
        cnt++;
        m[cnt] = num* m[cnt-1];
    }

    int getProduct(int k) {
        int l = m.size()-k-1;
        if(l < 0) return 0;
        int a = m[cnt];
        int b = m[l];
        return a/b;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
