int vmax = INT32_MIN; 
int balo2(int k, vector v, vector s, vector a, vector c , int w) {
 //stop
 if(k >= n) { 
int t = 0, v = 0; 
for(int i = 0; i < p.size(); i ++) {
 v += v[i]; t += s[i]; 
} 
if(t <= w && vmax < v ) {
 vmax = v; 
}
 v.clear(); s.clear(); 
return 0; 
} 
//back 
v[k] = c[k]; s[k] = a[k] //choose
balo2(k+1, v, s, a, c, w); 
p[k] = s[k] = 0; //ignore
 balo2(k+1, v, s, a, c, w);
 return 0; 
}
