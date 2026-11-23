class ProductOfNumbers {
public:
    vector<int> pre;
    
    ProductOfNumbers() {
        pre.clear();
        pre.push_back(1);
    }
    
    void add(int num) {
        int n=pre.size();
        
        if(num==0){pre.clear();pre.push_back(1);}
        else{pre.push_back(pre[n-1]*num);}
        
    }
    
    int getProduct(int k) {
        int n=pre.size();
        if(k>=n){return 0;}
        else{
            return pre[n-1]/pre[n-k-1];
        }
       

        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */