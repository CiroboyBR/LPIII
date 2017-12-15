#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

char tab[8][8];

struct rei
{
    int x;
    int y;
    bool check;
};
struct rei K, k;

//true = check
//false = não check

bool CheckRei(struct rei R)
{
    if(tab[R.x][R.y] == 'K')
    {
        //Diagonais
        if( (tab[R.x-1][R.y-1] == 'k' && R.x-1 > -1 && R.y-1 > -1) || ( tab[R.x-1][R.y+1] == 'k' && R.x-1 > -1 && R.y+1 < 8) || (tab[R.x+1][R.y+1] == 'k' && R.x+1 < 8 && R.y+1 < 8) || (tab[R.x+1][R.y-1] == 'k' && R.x+1 < 8 && R.y-1 > -1) )
            return true;
        //Vert Hor
        else if ( (tab[R.x-1][R.y] == 'k' && R.x-1 > -1)  || ( tab[R.x+1][R.y] == 'k' && R.x+1 < 8 ) || ( tab[R.x][R.y-1] == 'k' && R.y-1 > -1) || ( tab[R.x][R.y+1] == 'k' && R.y+1 < 8) )
            return true;
    }
    else
    {
        //Diagonais
        if( (tab[R.x-1][R.y-1] == 'K' && R.x-1 > -1 && R.y-1 > -1) || ( tab[R.x-1][R.y+1] == 'K' && R.x-1 > -1 && R.y+1 < 8) || (tab[R.x+1][R.y+1] == 'K' && R.x+1 < 8 && R.y+1 < 8) || (tab[R.x+1][R.y-1] == 'K' && R.x+1 < 8 && R.y-1 > -1) )
            return true;
        //Vert Hor
        else if ( (tab[R.x-1][R.y] == 'K' && R.x-1 > -1)  || ( tab[R.x+1][R.y] == 'K' && R.x+1 < 8 ) || ( tab[R.x][R.y-1] == 'K' && R.y-1 > -1) || ( tab[R.x][R.y+1] == 'K' && R.y+1 < 8) )
            return true;
    }

    return false;
}

bool CheckPeao(struct rei R)
{
    if(tab[R.x][R.y] == 'K')
    {   if(R.x-1 > -1 && R.y-1 > -1 && R.x-1 > -1 && R.y+1 < 8)
            if(tab[R.x-1][R.y-1] == 'p' || tab[R.x-1][R.y+1] == 'p')
                return true;
    }
    else if(R.x+1 < 8 && R.y+1 < 8 && R.x+1 < 8 && R.y-1 > -1)
            if(tab[R.x+1][R.y+1] == 'P' || tab[R.x+1][R.y-1] == 'P')
                return true;

    return false;
}

bool CheckDiagonais(struct rei R )
{
    register int x = R.x+1, y = R.y+1;
    char bispo, rainha;

    if(tab[R.x][R.y] == 'K') {
        rainha = 'q';
        bispo = 'b';
    }
    else {
        rainha = 'Q';
        bispo = 'B';
    }

    //Diagonal Principal descendo
    while(x < 8 && y < 8) {
        if (tab[x][y] == rainha || tab[x][y] == bispo)
            return true;
        else if (tab[x][y] != '.')
            break;
        x++;
        y++;
    }

    //Diagonal Principal subindo
    x = R.x-1;
    y = R.y-1;
    while(x > -1 && y > -1) {
        if (tab[x][y] == rainha || tab[x][y] == bispo)
            return true;
        else if (tab[x][y] != '.')
            break;
        x--;
        y--;
    }

    //Diagonal Secundaria subindo
    x = R.x-1;
    y = R.y+1;
    while(x > -1 && y < 8) {
        if (tab[x][y] == rainha || tab[x][y] == bispo)
            return true;
        else if (tab[x][y] != '.')
            break;
        x--;
        y++;
    }

    //Diagonal Secundaria descendo
    x = R.x+1;
    y = R.y-1;
    while(x < 8 && y > -1) {
        if (tab[x][y] == rainha || tab[x][y] == bispo)
            return true;
        else if (tab[x][y] != '.')
            break;
        x++;
        y--;
    }

    return false;
}

