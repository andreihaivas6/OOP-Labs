struct nod
{
    int info;
    nod* urm;
};

class Sort
{
    nod* prim;
    nod* ultim;
    public:
        // add constuctors
        Sort(int length, int min, int max);
        Sort(int n, int v[]);
        Sort(int count, ...);
        Sort(char s[100]);
        void InsertSort(bool ascendent = false);
        void QuickSort(bool ascendent = false);
        void BubbleSort(bool ascendent = false);
        void Print();
        int  GetElementsCount();
        int  GetElementFromIndex(int index);
        void insereaza(int x);
        void QuickSort(int pr, int ul);
        void Partitioneaza(int pr, int ul, int piv);
        void atribuie(int poz, int val);
};

