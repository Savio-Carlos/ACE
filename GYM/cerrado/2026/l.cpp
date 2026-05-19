#include <bits/stdc++.h>
using namespace std;
//codigo do gemini

// Retorna o id do módulo dado o seu nível (r) e a sua posição no nível (c)
// r e c são 1-indexados.
long long get_id(long long r, long long c) {
    return r * (r - 1) / 2 + c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    if (!(cin >> N)) return 0;

    long long r = 1, c = 1;
    
    // Armazena a posição do Último "1" Verificado
    long long K_r = 1, K_c = 1;

    // 1. Fase de Descida: Exatamente N consultas
    for (long long L = 1; L <= N; ++L) {
        long long left_child_r = r + 1;
        long long left_child_c = c;
        
        cout << "? " << get_id(left_child_r, left_child_c) << endl;
        
        int resp;
        cin >> resp;
        
        if (resp == 1) {
            // Filho à esquerda é 1. Nós confirmamos um novo 1.
            r = left_child_r;
            c = left_child_c;
            K_r = r;
            K_c = c;
        } else {
            // Filho à esquerda é 0. Assumimos o filho da direita para continuar a descida.
            r = left_child_r;
            c = left_child_c + 1;
        }
    }

    // 2. Fase de Busca Binária
    // A sequência começa em K e vai até a base (nível N+2).
    long long m = (N + 2) - K_r; 
    long long low = 0;
    long long high = m;

    while (high - low > 1) {
        long long mid = low + (high - low) / 2;
        
        long long mid_node = get_id(K_r + mid, K_c + mid);
        cout << "? " << mid_node << endl;
        
        int resp;
        cin >> resp;
        
        if (resp == 1) {
            low = mid; // A transição 1 -> 0 está mais para baixo
        } else {
            high = mid; // A transição 1 -> 0 está mais para cima
        }
    }

    // O nó em 'low' tem valor 1, e o seu filho à direita em 'high' tem valor 0.
    // O seu filho à esquerda foi consultado durante a Fase 1 e também é 0.
    long long answer = get_id(K_r + low, K_c + low);
    cout << "! " << answer << endl;

    return 0;
}