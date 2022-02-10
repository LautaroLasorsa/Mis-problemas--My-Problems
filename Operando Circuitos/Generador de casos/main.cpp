#include "template.cpp"
#include "generator.cpp"
#include "solver.cpp"
//#include "Solucion Bitset.cpp"
//#include "Solucion Euristica.cpp"
/**
Casos:
La correctitud la hago probando todos los posibles input para esa compuerta, con los elementos 1, 2500 y 5000.
00 - Correctitud OR  seed: 1234567
01 - Correctitud AND seed: 314159
02 - Correctitud XOR seed: 7654321

03 - 'seno' de OR con valores de 1 a 5000. N = 100 000 seed : 969934516
04 - 'seno' de AND con valores de 1 a 5000. N = 100 000 seed : 204136269
05 - 'seno' de XOR con valores de 1 a 5000. N = 100 000 seed : 120729107
06 - 'seno' alternnado con valores de 1 a 5000. N = 100 000 seed : 557449645

07 - zig zag de OR con valores grandes N = 100 000 seed : 399947571
08 - zig zag de AND con valores grandes N = 100 000 seed : 298974798
09 - zig zag de XOR con valores grandes N = 100 000 seed : 757497539
10 - zig zag alternnado con valores grandes N = 100 000 seed : 596085799

11 - Correctitud extendida OR seed: 864608265
12 - Correctitud extendida AND seed: 118516758
13 - Correctitud extendida XOR seed: 485369723

14 - Correctitud compuesta 2 niveles con OR y AND. seed: 650986851
15 - Correctitud compuesta 2 niveles con OR y XOR. seed: 747021619
16 - Correctitud compuesta 2 niveles con AND y XOR. seed: 347487929

17 - Concatenar casos 00, 01, 02, 14, 15, 16 en rango original. seed: 527887100
18 - Concatenar casos 00, 01, 02, 14, 15, 16 en rango ampliado. seed: 346009972

19 - zig zag de OR y XOR con valores de 1 a 5000. N = 100 000 seed: 942777546
20 - zig zag de OR y XOR con valores grandes. N = 100 000 seed: 560519568

21 - zig zag de 2 niveles OR con valores granes. N = 99 998 seed:504719046
22 - zig zag de 2 niveles XOR con valores granes. N = 99 998 seed: 504719046
23 - zig zag de 2 niveles OR y XOR con valores de 1 a 5000. N = 99 998 seed: 812967408
24 - zig zag de 2 niveles OR y XOR con valores granes. N = 99 998 seed: 660613808
Subtareas:

1 <= N,M <= 500 e 1<=input<=5000, casos : 00, 01, 02, 14, 15, 16 | 6
Sin XOR ni OR, casos: 01, 04, 08,12 | 4
Sin AND ni XOR, casos: 00, 03, 07, 11, 21| 5
Sin OR ni AND, casos: 02, 05, 09, 13, 22 | 5
1<=input<=5000, casos: 03, 04, 05, 06, 17, 19, 23 | 7
Sin restricciones adicionales, casos: 07, 08, 09, 10, 11, 12, 13, 18, 20,21, 22, 24 | 12
Total: 39
Techo: 40

*/
int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(0);

    /**
        ofstream out00 ("00.in");
        ofstream out01 ("01.in");
        ofstream out02 ("02.in");
        int M00 = generator00_02(1234567,out00,'O');
        int M01 = generator00_02(314159,out01,'A');
        int M02 = generator00_02(7654321,out02,'X');
        DBG(M00);
        DBG(M01);
        DBG(M02);
        out00.close();
        out01.close();
        out02.close();

        ifstream in00("00.in");
        ifstream in01("01.in");
        ifstream in02("02.in");
        cout<<"generado"<<endl;
        ofstream res00("00.out");
        ofstream res01("01.out");
        ofstream res02("02.out");
        cout<<"output creado"<<endl;
        solver(in00,res00);
        cout<<"00 solucionado"<<endl;
        solver(in01,res01);
        cout<<"01 solucionado"<<endl;
        solver(in02,res02);
        cout<<"02 solucionado"<<endl;


        ofstream out03("03.in");
        ofstream out04("04.in");
        ofstream out05("05.in");
        ofstream out06("06.in");
        int M03 = generator03_10(969934516,out03,{'O'});
        int M04 = generator03_10(204136269,out04,{'A'});
        int M05 = generator03_10(120729107,out05,{'X'});
        int M06 = generator03_10(557449645,out06,{'O','A','X'});
        DBG(M03);
        DBG(M04);
        DBG(M05);
        DBG(M06);
        out03.close();
        out04.close();
        out05.close();
        out06.close();
        cout<<"generado ok"<<endl;
        ifstream in03("03.in");
        ofstream res03("03.out");
        solver(in03,res03);

    **/
    /**
        ofstream out07("07.in");
        ofstream out08("08.in");
        ofstream out09("09.in");
        ofstream out10("10.in");
        int M07 = generator03_10(399947571,out07,{'O'},false);
        int M08 = generator03_10(298974798,out08,{'A'},false);
        int M09 = generator03_10(757497539,out09,{'X'},false);
        int M10 = generator03_10(596085799,out10,{'O','A','X'},false);
        DBG(M07);
        DBG(M08);
        DBG(M09);
        DBG(M10);
        out07.close();
        out08.close();
        out09.close();
        out10.close();
        cout<<"generado ok"<<endl;
    */
    /**

        ofstream out11 ("11.in");
        ofstream out12 ("12.in");
        ofstream out13 ("13.in");
        int M11 = generator11_13(864608265,out11,'O');
        int M12 = generator11_13(118516758,out12,'A');
        int M13 = generator11_13(485369723,out13,'X');
        DBG(M11);
        DBG(M12);
        DBG(M13);
        out11.close();
        out12.close();
        out13.close();


        ifstream in11("11.in");
        ifstream in12("12.in");
        ifstream in13("13.in");
        cout<<"generado"<<endl;
        ofstream res11("11.out");
        ofstream res12("12.out");
        ofstream res13("13.out");
        cout<<"output creado"<<endl;
        int t0 = time(0);
        solver(in11,res11);
        cout<<"11 solucionado"<<endl;
        int t1 = time(0);
        solver(in12,res12);
        cout<<"12 solucionado"<<endl;
        int t2 = time(0);
        solver(in13,res13);
        cout<<"13 solucionado"<<endl;
        int t3 = time(0);
        DBG(t0);
        DBG(t1);
        DBG(t2);
        DBG(t3);
    **/
    /**
        ofstream out14 ("14.in");
        ofstream out15 ("15.in");
        ofstream out16 ("16.in");
        int M14 = generator14_16(650986851,out14,{'O','A'});
        int M15 = generator14_16(747021619,out15,{'O','X'});
        int M16 = generator14_16(347487929,out16,{'A','X'});
        DBG(M14);
        DBG(M15);
        DBG(M16);
        out14.close();
        out15.close();
        out16.close();
        ifstream in14("14.in");
        ifstream in15("15.in");
        ifstream in16("16.in");
        cout<<"generado"<<endl;
        ofstream res14("14.out");
        ofstream res15("15.out");
        ofstream res16("16.out");
        cout<<"output creado"<<endl;
        solver(in14,res14);
        solver(in15,res15);
        solver(in16,res16);
    **/
    /**
        ofstream out17("17.in");
        ofstream out18("18.in");
        vector<string> ins = {"00.in","01.in","02.in","14.in","15.in","16.in"};
        int M17 = concatenador(527887100,ins,out17);
        int M18 = concatenador(346009972,ins,out18,true);
        DBG(M17);
        DBG(M18);
        out17.close();
        out18.close();
        ifstream in17("17.in");
        ifstream in18("18.in");
        cout<<"generado"<<endl;
        ofstream res17("17.out");
        ofstream res18("18.out");
        cout<<"output creado"<<endl;
        solver(in17,res17);
        cout<<"intermedio"<<endl;
        solver(in18,res18);
        cout<<"Todo ok"<<endl;
        return 0;
    **/
    /**
        ofstream out19("19.in");
        ofstream out20("20.in");
        int M19 = generator03_10(942777546,out19,{'O','X'});
        int M20 = generator03_10(560519568,out20,{'O','X'},false);
        DBG(M19);
        DBG(M20);
        out19.close();
        out20.close();
        942777546  560519568
    **/

    /**
        ofstream in21("inputs\\21.in");
        ofstream in22("inputs\\22.in");
        ofstream in23("inputs\\23.in");
        ofstream in24("inputs\\24.in");

        int M21 = generator21_24(504719046,in21,{'O'},false);
        int M22 = generator21_24(512578716,in22,{'X'},false);
        int M23 = generator21_24(812967408,in23,{'O','X'},true);
        int M24 = generator21_24(660613808,in24,{'O','X'},false);

        DBG(M21);
        DBG(M22);
        DBG(M23);
        DBG(M24);

        in21.close();
        in22.close();
        in23.close();
        in24.close();
    */

    forsn(t,0,25){
        string tc = "00";
        tc[1] += t%10;
        tc[0] += t/10;
        string in = "inputs\\"+tc+".in";
        string out = "outputs\\"+tc+".out";
        cout<<Chequer(in)<<endl;
        ifstream resin(in);
        ofstream resout(out);
        solver(resin,resout);
        resin.close();
        resout.close();
    }
}
