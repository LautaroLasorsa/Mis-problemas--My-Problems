int generator00_02(int seed, ostream & out, char comp){
    srand(seed);
    int tam = 3;
    vector<int> lvals = {1,2500,5000};
    int N = 4 + 4*(1<<(2*tam)), M = 0;
    vector<int> ids(N);
    vector<int> vals;
    forn(i,5000) vals.pb(i+1);
    random_shuffle(ALL(vals));
    forn(i,N) ids[i] = i;
    random_shuffle(ALL(ids));
    vector<vector<int> > vs(N);
    int cost = 0;
    string ts(N,'E');
    for(int i = 0;i<ids.size()-4;i+=4){
        ts[ids[i]] = 'L';
        vs[ids[i]] = {ids[i+1]};
        ts[ids[i+1]] = comp;
        vs[ids[i+1]] = {ids[i+2],ids[i+3]};
        int mask = i/4;
        int x = ids[i+2], y = ids[i+3];
        ts[x] = ts[y] = 'E';
        forn(j,tam){
            if(get(mask,j)) vs[x].push_back(lvals[j]), cost++;
            if(get(mask,j+tam)) vs[y].push_back(lvals[j]), cost++;
        }
        cost += 3;
    }
    int sem = (500-cost-3)/2;
    int x = ids.size()-1;
    int y = ids.size()-2;
    int a = ids.size()-3, b = ids.size()-4;
    x = ids[x], y = ids[y], a = ids[a], b = ids[b];
    ts[x] = 'L';
    vs[x] = {y};
    ts[y] = comp;
    ts[a] = ts[b] = 'E';
    vs[y] = {a,b};
    forn(i, sem) vs[a].pb(vals[i]), vs[b].pb(vals[i+sem/2]);
    out<<N<<endl;
    out<<ts<<endl;
    for(auto v : vs){
        M += v.size();
        out<<v.size();
        forn(i,v.size()){
            out<<" ";
            out<<v[i];
        }
        out<<endl;
    }
    return M;
}


int generator03_10(int seed, ostream & out, vector<char> comp, bool lim = true){
    int N = 100000;
    vector<int> ids(N);
    forn(i,N) ids[i] = i;
    srand(seed);
    random_shuffle(ALL(ids));
    vector<vector<int> > vs(N);
    string ts(N,'E');
    int pre = ids[0];
    int val = 1, dval = 1;
    int m1 = 2500, m2 = 5000;
    if(lim == false) m1 = 1e6, m2 = 1e8;
    vs[pre] = {val,m1+1-val,m1+val,m2+1-val,3333};
    ts[pre] = 'E';
    int id = 0;
    for(int i = 1;i<N-1;i+=2){
        int x = ids[i];
        int y = ids[i+1];
        if(i%4==1)vs[x] = {y,pre};
        else if(i%4==3) vs[x] = {pre,y};
        val+=dval;
        if((val==1 || val==1250)&&lim) dval*=-1;
        vs[y] = {val,m1+1-val,m1+val,m2+1-val};
        ts[y] = 'E';
        ts[x] = comp[id%comp.size()];
        id++;
        pre = x;
    }
    int x = ids[N-1];
    vs[x] = {pre};
    ts[x] = 'L';
    int M = 0;
    out<<N<<endl;
    out<<ts<<endl;
    for(auto v : vs){
        M += v.size();
        out<<v.size();
        forn(i,v.size()){
            out<<" ";
            out<<v[i];
        }
        out<<endl;
    }
    return M;
}


int generator11_13(int seed, ostream & out, char comp){
    srand(seed);
    int tam = 7;
    vector<int> vals;
    set<int> svals;
    int lim = 1e9, id = 0;
    int N = 4+4*(1<<(2*tam)), M = 0;
    int cost = 0;
    forn(j,150000){
        int v = (1ll*rand()*RAND_MAX + rand())%lim+1;
        if(svals.count(v))j--;
        else svals.insert(v),vals.pb(v);
    }
    vector<int> ids(N);
    forn(i,N) ids[i] = i;
    random_shuffle(ALL(ids));
    vector<vector<int> > vs(N);
    string ts(N,'E');
    for(int i = 0;i<ids.size()-4;i+=4){
        ts[ids[i]] = 'L';
        vs[ids[i]] = {ids[i+1]};
        ts[ids[i+1]] = comp;
        vs[ids[i+1]] = {ids[i+2],ids[i+3]};
        int mask = i/4;
        int x = ids[i+2], y = ids[i+3];
        ts[x] = ts[y] = 'E';
        vector<int> lvals;
        forn(k,tam) lvals.pb(vals[id]),id++;
        forn(j,tam){
            if(get(mask,j)) vs[x].push_back(lvals[j]), cost++;
            if(get(mask,j+tam)) vs[y].push_back(lvals[j]), cost++;
        }
        cost += 3;
    }
    int sem = (300000-cost-3)/2;
    int x = ids.size()-1;
    int y = ids.size()-2;
    int a = ids.size()-3, b = ids.size()-4;
    x = ids[x], y = ids[y], a = ids[a], b = ids[b];
    ts[x] = 'L';
    vs[x] = {y};
    ts[y] = comp;
    ts[a] = ts[b] = 'E';
    vs[y] = {a,b};
    forn(i, sem) vs[a].pb(vals[i]), vs[b].pb(vals[i+sem/2]);
    out<<N<<endl;
    out<<ts<<endl;
    for(auto v : vs){
        M += v.size();
        out<<v.size();
        forn(i,v.size()){
            out<<" ";
            out<<v[i];
        }
        out<<endl;
    }
    return M;
}

