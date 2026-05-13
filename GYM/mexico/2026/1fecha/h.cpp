#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
char A[MAXN], B[MAXN];
int X[MAXN], d1[MAXN], d2[MAXN];
int fDiff[MAXN+2], gDiff[MAXN+2], fArr[MAXN], gArr[MAXN];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", A); scanf("%s", B);
        int n = strlen(A);
        int prefL = 0, sufL = 0;
        while (prefL < n && A[prefL] == B[n-1-prefL]) prefL++;
        while (sufL < n && A[n-1-sufL] == B[sufL]) sufL++;
        int muStar = min(prefL, sufL);
        for (int i = 0; i < n; i++) X[i] = (A[i]-'a')*26 + (B[i]-'a');
        for (int i = 0; i <= n+1; i++) fDiff[i] = gDiff[i] = 0;
        // Manacher odd
        { int l=0,r=-1;
          for (int i = 0; i < n; i++) {
            int k = (i>r) ? 1 : min(d1[l+r-i], r-i+1);
            while (i-k>=0 && i+k<n && X[i-k]==X[i+k]) k++;
            d1[i] = k;
            if (i+k-1>r) { l=i-k+1; r=i+k-1; }
        }}
        // Manacher even
        { int l=0,r=-1;
          for (int i = 0; i < n; i++) {
            int k = (i>r) ? 0 : min(d2[l+r-i+1], r-i+1);
            while (i-k-1>=0 && i+k<n && X[i-k-1]==X[i+k]) k++;
            d2[i] = k;
            if (i+k-1>r) { l=i-k; r=i+k-1; }
        }}
        for (int i = 0; i < n; i++) {
            int K = d1[i];
            fDiff[i-K+1]++; fDiff[i+1]--;
            gDiff[i]++; gDiff[i+K]--;
            K = d2[i];
            if (K > 0) {
                fDiff[i-K]++; fDiff[i]--;
                gDiff[i]++; gDiff[i+K]--;
            }
        }
        int cur = 0;
        for (int i = 0; i < n; i++) { cur += fDiff[i]; fArr[i] = cur; }
        cur = 0;
        for (int i = 0; i < n; i++) { cur += gDiff[i]; gArr[i] = cur; }
        long long total = muStar;
        for (int mu = 1; mu <= muStar; mu++) {
            if (mu < n) total += fArr[mu];
            if (n-mu-1 >= 0) total += gArr[n-mu-1];
        }
        printf("%lld\n", total);
    }
    return 0;
}