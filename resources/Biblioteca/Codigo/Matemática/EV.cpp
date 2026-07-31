// Valor Esperado do Máximo
//
// Calcula o valor esperado (EV) do maior resultado dentre n eventos independentes,
// cada um uniforme em {1, ..., m}
//
// Complexidades:
// O(m) para somar P(r) * r sobre todo r (fastExpo assumido O(log n))
//
// requer fastExpo(ld base, int exp) ja implementado
/*
(r/m)^n - ((r-1)/m)^n = probabilidade de ter exatamente r como o maior resultado 
somatorio de P(r) * r = EV do maximo

n: numero de eventos
r: resultado
m: quantidade de resultados possiveis para um evento
*/

r * ((fastExpo((r/m), n)) - (fastExpo((ld)(r-1)/m, n)));
