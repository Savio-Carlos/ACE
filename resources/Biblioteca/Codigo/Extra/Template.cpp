// Template
//
// Boilerplate padrao pra abrir uma questao: bits/stdc++, operator>>/operator<<
// pra pair e pra qualquer container iteravel (cin >> vector, cout << vector/set/...),
// fastio e defines uteis (int como long long, ld, endl)
//
// copiar como base do arquivo .cpp
// cuidado ao usar #define int long long: pode conflitar com size_t/unsigned e
// com funcoes de biblioteca que esperam int de 32 bits

#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
	return is >> p.first >> p.second;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
	for(auto& elem: v){
		is >> elem;
	}
	return is;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const std::pair<T, U>& p) {
	return os << "{" << p.first << ", " << p.second << "}";
}

template <typename T>
concept IterableContainer = requires(T t) {
    begin(t);
    end(t);
} && !is_convertible_v<T, string_view>;

template<IterableContainer Container>
ostream& operator<<(ostream& os, const Container& c) {
	os << "[";
	bool first = true;
	for(const auto& elem : c){
	if(!first) os << ", ";
 		os << elem;
		first = false;
	}
	return os << "]";
}

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define int long long
#define ld long double
#define endl '\n'

signed main(){
	fastio;
	
	return 0;
}
