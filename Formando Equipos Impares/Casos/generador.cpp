#include <bits/stdc++.h>
#include "../Solución oficial/impares.cpp"
using namespace std;

#define pb push_back
#define mp make_pair

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>=0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define fore(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)

#define DBG(x) do{cout<<#x<<" = "<<x<<endl;}while(false)
#define TAM_MASK 1
#define get(mask,i) ((mask>>(TAM_MASK*(i)) & ( (1<<TAM_MASK)-1)))
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) ))
#define popcount(mask) (__builtin_popcount(mask))
//#define endl '\n'
#define ALL(x) x.begin(),x.end()
template<class T> ostream & operator<<(ostream & out, vector<T> & v)
{
    out<<"[";
    for(auto k : v) out<<k<<",";
    out<<"]"<<"\n";
    return out;
}
template<class T> ostream & operator<<(ostream & out, set<T>  s)
{
    out<<"{";
    for(auto k : s) out<<k<<",";
    out<<"}"<<"\n";
    return out;
}

template<class T, class U> ostream & operator<<(ostream & out, pair<T,U>  p)
{
    out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
    return out;
}
template<class T, class U> istream & operator>>(istream & in, pair<T,U> & p)
{
    in>>p.first>>p.second;
    return in;
}


typedef long long intl;
using std::cout; //using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;
int getTiempo(){
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

string cast(int x){
    if(x<10) return "0"+to_string(x);
    else return to_string(x);
}

void subtarea1(string numcaso){
    string sin = "subtarea 1/S1C"+numcaso+".in";
    string sout = "subtarea 1/S1C"+numcaso+".out";
    ofstream in(sin.c_str());
    ofstream out(sout.c_str());
    int N = 10;
    vector<int> id(N);
    forn(i,N) id[i] = i;
    srand(time(0));
    random_shuffle(id.begin()+1,id.end());
    vector<vector<int> > sub(N);
    forsn(i,1,N){
        int j = rand()%i;
        sub[id[j]].pb(id[i]);
    }
    in<<N<<"\n";
    forn(i,N){
        in<<sub[i].size();
        for(auto x : sub[i]) in<<" "<<x;
        in<<"\n";
    }
    int t0 = getTiempo();
    out<<impares(sub)<<"\n";
    int t1 = getTiempo();
    cout<<sin<<" Tiempo "<<(t1-t0)<<"ms \n";
    in.close();
    out.close();
}

void subtarea2(string numcaso){
    string sin = "subtarea 2/S2C"+numcaso+".in";
    string sout = "subtarea 2/S2C"+numcaso+".out";
    ofstream in(sin.c_str());
    ofstream out(sout.c_str());
    int N = 2e5;
    vector<int> id(N);
    forn(i,N) id[i] = i;
    srand(time(0));
    random_shuffle(id.begin()+1,id.end());
    vector<vector<int> > sub(N);
    forsn(i,1,N){
        sub[id[i-1]]={id[i]};
    }
    in<<N<<"\n";
    forn(i,N){
        in<<sub[i].size();
        for(auto x : sub[i]) in<<" "<<x;
        in<<"\n";
    }
    int t0 = getTiempo();
    out<<impares(sub)<<"\n";
    int t1 = getTiempo();
    cout<<sin<<" Tiempo "<<(t1-t0)<<"ms \n";
    in.close();
    out.close();
}

void subtarea3(string numcaso){
    string sin = "subtarea 3/S3C"+numcaso+".in";
    string sout = "subtarea 3/S3C"+numcaso+".out";
    ofstream in(sin.c_str());
    ofstream out(sout.c_str());
    int N = 2e5;
    vector<int> id(N);
    forn(i,N) id[i] = i;
    srand(time(0));
    random_shuffle(id.begin()+1,id.end());
    vector<vector<int> > sub(N);
    sub[0] = {id[1],id[2]};
    forsn(i,3,N){
        sub[id[i-2]]={id[i]};
    }
    in<<N<<"\n";
    forn(i,N){
        in<<sub[i].size();
        for(auto x : sub[i]) in<<" "<<x;
        in<<"\n";
    }
    int t0 = getTiempo();
    out<<impares(sub)<<"\n";
    int t1 = getTiempo();
    cout<<sin<<" Tiempo "<<(t1-t0)<<"ms \n";
    in.close();
    out.close();
}

void subtarea4(string numcaso){
    string sin = "subtarea 4/S4C"+numcaso+".in";
    string sout = "subtarea 4/S4C"+numcaso+".out";
    ofstream in(sin.c_str());
    ofstream out(sout.c_str());
    int N = 2e5;
    vector<int> id(N);
    forn(i,N) id[i] = i;
    srand(time(0));
    random_shuffle(id.begin()+1,id.end());
    vector<vector<int> > sub(N);
    int h = 15 + stoi(numcaso.c_str())%6;
    
    forsn(i,1,N){
        sub[id[max(0,i-h)]].pb(id[i]);
    }
    in<<N<<"\n";
    forn(i,N){
        in<<sub[i].size();
        for(auto x : sub[i]) in<<" "<<x;
        in<<"\n";
    }
    int t0 = getTiempo();
    out<<impares(sub)<<"\n";
    int t1 = getTiempo();
    cout<<sin<<" Tiempo "<<(t1-t0)<<"ms \n";
    in.close();
    out.close();
}

void subtarea5(string numcaso){
    string sin = "subtarea 5/S5C"+numcaso+".in";
    string sout = "subtarea 5/S5C"+numcaso+".out";
    ofstream in(sin.c_str());
    ofstream out(sout.c_str());
    int N = 2e5;
    vector<int> id(N);
    forn(i,N) id[i] = i;
    srand(time(0));
    random_shuffle(id.begin()+1,id.end());
    vector<vector<int> > sub(N);
    int r = 1;
    forsn(i,0,N){
        if(r<N){
            int c = rand()%2+1;
            forn(j,c){
                sub[id[i]].pb(id[r]);
                r++;
            }
        }
    }
    in<<N<<"\n";
    forn(i,N){
        in<<sub[i].size();
        for(auto x : sub[i]) in<<" "<<x;
        in<<"\n";
    }
    int t0 = getTiempo();
    out<<impares(sub)<<"\n";
    int t1 = getTiempo();
    cout<<sin<<" Tiempo "<<(t1-t0)<<"ms \n";
    in.close();
    out.close();
}

void subtarea6(string numcaso){
    string sin = "subtarea 6/S6C"+numcaso+".in";
    string sout = "subtarea 6/S6C"+numcaso+".out";
    ofstream in(sin.c_str());
    ofstream out(sout.c_str());
    int N = 2e5;
    vector<int> id(N);
    forn(i,N) id[i] = i;
    srand(time(0));
    random_shuffle(id.begin()+1,id.end());
    vector<vector<int> > sub(N);
    int r = 1;
    forsn(i,0,N){
        if(r<N){
            int c = rand()%(N-r)+1;
            forn(j,c){
                sub[id[i]].pb(id[r]);
                r++;
            }
        }
    }
    in<<N<<"\n";
    forn(i,N){
        in<<sub[i].size();
        for(auto x : sub[i]) in<<" "<<x;
        in<<"\n";
    }
    int t0 = getTiempo();
    out<<impares(sub)<<"\n";
    int t1 = getTiempo();
    cout<<sin<<" Tiempo "<<(t1-t0)<<"ms \n";
    in.close();
    out.close();
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    forsn(i,1,51)
        subtarea1(cast(i));
    cout<<string(30,'-')<<endl;
    forsn(i,1,6)
        subtarea2(cast(i));
    cout<<string(30,'-')<<endl;
    forsn(i,1,6)
        subtarea3(cast(i));
    cout<<string(30,'-')<<endl;
    forsn(i,1,11)
        subtarea4(cast(i));
    cout<<string(30,'-')<<endl;
    forsn(i,1,21)
        subtarea5(cast(i));
    cout<<string(30,'-')<<endl;
    forsn(i,1,21)
        subtarea6(cast(i));
    cout<<string(30,'-')<<endl;

}


