#include <stdio.h>
int main(){
    int ah,al,bh,bl,cl,ch,dl;
    printf("ingresa valor ah:\n");
    scanf("%d",&ah);
    printf("ingresa valor al:\n");
    scanf("%d",&al);
    printf("ingresa valor bh:\n");
    scanf("%d",&bh);
    printf("ingresa valor bl:\n");
    scanf("%d",&bl);
    printf("ingresa valor ch:\n");
    scanf("%d",&ch);
    printf("ingresa valor cl:\n");
    scanf("%d",&cl);

    int *const pah=&ah;
    int *const pal=&al;
    int *const pbh=&bh;
    int *const pbl=&bl;
    int *const pch=&ch;
    int *const pcl=&cl;
    int *const pdl=&dl;
    
    printf("valores ingresados: ah=%p\n",&ah);
    printf("valores ingresados: al=%p\n",&al);
    printf("valores ingresados: bh=%p\n",&bh);
    printf("valores ingresados: bl=%p\n",&bl);
    printf("valores ingresados: ch=%p\n",&ch);
    printf("valores ingresados: cl=%p\n",&cl);
    
    int suma= *pah + *pal;
    printf("resultado de la suma ah+al= %d\n",suma);

    *pdl=suma;
    printf("valor dl: %d\n",*pdl);

    int resta= *pah - *pal;
    printf("resultaod de la resta ah-al= %d\n",resta);
    *pdl=resta;
    printf("valor nuevo dl: %d\n",*pdl);

    int multiplicacion= *pah * *pal;
    printf("resultado de la multiplicacion ah*al=%d\n",multiplicacion);
    *pdl=multiplicacion;
    printf("valor nuevo dl: %d\n",*pdl);

    int division= *pah / *pal;
    printf("resultado de la division ah/al=%d\n",division);
    *pdl=division;
    printf("valor nuevo dl: %d\n",*pdl);



    int sumab= *pbh + *pbl;
    printf("resultado de la suma bh+bl= %d\n",sumab);

    *pdl=sumab;
    printf("valor dl: %d\n",*pdl);

    int restab= *pbh - *pbl;
    printf("resultaod de la resta bh-bl= %d\n",restab);
    *pdl=restab;
    printf("valor nuevo dl: %d\n",*pdl);

    int multiplicacionb= *pbh * *pbl;
    printf("resultado de la multiplicacion bh*bl=%d\n",multiplicacionb);
    *pdl=multiplicacionb;
    printf("valor nuevo dl: %d\n",*pdl);

    int divisionb= *pbh / *pbl;
    printf("resultado de la division bh/bl=%d\n",divisionb);
    *pdl=divisionb;
    printf("valor nuevo dl: %d\n",*pdl);


    int sumac= *pch + *pcl;
    printf("resultado de la suma ch+cl= %d\n",sumac);

    *pdl=sumac;
    printf("valor dl: %d\n",*pdl);

    int restac= *pch - *pcl;
    printf("resultaod de la resta ch-cl= %d\n",restac);
    *pdl=restac;
    printf("valor nuevo dl: %d\n",*pdl);

    int multiplicacionc= *pch * *pcl;
    printf("resultado de la multiplicacion ch*cl=%d\n",multiplicacionc);
    *pdl=multiplicacionc;
    printf("valor nuevo dl: %d\n",*pdl);

    int divisionc= *pch / *pcl;
    printf("resultado de la division ch/cl=%d\n",divisionc);
    *pdl=divisionc;
    printf("valor nuevo dl: %d\n",*pdl);






    return 0;
}