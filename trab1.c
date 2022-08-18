// GRR2017300-khkk17 

#include "trab1.h" 

dados* inic_dados(int n)
{
    dados* d_new = malloc(sizeof(dados));
    

    d_new->n = 0;
    d_new->tmax = 0;
    d_new->ca = 0;
    d_new->ct = 0;
    d_new->v_ini = 0;
    d_new->v_min = 0;
    d_new->v_max = 0;
    d_new->k = 0;
    d_new->dn = malloc(sizeof(int)*n);
    d_new->yn = malloc(sizeof(int)*n);
    

    return d_new;
}

void free_dados(dados* dt, energia* e)
{
    free(dt->dn);
    free(dt->yn);
    dt->n = 0;
    dt->tmax = 0;
    dt->ca = 0;
    dt->ct = 0;
    dt->v_ini = 0;
    dt->v_min = 0;
    dt->v_max = 0;
    dt->k = 0;
    e->hidri =0;
    e->termo =0;
    free(dt);
    free(e);
}

dados* readInput()
{
    int na=0;
    //int v;
    //float c;

    fscanf(stdin, "%d\n", &na);
    if (na == 0)
        fprintf(stderr, "Erro nas demandas mensais!!");
    dados* da = inic_dados(na);

    
    da->n = na;
    int i;
    for(i = 0; i < da->n; i++ )
    {
        fscanf(stdin, "%d ", &da->dn[i]);
        
        //da->dn[i] = v;

        if( da->dn[i] < 0)
        {
            fprintf(stderr, "Erro na leitura das demandas!");
                exit(EXIT_FAILURE);
        }        
    }

    for (i = 0; i< da->n ; i++)
    {
        fscanf(stdin, "%d ", &da->yn[i]);
        
        //da->yn[i] = v;

        if( da->yn[i] < 0  )
        {
            fprintf(stderr, "Erro na leitura das demandas!");
                exit(EXIT_FAILURE);
        }        
    }

    fscanf(stdin, "%d %d %d %f ",&da->v_ini,&da->v_min,&da->v_max,&da->k);
    	//da->cap_h[i] = c;
    	if(da->k < 0)
    	{
    		fprintf(stderr, "erro !!");
    		exit(EXIT_FAILURE);
    	}
    
   
    fscanf(stdin, "%d %f",&da->tmax,&da->ca);
        if(da->tmax < 0 || da->ca < 0)
    	{
    		fprintf(stderr, "erro tmax ou ca!!");
    		exit(EXIT_FAILURE);
    	}
    
    fscanf(stdin, "%f ",&da->ct);
        if(da->ct < 0)
    	{
    		fprintf(stderr, "erro no ct !!");
    		exit(EXIT_FAILURE);
    	}
    
        return da;
}

void print_dados(dados* d, energia* e)
{
    int i;
    int v[d->n];
    int sh=0;
    float h;
    float r[d->n];
    float reservatorio;
    float v_turb[d->n];
    for (i = 0; i < d->n ; i++)
    { 
        reservatorio = (float)(d->v_ini + d->yn[i]);//volume do reservatorio;
        r[i] = reservatorio; //vector do volume do resrevatorio de cada mes;
           
        v_turb[i] = reservatorio - (float)(d->v_min); // volume de aguá turbinado no mes;
        e->hidri = (int)(v_turb[i] * d->k); //energia hidrielectrica de cada mes com o volume de aguÁ TURBINADO 
        v[i] = e->hidri; //vetor da energia hidrieletrica em cada mes; 
        d->v_ini = reservatorio - v_turb[i]; // volume restante no reservstorio no mes anterior. 
    }
    for (i = 0; i < d->n ; i++)
        sh = sh + v[i];

    h = (float)(sh*d->ca);// custo ambiental total do n meses 

    fprintf(stdout, "\n min : %.3fx1 + %.3f ;",d->ct,h);// função objectivo
    fprintf(stdout,"\n");
    for (i = 0; i<d->n; i++)// restriçoes de cada mes com as demandas respectivas
        fprintf(stdout, "\n x1 + %d >= %d ;",v[i],d->dn[i]);
    fprintf(stdout,"\n");    
    for (i = 0; i<d->n; i++)// restriçoes dos volumes mensais
        fprintf(stdout, "\n  %.2f >= %d ;",r[i],d->v_max);
    fprintf(stdout,"\n");    
    for (i = 0; i < d->n; i++)// volume de aguá a produzir energia
        fprintf(stdout, "\n x1%d = %.3f ;",i,v_turb[i]);
    fprintf(stdout,"\n");    
        
    fprintf(stdout, "\n x1 >= %d ;",d->tmax);//restrição da energia termoeletrica
    fprintf(stdout,"\n");
    fprintf(stdout, "\n int x1 ; "); // restrição da variavel.
    fprintf(stdout,"\n");
}