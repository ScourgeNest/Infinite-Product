//Niculici Mihai-Daniel 315CA - infinite_product
//Sper ca e bine, doamne ajuta.
#include <stdio.h>
#include <math.h>
#define ull unsigned long long
//Trasforma un numar aflat in baza 8 intr-unul in baza 10
ull baza_8_in_baza_10(ull numar)
{
	//Am nevoie de 8^0 pentru a incepe procesul
	ull putere_8 = 1, numar_baza_10 = 0;
	//Fiecarei cifre de la ultima spre prima
	// ii corespunde cate o putere de-a lui 8.
	while (numar != 0) {
		numar_baza_10 += ((numar % 10) * putere_8);
		numar /= 10;
		putere_8 *= 8;
	}
	return numar_baza_10;
}

void cond_a(ull ai, ull *pa_max, ull *pa_max_int, char *p_0a, char *p_0a_int)
{
	//Verific daca am 0 la coordonate.
	if (ai == 0) {
		//Daca da, marchez ca maximului ii este atribuit 0 si
		// ca nu este initializat cu 0.
		if (*pa_max_int == 0 && *p_0a_int == '0')
			*p_0a_int = '1';
	}
	//Verific daca numarul meu este mai mare decat primul maxim
	if (ai > *pa_max_int) {
		//Verific daca primul max este initializat ca sa il
		//dau celui de-al doilea max.
		if (*p_0a_int == '1') {
			*p_0a = '1';
			*pa_max = *pa_max_int;
		}
		*pa_max_int = ai;
		*p_0a_int = '1';
	}
	//Verific daca ai se afla intre primul max si al doilea max
	if (ai >= *pa_max && ai != *pa_max_int) {
		*pa_max = ai;
		*p_0a = '1';
	}
}

void cond_b(ull bi, ull *pb_max, ull *pb_max_int, char *p_0b, char *p_0b_int)
{
	//Verific daca am 0 la coordonate.
	if (bi == 0) {
		//Daca da, marchez ca maximului ii este atribuit 0 si
		// ca nu este initializat cu 0.
		if (*pb_max_int == 0 && *p_0b_int == '0')
			*p_0b_int = '1';
	}
	if (bi > *pb_max_int) {
		//Verific daca numarul meu este mai mare decat primul maxim
		if (*p_0b_int == '1') {
			*p_0b = '1';
			*pb_max = *pb_max_int;
		}
		*pb_max_int = bi;
		*p_0b_int = '1';
	}
	//Verific daca bi se afla intre primul max si al doilea max
	if (bi >= *pb_max && bi != *pb_max_int) {
		*pb_max = bi;
		*p_0b = '1';
	}
}

void afis_max(ull a_max, ull b_max, char *p_0a, char *p_0b)
{
	//Verific daca exista al doilea maxim pentru ambii vectori.
	//Daca nu exista, afisez "-1"
	//Daca exista, il afisez.
	if (*p_0a == '0')
		printf("-1 ");
	else
		printf("%llu ", a_max);
	if (*p_0b == '0')
		printf("-1\n");
	else
		printf("%llu\n", b_max);
}

int main(void)
{
	//Toate variabilele folosite sunt explicate in README
	int N;
	ull ps = 0, a_max = 0, b_max = 0;
	ull *pa_max = &a_max, *pb_max = &b_max;
	ull a_max_int = 0, b_max_int = 0;
	ull *pa_max_int = &a_max_int, *pb_max_int = &b_max_int;
	char nr_0a = '0', nr_0b = '0';
	char *p_0a = &nr_0a, *p_0b = &nr_0b;
	char nr_0a_int = '0', nr_0b_int = '0';
	char *p_0a_int = &nr_0a_int, *p_0b_int = &nr_0b_int;
	double n_a = 0, n_b = 0;
	scanf("%d", &N);
	//Parcurg coordonatele si le folosesc pentru a nu fi
	//nevoie sa le stochez undeva.
	for (int i = 1; i <= N; i++) {
		ull ai, bi;
		scanf("%llu %llu", &ai, &bi);
		//Transform numerele in baza 10.
		ai = baza_8_in_baza_10(ai);
		bi = baza_8_in_baza_10(bi);
		//Calculez prod scalar
		ps += (ai * bi);
		//Conditiile pentru a determina maximul
		cond_a(ai, pa_max, pa_max_int, p_0a, p_0a_int);
		cond_b(bi, pb_max, pb_max_int, p_0b, p_0b_int);
		//Calculez norma.
		n_a += (ai * ai);
		n_b += (bi * bi);
	}
	//Afisez tot ce imi cere.
	printf("%llu\n", ps);
	afis_max(a_max, b_max, p_0a, p_0b);
	//Aplic radical pentru a obtine norma.
	n_a = sqrt(n_a);
	n_b = sqrt(n_b);
	//Apoi afisez normele.
	printf("%.7F %.7F\n", n_a, n_b);
	return 0;
}
