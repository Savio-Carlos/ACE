// Prefix Sum 2D
//
// prefix[i][j] = soma de todos os arr[x][y] com x <= i e y <= j
//
// Complexidades:
// build - O(n*m)
// query (soma de um retangulo) - O(1)
//
// soma do retangulo [x1,y1]-[x2,y2]:
// prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1]
// usar prefix com 1 linha/coluna extra de folga pra nao estourar indice negativo

prefix[i][j]= prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+arr[i][j]​

