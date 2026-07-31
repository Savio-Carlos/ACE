// StringStream
//
// Padrao de uso de stringstream pra separar uma string em tokens por um delimitador
//
// split_sentence(s) retorna um vector<string> com as palavras de s separadas por ' '
// trocar o ' ' em getline(ss, word, ' ') pra separar por outro delimitador

vector<string> split_sentence(string s){
    stringstream ss(s);

    string word;

    vector<string> v;

    while(getline(ss, word, ' ')){
        v.push_back(word);
    }
    return v;
}