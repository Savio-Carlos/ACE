//LIS

for (auto x : a){
    int pos = upper_bound(all(lis), x) - lis.begin();
    if (pos == (int)lis.size()) lis.push_back(x);
    else lis[pos] = x;
}