int generator14_16(int seed, ostream & out, vector<char> comp){
    int tam = 1;
    int N =  8 * (2 * (1<<(4*tam))+2);
    srand(seed);
    int lim = 5000;
    vector<int> vals(lim);
    vector<int> ids(N);
    forn(i,N) ids[i] = i;
    forn(i,lim) vals[i] = i+1;
    random_shuffle(ALL(ids));
    random_shuffle(ALL(vals));
    vector<vector<int> > vs(N);
    string ts(N,'E');
    int cost = 0;
    for(int i = 0;i<N-16;i+=8){
        ts[ids[i]] = 'L';
        vs[ids[i]] = {ids[i+1]};
        int tt = bool(get(i,4));
        ts[ids[i+1]] = comp[tt];
        vs[ids[i+1]] = {ids[i+2],ids[i+3]};
        ts[ids[i+2]] = ts[ids[i+3]] = comp[1-tt];
        vs[ids[i+2]] = {ids[i+4],ids[i+5]};
        vs[ids[i+3]] = {ids[i+6],ids[i+7]};
        forn(j,4*tam){
            if(get(i>>3,j)){
                vs[ids[i+4+j]].pb(vals[i]);
                cost++;
            }
        }
        cost += 7;
    }
    DBG(cost);
    int sem = (500 - cost - 14)/8;
    DBG(sem);
    int base = 0;
    for(int i = N-16;i<N;i+=8){
        ts[ids[i]] = 'L';
        vs[ids[i]] = {ids[i+1]};
        int t = bool(get(i,4));
        ts[ids[i+1]] = comp[t];
        vs[ids[i+1]] = {ids[i+2],ids[i+3]};
        ts[ids[i+2]] = ts[ids[i+3]] = comp[1-t];
        vs[ids[i+2]] = {ids[i+4],ids[i+5]};
        vs[ids[i+3]] = {ids[i+6],ids[i+7]};
        forn(j,4){
            vs[ids[i+4+j]].insert(vs[ids[i+4+j]].end(),vals.begin()+base,vals.begin()+base+sem);
            base += sem/2;
        }
    }
    int M = 0;
    out<<N<<endl;
    out<<ts<<endl;
    for(auto v : vs){
        M += v.size();
        out<<v.size();
        forn(i,v.size()){
            out<<" ";
            out<<v[i];
        }
        out<<endl;
    }
    return M;
}

int concatenador(int seed, vector<string> vin, ostream & out, bool add = false){
    bool ok = true;
    srand(seed);
    int maxN = 1e5;
    int N = 0;
    string ts;
    vector<vector<int> > vs;
    set<string> used;
    while(ok){
        random_shuffle(ALL(vin));
        for(auto & s : vin){
            ifstream in(s);
            int n; in>>n;
            if(n+N>maxN){
                ok = false;
                break;
            }
            string t; in>>t;
            ts.insert(ts.end(),ALL(t));
            int adv = 0;
            if(add && used.count(s)) adv = rand()%int(1e8)+int(1e6);
            forn(i,n){
                vector<int> v;
                int k; in>>k;
                forn(j,k){
                    int a; in>>a;
                    if(t[i]!='E')
                        a+=N;
                    else if(add){
                        a+=adv;
                    }
                    v.pb(a);
                }
                vs.pb(v);
            }
            N += n;
            used.insert(s);
        }
    }
    int M = 0;
    out<<N<<endl;
    out<<ts<<endl;
    for(auto v : vs){
        M += v.size();
        out<<v.size();
        forn(i,v.size()){
            out<<" ";
            out<<v[i];
        }
        out<<endl;
    }
    //DBG(N);
    return M;
}

int generator21_24(int seed, ostream & out, vector<char> comp, bool lim = true){
    int N = 99998;
    vector<int> ids(N);
    forn(i,N) ids[i] = i;
    srand(seed);
    random_shuffle(ALL(ids));
    vector<vector<int> > vs(N);
    string ts(N,'E');
    int pre = ids[0];
    int val = 1, dval = 1;
    int m1 = 2500, m2 = 5000;
    if(lim == false) m1 = 1e6, m2 = 1e8;
    vs[pre] = {val,m1+1-val,m1+val,m2+1-val,3333};
    ts[pre] = 'E';
    int id = 0;
    for(int i = 1;i<N-3;i+=4){
        int x = ids[i];
        int y = ids[i+1];
        int a = ids[i+2];
        int b = ids[i+3];
        if(id%2==1)vs[x] = {y,pre};
        else vs[x] = {pre,y};
        vs[y] = {a,b};
        val+=dval;
        if((val==1 || val==1250)&&lim) dval*=-1;
        vs[a] = {val,m1+1-val,m1+val,m2+1-val};
        val+=dval;
        if((val==1 || val==1250)&&lim) dval*=-1;
        vs[b] = {val,m1+1-val,m1+val,m2+1-val};
        ts[y] = comp[(1+id)%comp.size()];
        ts[x] = comp[id%comp.size()];
        ts[a] = ts[b] = 'E';
        id++;
        pre = x;
    }
    int x = ids[N-1];
    vs[x] = {pre};
    ts[x] = 'L';
    int M = 0;
    out<<N<<endl;
    out<<ts<<endl;
    for(auto v : vs){
        M += v.size();
        out<<v.size();
        forn(i,v.size()){
            out<<" ";
            out<<v[i];
        }
        out<<endl;
    }
    return M;
}

