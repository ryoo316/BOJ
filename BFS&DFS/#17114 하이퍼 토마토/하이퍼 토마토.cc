#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int w, v, u, t, s, r, q, p, o, n, m;
}coord;

queue<coord> QQ;

int ***********A;
int N, M, O, P, Q, R, S, T, U, V, W;

int dirw[22] = {1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dirv[22] = {0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int diru[22] = {0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dirt[22] = {0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dirs[22] = {0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0};
int dirr[22] = {0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0};
int dirq[22] = {0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0};
int dirp[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0};
int diro[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0};
int dirn[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0};
int dirm[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1};

bool is_outside(int w, int v, int u, int t, int s, int r, int q, int p, int o, int n, int m){
    if((w < 0 || w >= W || v < 0 || v >= V) || (u < 0 || u >= U || t < 0 || t >= T)) return true;
    if((s < 0 || s >= S || r < 0 || r >= R) || (q < 0 || q >= Q || p < 0 || p >= P)) return true;
    if((o < 0 || o >= O || n < 0 || n >= N) || (m < 0 || m >= M)) return true;
    return false;
}

void BFS(){
    while(!QQ.empty()){
        coord cur = QQ.front();
        int w = cur.w, v = cur.v, u = cur.u, t = cur.t, s = cur.s, r = cur.r;
        int q = cur.q, p = cur.p, o = cur.o, n = cur.n, m = cur.m;
        QQ.pop();
        for(int i=0;i<22;i++){
            int nw = w + dirw[i], nv = v + dirv[i], nu = u + diru[i], nt = t + dirt[i];
            int ns = s + dirs[i], nr = r + dirr[i], nq = q + dirq[i], np = p + dirp[i];
            int no = o + diro[i], nn = n + dirn[i], nm = m + dirm[i];
            if(is_outside(nw, nv, nu, nt, ns, nr, nq, np, no, nn, nm))continue;
            if(A[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] != 0)continue;
            A[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm]
            = A[w][v][u][t][s][r][q][p][o][n][m] + 1;
            QQ.push({nw, nv, nu, nt, ns, nr, nq, np, no, nn, nm});
        }
    }
}

void free(){
    for(int w=0;w<W;w++){
        for(int v=0;v<V;v++){
            for(int u=0;u<U;u++){
                for(int t=0;t<T;t++){
                    for(int s=0;s<S;s++){
                        for(int r=0;r<R;r++){
                            for(int q=0;q<Q;q++){
                                for(int p=0;p<P;p++){
                                    for(int o=0;o<O;o++){
                                        for(int n=0;n<N;n++){
                                            delete[] A[w][v][u][t][s][r][q][p][o][n];
                                        }
                                        delete[] A[w][v][u][t][s][r][q][p][o];
                                    } 
                                    delete[] A[w][v][u][t][s][r][q][p];
                                }
                                delete[] A[w][v][u][t][s][r][q];
                            }
                            delete[] A[w][v][u][t][s][r];
                        }
                        delete[] A[w][v][u][t][s];
                    }
                    delete[] A[w][v][u][t];
                }
                delete[] A[w][v][u];
            }
            delete[] A[w][v];
        }
        delete[] A[w];
    }
    delete A;
}

void Solve(){
    cin >> M >> N >> O >> P >> Q >> R;
    cin >> S >> T >> U >> V >> W;
    A = new int **********[W];
    for(int w=0;w<W;w++){
        A[w] = new int *********[V];
        for(int v=0;v<V;v++){
            A[w][v] = new int ********[U];
            for(int u=0;u<U;u++){
                A[w][v][u] = new int *******[T];
                for(int t=0;t<T;t++){
                    A[w][v][u][t] = new int ******[S];
                    for(int s=0;s<S;s++){
                        A[w][v][u][t][s] = new int *****[R];
                        for(int r=0;r<R;r++){
                            A[w][v][u][t][s][r] = new int ****[Q];
                            for(int q=0;q<Q;q++){
                                A[w][v][u][t][s][r][q] = new int ***[P];
                                for(int p=0;p<P;p++){
                                    A[w][v][u][t][s][r][q][p] = new int **[O];
                                    for(int o=0;o<O;o++){
                                        A[w][v][u][t][s][r][q][p][o] = new int *[N];
                                        for(int n=0;n<N;n++){
                                            A[w][v][u][t][s][r][q][p][o][n] = new int [M];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int w=0;w<W;w++){
        for(int v=0;v<V;v++){
            for(int u=0;u<U;u++){
                for(int t=0;t<T;t++){
                    for(int s=0;s<S;s++){
                        for(int r=0;r<R;r++){
                            for(int q=0;q<Q;q++){
                                for(int p=0;p<P;p++){
                                    for(int o=0;o<O;o++){
                                        for(int n=0;n<N;n++){
                                            for(int m=0;m<M;m++){
                                                cin >> A[w][v][u][t][s][r][q][p][o][n][m];
                                                if(A[w][v][u][t][s][r][q][p][o][n][m] == 1)
                                                    QQ.push({w, v, u, t, s, r, q, p, o, n, m});
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    BFS();
    int mx = 0;
    for(int w=0;w<W;w++){
        for(int v=0;v<V;v++){
            for(int u=0;u<U;u++){
                for(int t=0;t<T;t++){
                    for(int s=0;s<S;s++){
                        for(int r=0;r<R;r++){
                            for(int q=0;q<Q;q++){
                                for(int p=0;p<P;p++){
                                    for(int o=0;o<O;o++){
                                        for(int n=0;n<N;n++){
                                            for(int m=0;m<M;m++){
                                                if(A[w][v][u][t][s][r][q][p][o][n][m] == 0){
                                                    cout << -1;
                                                    return;
                                                }
                                                else if(A[w][v][u][t][s][r][q][p][o][n][m] >= 1)
                                                    mx = max(mx, A[w][v][u][t][s][r][q][p][o][n][m]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << mx - 1;
    free();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}