bool CheckCavalos(struct rei R)
{
    char cavalo;

    if(tab[R.x][R.y] == 'K')
        cavalo = 'n';
    else
        cavalo = 'N';

    //L de cima esquerdo
    if( R.x-2 > -1 && R.y-1 > -1)
        if(tab[R.x-2][R.y-1] == cavalo)
            return true;

    if( R.x-2 > -1 && R.y+1 < 8)
        if(tab[R.x-2][R.y+1] == cavalo)
            return true;

    //L de baixo esquerdo
    if( R.x+2 < 8 && R.y-1 > -1)
        if(tab[R.x+2][R.y-1] == cavalo)
            return true;

    //L de baixo direito
    if( R.x+2 < 8 && R.y+1 < 8)
        if(tab[R.x+2][R.y+1] == cavalo)
            return true;

    //L direito cima
    if( R.x-1 > -1 && R.y+2 < 8)
        if(tab[R.x-1][R.y+2] == cavalo)
            return true;

    //L direito baixo
    if( R.x+1 >= 0 && R.y+2 < 8)
        if(tab[R.x+1][R.y+2] == cavalo)
            return true;

    //L esquerda cima
    if( R.x-1 > -1 && R.y-2 > -1)
        if(tab[R.x-1][R.y-2] == cavalo)
            return true;

    //L esquerda baixo
    if( R.x+1 > -1 && R.y-2 > -1)
        if(tab[R.x+1][R.y-2] == cavalo)
            return true;

    return false;
}

bool CheckVertHor(struct rei R)
{
    char torre, rainha;
    register int x;

    if(tab[R.x][R.y] == 'K') {
        rainha = 'q';
        torre = 'r';
    }
    else {
        rainha = 'Q';
        torre = 'R';
    }
    //HOR direita
    for(x = R.y+1; x < 8; x++ )
        if(tab[R.x][x] == rainha || tab[R.x][x] == torre)
            return true;
        else if (tab[R.x][x] != '.')
            break;
    //HOR esquerda
    for(x = R.y-1; x > -1; x-- )
        if(tab[R.x][x] == rainha || tab[R.x][x] == torre)
            return true;
        else if (tab[R.x][x] != '.' )
            break;
    //VER cima
    for(x = R.x-1; x > -1; x-- )
        if(tab[x][R.y] == rainha || tab[x][R.y] == torre)
            return true;
        else if (tab[x][R.y] != '.')
            break;
    //VER baixo
    for(x = R.x+1; x < 8; x++ )
        if(tab[x][R.y] == rainha || tab[x][R.y] == torre)
            return true;
        else if (tab[x][R.y] != '.')
            break;

    return false;
}
void identificaPosReis()
{
    for(register int i = 0; i < 8; i++)
        for(register int j = 0; j < 8; j++) {
            if (tab[i][j] == 'k') {
                k.x = i;
                k.y = j;
            }
            else if (tab[i][j] == 'K') {
                K.x = i;
                K.y = j;
            }
        }
}

int main ()
{
    register long long unsigned int num = 1;
    register int i;
    bool checado;
    string branco;
    while (1) {
        checado = false;
        //leitura de 0 a 7
        for( i = 0; i < 8; i++)
            cin >> tab[i];

        //identifica posicao do rei
        k.x = -1;
        identificaPosReis();
        if(k.x == -1)
            return 0;

        //Checa Rei Preto
        if(CheckPeao(k) || CheckRei(k) || CheckCavalos(k) || CheckDiagonais(k) || CheckVertHor(k)) {
            printf("Game #%llu: black king is in check.\n", num);
            checado = true;
        }
        //Checa Rei Branco
        if(CheckPeao(K) || CheckRei(K) || CheckCavalos(K) || CheckDiagonais(K) || CheckVertHor(K)) {
            printf("Game #%llu: white king is in check.\n", num);
            checado = true;
        }

        if (checado == false)
            printf("Game #%llu: no king is in check.\n", num);

        ++num;
        //imprimeMat();
    }

    return 0;
}
