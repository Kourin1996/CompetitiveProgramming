std::vector<int> prim;
void getPrim(int N) {
    prim.reserve(N/2);
    std::vector<bool> used(N+1, false);
    REP(i, 4) {
        used[i] = true;
    }
    prim.pb(2);
    prim.pb(3);
    FOR(i, 1, (N+1)/2) {
        if(i*2 <= N) used[i*2] = true;
        if(i*3 <= N) used[i*3] = true;
    }

    FOR(i, 1, N/6 + 1) {
        int a = 6*i - 1;
        if(a > N) break;
        if(!used[a]) {
            prim.pb(a);
            FOR(i, 1, (N+a-1)/a){
                used[a*i] = true;
            }
        }

        int b = 6*i + 1;
        if(b > N) break;
        if(!used[b]) {
            prim.pb(b);
            FOR(i, 1, (N+b-1)/b){
                used[b*i] = true;
            }
        }
    }
}