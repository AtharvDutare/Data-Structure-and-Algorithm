int64_t fun(int64_t x) {
    int64_t res=0;
    vector<int64_t> p={2,3,5,7};
    for(int64_t mask=0;mask<16;mask++) {
        int64_t m=1;
        int64_t sg=1;
        for(int64_t i=0;i<4;i++) {
            if((mask>>i)&1) {
                m*=p[i];
                sg=-sg;
            }
        }
        res+=sg*(x/m);
    }
    return res;
}