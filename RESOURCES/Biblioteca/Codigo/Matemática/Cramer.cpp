//Cramer

//Calcula x e y de um sistema linear com 2 equacoes e 2 variaveis
/*
c1 * x + c2 * y = n
c3 * x + c4 * y = m

c = coeficientes

5x + 3y = 35
2x - 8y = 12
*/

int det = (c1 * c4) - (c2 * c3);
int det_x = (n * c4) - (c2 * m);
int det_y = (c1 * m) - (n * c3);

int x = det_x / det;
int y = det_y / det;

//mudar pra double e checar se det != 0