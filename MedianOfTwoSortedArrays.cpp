double median(vector<int> a, vector<int> b) {
    int size1 = a.size();
    int size2 = b.size();
    int maxcount = (size1 + size2) / 2 + 1;
    int x1 = 0.0, x2 = 0.0;
    int m1 = 0, m2 = 0; 
    for(int count = 0; count < maxcount; count++) {
        m1 = m2;
        if(x1 != size1 && x2 != size2) {
            m2 = a[x1] < b[x2] ? a[x1++] : b[x2++];
        }
        else if(x1 != size1)
            m2 = a[x1++];
        else if(x2 != size2)
            m2 = b[x2++];
    }
    if((size1 + size2) % 2 == 0)
        return (double)(m1 + m2) / 2;
    else
        return m2;
}