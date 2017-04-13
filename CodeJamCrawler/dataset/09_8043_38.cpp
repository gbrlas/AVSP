#include <fstream>

using namespace std;

char pos[121][6] = {"12345","12354","12435","12453","12534","12543","13245","13254","13425","13452","13524","13542","14235",
"14253","14325","14352","14523","14532","15234","15243","15324","15342","15423","15432","21345","21354",
"21435","21453","21534","21543","23145","23154","23415","23451","23514","23541","24135","24153","24315",
"24351","24513","24531","25134","25143","25314","25341","25413","25431","31245","31254","31425","31452",
"31524","31542","32145","32154","32415","32451","32514","32541","34125","34152","34215","34251","34512",
"34521","35124","35142","35214","35241","35412","35421","41235","41253","41325","41352","41523","41532",
"42135","42153","42315","42351","42513","42531","43125","43152","43215","43251","43512","43521","45123",
"45132","45213","45231","45312","45321","51234","51243","51324","51342","51423","51432","52134","52143",
"52314","52341","52413","52431","53124","53142","53214","53241","53412","53421","54123","54132","54213",
"54231","54312","54321"};

char c[12][12];

long long simulate(int nrcells,int nrpris,int* whichpris, int* relorder)
{
    long long res = 0;
    int cells[101];
    memset(cells,1,sizeof(cells));
    cells[0] = cells[nrcells+1] = 0;
    int where = 1;
    for(int i=0;i<nrpris;i++)
    {
        int j = 0;
        while(relorder[j]!=where) ++j;
        cells[whichpris[j]] = 0;
        int k = whichpris[j]+1;
        while(cells[k++]) ++res;
        k = whichpris[j]-1;
        while(cells[k--]) ++res;
        where ++;
    }
    return res;

}

int main()
{
    ifstream f("c_brut.in");
    ofstream f2("c_brut.out");
    int nrcases;
    f>>nrcases;
    for(int hh=1;hh<=nrcases;hh++)
    {
        int pris[101];
        int p,q;
        f>>p>>q;
        for(int i=0;i<q;++i) f>>pris[i];

        int fact = 1;
        for(int i=1;i<=q;++i) fact *= i;
        long long costmin = p*q;
        int relorder[6];
        for(int i=0; i<fact; ++i)
        {
            for(int j=0;j<q;++j)
                relorder[j] = pos[i][4-j] - 5 + q - '0';
            long long mincrt = simulate(p,q,pris,relorder);
            if(costmin>mincrt) costmin = mincrt;

        }
        f2<<"Case #"<<hh<<": "<<costmin<<"\n";
    }
    return 0;
}
