class UF{
    public:
        UF();
        void Union(int p,int q);
        int find(int p);
        bool connected(int p,int q);
        int count();
    private:
        int id[1000];
        int count;
        int size[1000];
};