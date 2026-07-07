//compressao de coordenada para vector

vector<int> v(n);
vector<int> todos;
for (int i = 0; i < n; i++){
    cin >> v[i];
    todos.push_back(v[i]);
}

sort(all(todos));
todos.erase(unique(all(todos)), todos.end());
int m = todos.size();

vector<int> comp(n);
for (int i = 0; i < n; i++){
    comp[i] = lower_bound(all(todos), v[i]) - todos.begin();
}

template <typename T>
struct Compressor {
    vector<T> coords;
    
    // 1. Add all coordinates from queries and updates
    void add(T x) { 
        coords.push_back(x); 
    }
    
    // 2. Sort and remove duplicates
    void build() {
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
    }
    
    // 3. Get compressed index (0-indexed)
    int get(T x) {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    }
    
    // 4. Get original value from compressed index
    T orig(int idx) {
        return coords[idx];
    }
    
    // 5. Get total number of unique coordinates
    int size() {
        return coords.size();
    }
};