#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
#define ld long double


// string split_sentence(string s){
//     stringstream ss(s);

//     string word;

//     vector<string> v;

//     while(getline(ss, word, ' ')){
//         if(word.size() > 0) v.push_back(word);
//     }
//     return v;
// }

vector<string> split_sentence(string s){
    vector<string> v;
    string aux;
    for(int i = 0; i < s.size(); i++){

        if(s[i] == ':'){
            if(!aux.empty()) v.push_back(aux);
            v.push_back(":");
            aux = "";
            continue;
        }

        if(s[i] == '\''){
            string aux2 = "\'";
            i++;
            while(s[i] != '\''){
                aux2 += s[i];
                i++;
            }
            v.push_back(aux2 + "\'");
            continue;
        }

        if(s[i] == '"'){
            string aux2 = "\"";
            i++;
            while(s[i] != '"'){
                aux2 += s[i];
                i++;
            }
            v.push_back(aux2 + "\"");
            continue;
        }

        if(s[i] == ' '){
            if(!aux.empty()) v.push_back(aux);
            aux = "";
        } else {
            if(s[i] != '"' || s[i] != '\'') aux += s[i];
        }
    }

    if(!aux.empty()) v.push_back(aux);

    return v;
}

// Retorna vazio se nao for uma string
// Retorna a string sem o prefixo print(, print(", print('
string is_print(string s){
    string aux = "print(", ret;
    
    for(int i = 0; i < aux.size(); i++){
        if(aux[i] != s[i]) return ret;
    }

    

    for(int i = aux.size(); i < s.size(); i++){
        if(s[i] != ')'){
            ret.push_back(s[i]);
        }
    }

    return ret;
}

signed main(){
    fastio;

    string total, aux;

    // while(cin >> aux){
    //     total += aux;
    // }

    while(getline(cin, aux)){
        total += aux;
    }

    // ;

    // total += aux;

    // getline(cin, aux, '\n');

    // if(aux.empty())

    // total += aux;

    auto pp = split_sentence(total);


    // for(auto p:pp) cout << p << endl;

    // cout << total << endl;

    stack<string> pilha, pilha2;
    for(int i = 0; i < pp.size(); i++){

        pilha.push(pp[i]);

        if(pilha.top() == "input()"){
            pilha.pop(); // remove "input()"
            pilha.pop(); // remove o caractere '='
            cout << "LEIA " << pilha.top() << endl;
            pilha.pop();
            continue;
        }

        if(pilha.top() == "print()"){
            pilha.pop();
            cout << "APRESENTE " << pilha.top() << endl;
            pilha.pop();
            continue;
        }

        string s;
        
        s = is_print(pilha.top());

        if(!s.empty()){
            cout << "APRESENTE " << s << endl;
            pilha.pop();
            continue;
        }

        if(pilha.top() == ":"){


            pilha.pop(); // remove ":"


            while(pilha.top() != "while" && pilha.top() != "if"){
                pilha2.push(pilha.top());
                pilha.pop();
            }


            

            if(pilha.top() == "while") cout << "ENQUANTO ";
            if(pilha.top() == "if") cout << "SE ";

            while(!pilha2.empty()){
                cout << pilha2.top();
                if(pilha2.size() != 1) cout << " ";
                pilha2.pop();
            }

            if(pilha.top() == "while") cout << " ";
            if(pilha.top() == "if") cout << " ENTAO ";

            pilha.pop();
        }
    }


}