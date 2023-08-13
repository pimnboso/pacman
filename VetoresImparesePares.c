#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpa(){
    system ("clear"); // Limpa a tela para cada execução
}

int main()
{
  setlocale(LC_ALL, "portuguese");
	int c=0, x=0, i, j, n, p;		// auxiliares
	int par[5],impar[5],N[15];		// vetores
	int cont_impar=0, cont_par=0;	// contadores
 
	// Entrada dos valores no vetor N     
	 for (i = 0; i < 15; i++)
    {
    	printf("O valor do vetor N[%d]: ", i);
		  scanf("%d", &N[i]);
        limpa();
	}	        
	
	for (i=0; i<15; i++)
    {
        if (cont_impar == 5)	// estourou o vetor impar
        {
            for (n=0; n<5; n++)
            printf("Impar[%d] = %d\n", n, impar[n]);
              cont_impar=0;
        }
        if (cont_par == 5)		// estourou o vetor par
        {
            for (p = 0; p < 5; p++)
            printf("Par[%d] = %d\n", p, par[p]);
              cont_par=0;
        }

        if (N[i] % 2 != 0)		// Se for impar
        {
            impar[c] = N[i];
            ++c;
            cont_impar++;
            if (c == 5) c = 0;
        }
        if (N[i] % 2 == 0)		// Se for par
        {
            par[x] = N[i];
            ++x;
            cont_par++;
            if (x == 5) x = 0;
        }
    }
    for (i = 0; i < cont_impar; i++)	// Mostra vetor impar
            printf("Impar[%d] = %d\n", i, impar[i]);
            
    for (j = 0; j < cont_par; j++)		// Mostra vetor par
            printf("Par[%d] = %d\n", j, par[j]);
}

